#!/usr/bin/env bash
# Arranca una sesion de examen en modo REAL: disclaimer, confirmacion,
# animacion de "conexion", seleccion de parcial al azar, creacion del
# intento (.cpp con cabecera 42 por problema) y entrada en el bucle
# interactivo de comandos (examshell>). El bucle en si vive en
# scripts/sesion_examen.sh.
set -uo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$DIR/common.sh"

CACHE_DIR="${1:-.cache}"
INTENTOS_DIR="${2:-intentos}"
EXAM_MINUTES="${3:-90}"

cat <<'EOF'
==================================================================
 SIMULADOR DE PARCIALES DE PRO1 -- MODO REAL (no oficial)
==================================================================

Herramienta personal, NO oficial de la FIB/UPC, inspirada en el modo
"real" de Maestro42: en cuanto confirmes, el tiempo empieza a contar
de verdad y entraras en una sesion interactiva (examshell>) con estos
comandos disponibles durante el examen:

  help       Lista de comandos.
  status     Tiempo restante, problema actual y estado de lo desbloqueado.
  enunciado  Vuelve a mostrar el enunciado del problema actual (solo ese).
  siguiente  Pasa al siguiente problema (alias: next). PIDE CONFIRMACION Y
             NO SE PUEDE VOLVER ATRAS: hasta entonces no ves los demas.
  grademe    Compila, ejecuta y compara con la solucion de referencia.
  finish     Termina la sesion (pide confirmacion) y muestra el resumen.

Los problemas del parcial se van viendo UNO A UNO, como en Maestro42: no
se te ensenan todos de golpe, y una vez avanzas con 'siguiente' no hay
vuelta atras al problema anterior.

No hay pass/fail automatico (PRO1 no tiene jutge con casos de test
para estos examenes): 'grademe' solo ayuda a la autocorreccion manual.
==================================================================
EOF
echo
read -e -p "¿Empezar un parcial aleatorio en modo REAL ahora? (y/n) " confirm
case "$confirm" in
	y|Y|yes|YES) ;;
	*)
		echo "Cancelado."
		exit 0
		;;
esac

# --- seleccion de parcial: solo entre los que ya tengan cache poblada ---
disponibles=()
for parcial in "${PARCIALES[@]}"; do
	pslug=$(slug "$parcial")
	if [ -d "$CACHE_DIR/$pslug" ] && [ -n "$(ls -A "$CACHE_DIR/$pslug" 2>/dev/null)" ]; then
		disponibles+=("$parcial")
	fi
done

if [ ${#disponibles[@]} -eq 0 ]; then
	echo "No hay ningun parcial en cache. Ejecuta 'make fetch' (o 'make') primero." >&2
	exit 1
fi

idx=$((RANDOM % ${#disponibles[@]}))
parcial="${disponibles[$idx]}"
pslug=$(slug "$parcial")
pdir="$CACHE_DIR/$pslug"

# --- animacion de "conexion" (puramente estetica, no afecta al cronometro) ---
echo
type_out() {
	local text="$1" c
	while IFS= read -r -n1 c; do
		printf '%s' "$c"
		sleep 0.01
	done <<< "$text"
	echo
}
type_out "Conectando con examshell..."
sleep 0.2
type_out "Autenticando a agarcia2@pro1-simulador..."
sleep 0.2
type_out "Sesion establecida."
echo

# --- creacion del intento: solo el .cpp del PRIMER problema por ahora ---
# Los problemas se ven de uno en uno (como Maestro42): el resto de .cpp se
# va creando mas adelante, en sesion_examen.sh, al usar 'siguiente'.
problemas=("$pdir"/*/)
timestamp=$(date +%Y%m%d-%H%M%S)
intento_dir="$INTENTOS_DIR/${timestamp}-${pslug}"
mkdir -p "$intento_dir"
echo "$parcial" > "$intento_dir/.parcial"

PROBLEMS=""
for probdir in "${problemas[@]}"; do
	code=$(basename "$probdir")
	PROBLEMS="$PROBLEMS $code"
done
PROBLEMS="${PROBLEMS# }"
read -ra PROBLEMS_ARR <<< "$PROBLEMS"
CURRENT_IDX=0

crear_cpp_problema "${PROBLEMS_ARR[0]}" "$intento_dir"

echo "=================================================================="
echo " Vas a empezar el parcial: $parcial"
echo " Modo REAL: tendras $EXAM_MINUTES minutos en cuanto pulses una tecla."
echo " Tiene ${#PROBLEMS_ARR[@]} problema(s). Se veran UNO A UNO: hasta que"
echo " no escribas 'siguiente' (confirmando, y SIN posibilidad de volver"
echo " atras) no veras el siguiente problema."
echo " Intento creado en: $intento_dir"
read -e -n1 -p "Pulsa una tecla para comenzar... " tecla
echo
echo

# --- arranque real del cronometro: a partir de aqui el tiempo cuenta ---
PARCIAL="$parcial"
PARCIAL_SLUG="$pslug"
START_TIME=$(date +%s)
END_TIME=$((START_TIME + EXAM_MINUTES * 60))

guardar_estado "$intento_dir/.estado"

exec bash "$DIR/sesion_examen.sh" "$CACHE_DIR" "$INTENTOS_DIR" "$intento_dir"
