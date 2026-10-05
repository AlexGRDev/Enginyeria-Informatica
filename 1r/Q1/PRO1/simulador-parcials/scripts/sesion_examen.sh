#!/usr/bin/env bash
# Bucle interactivo de la sesion de examen en modo REAL (prompt
# "examshell>"), persistente mientras quede tiempo. Se invoca desde
# iniciar_examen.sh justo despues de arrancar el cronometro real (lee
# el estado de <intento_dir>/.estado). Tambien se puede reanudar a mano
# sobre un intento ya empezado:
#   bash scripts/sesion_examen.sh <CACHE_DIR> <INTENTOS_DIR> <intento_dir>
set -uo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$DIR/common.sh"

CACHE_DIR="${1:-.cache}"
INTENTOS_DIR="${2:-intentos}"
INTENTO_DIR="${3:?falta la ruta del intento}"

ESTADO="$INTENTO_DIR/.estado"
if [ ! -f "$ESTADO" ]; then
	echo "No hay sesion activa en $INTENTO_DIR (falta .estado)." >&2
	exit 1
fi
source "$ESTADO"

PDIR="$CACHE_DIR/$PARCIAL_SLUG"

tiempo_restante() {
	local ahora restante
	ahora=$(date +%s)
	restante=$((END_TIME - ahora))
	[ "$restante" -lt 0 ] && restante=0
	echo "$restante"
}

tiempo_agotado() {
	local ahora
	ahora=$(date +%s)
	[ "$ahora" -ge "$END_TIME" ]
}

fmt_mmss() {
	printf "%02d:%02d" $(($1 / 60)) $(($1 % 60))
}

mostrar_enunciados() {
	for probdir in "$PDIR"/*/; do
		code=$(basename "$probdir")
		echo "------------------------------------------------------------------"
		echo " Problema $code"
		echo "------------------------------------------------------------------"
		if [ -s "$probdir/enunciado.txt" ]; then
			cat "$probdir/enunciado.txt"
		else
			echo "(Este fichero fuente no trae un enunciado capturable como"
			echo " comentario inicial; revisa el .cc original en el repo de"
			echo " referencia si necesitas el enunciado completo.)"
		fi
		echo
	done
}

estado_compilacion() {
	# Compila en silencio cada .cpp del intento y muestra OK/ERROR.
	shopt -s nullglob
	local cpps=("$INTENTO_DIR"/*.cpp) cpp code
	shopt -u nullglob
	for cpp in "${cpps[@]}"; do
		code=$(basename "$cpp" .cpp)
		if clang++ -Wall -Wextra -fsanitize=address,undefined -O0 "$cpp" -o "$INTENTO_DIR/${code}.bin" 2>/dev/null; then
			echo "  $code : compila OK"
		else
			echo "  $code : ERROR DE COMPILACION"
		fi
	done
}

mostrar_help() {
	cat <<'EOF'
Comandos disponibles:
  help       Esta ayuda.
  status     Tiempo restante, parcial actual y estado de cada problema.
  enunciado  Vuelve a mostrar los enunciados completos del parcial (alias: subject).
  grademe    Compila, ejecuta (interactivo) y compara cada .cpp con la
             solucion de referencia. NO es correccion automatica pass/fail.
  finish     Termina la sesion (pide confirmacion 'yes') y muestra el resumen.
EOF
}

mostrar_status() {
	local restante
	restante=$(tiempo_restante)
	echo "Parcial: $PARCIAL"
	echo "Tiempo restante: $(fmt_mmss "$restante") de $EXAM_MINUTES min"
	echo "Enunciados en: $PDIR/*/enunciado.txt"
	echo "Tus .cpp en:    $INTENTO_DIR/"
	echo "Estado de los problemas:"
	estado_compilacion
}

resumen_final() {
	local ahora usado tope
	ahora=$(date +%s)
	usado=$((ahora - START_TIME))
	tope=$((EXAM_MINUTES * 60))
	[ "$usado" -gt "$tope" ] && usado=$tope
	echo "=================================================================="
	echo " RESUMEN FINAL"
	echo "=================================================================="
	echo " Parcial: $PARCIAL"
	echo " Tiempo usado: $(fmt_mmss "$usado") de $EXAM_MINUTES min"
	echo " Estado final de los problemas:"
	estado_compilacion
	echo "=================================================================="
}

# finish <manual|timeup|eof>: cierra la sesion. En modo "manual" pide
# confirmacion explicita; en "timeup"/"eof" cierra directamente (no hay
# nadie a quien pedirle confirmacion: se acabo el tiempo o se corto la
# entrada). Limpia los binarios temporales de 'grademe'/'status' pero
# nunca los .cpp del usuario.
finish() {
	local modo="${1:-manual}"
	case "$modo" in
		manual)
			read -e -p "Escribe 'yes' para confirmar que quieres terminar: " conf
			if [ "$conf" != "yes" ]; then
				echo "Cancelado, sigues en la sesion."
				return 1
			fi
			;;
		timeup)
			echo
			echo "¡¡SE ACABO EL TIEMPO!! Cerrando la sesion automaticamente."
			;;
		eof)
			echo
			echo "Sesion interrumpida (EOF o señal de salida). Cerrando."
			;;
	esac
	resumen_final
	rm -f "$INTENTO_DIR"/*.bin 2>/dev/null
	exit 0
}

trap 'finish eof' INT TERM

echo "=================================================================="
echo " Parcial: $PARCIAL -- tienes $EXAM_MINUTES minutos. examshell>"
echo " Escribe 'help' para ver los comandos disponibles."
echo "=================================================================="
mostrar_enunciados

while true; do
	if tiempo_agotado; then
		finish timeup
	fi

	if ! read -e -p "examshell> " cmd; then
		finish eof
	fi

	if tiempo_agotado; then
		finish timeup
	fi

	case "$cmd" in
		help) mostrar_help ;;
		status) mostrar_status ;;
		enunciado | subject) mostrar_enunciados ;;
		grademe) bash "$DIR/grade.sh" "$CACHE_DIR" "$INTENTOS_DIR" "$INTENTO_DIR" ;;
		finish) finish manual || true ;;
		"") ;;
		*) echo "Comando desconocido, usa 'help' para ver los comandos disponibles." ;;
	esac
done
