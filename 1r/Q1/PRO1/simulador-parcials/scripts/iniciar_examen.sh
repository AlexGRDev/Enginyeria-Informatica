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
  status     Tiempo restante, parcial actual y estado de cada problema.
  enunciado  Vuelve a mostrar los enunciados completos del parcial.
  grademe    Compila, ejecuta y compara con la solucion de referencia.
  finish     Termina la sesion (pide confirmacion) y muestra el resumen.

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

# --- creacion del intento: un .cpp con cabecera 42 por problema ---
problemas=("$pdir"/*/)
timestamp=$(date +%Y%m%d-%H%M%S)
intento_dir="$INTENTOS_DIR/${timestamp}-${pslug}"
mkdir -p "$intento_dir"
echo "$parcial" > "$intento_dir/.parcial"

for probdir in "${problemas[@]}"; do
	code=$(basename "$probdir")
	filename="${code}.cpp"
	dest="$intento_dir/$filename"
	fecha=$(date +"%Y/%m/%d %H:%M:%S")
	# Delimitador '#' en vez de '/': la fecha "YYYY/MM/DD HH:MM:SS" contiene
	# barras, y con '/' como delimitador el sed de BSD (macOS) rompe.
	sed -e "s#XXXXXXXXXX#${filename}#" -e "s#YYYY/MM/DD HH:MM:SS#${fecha}#g" \
		"$DIR/header_template.cpp" > "$dest"
	cat >> "$dest" <<'CPPEOF'

#include <iostream>

int	main(void)
{
	return (0);
}
CPPEOF
done

echo "=================================================================="
echo " Vas a empezar el parcial: $parcial"
echo " Modo REAL: tendras $EXAM_MINUTES minutos en cuanto pulses una tecla."
echo " Intento creado en: $intento_dir"
read -e -n1 -p "Pulsa una tecla para comenzar... " tecla
echo
echo

# --- arranque real del cronometro: a partir de aqui el tiempo cuenta ---
start_time=$(date +%s)
end_time=$((start_time + EXAM_MINUTES * 60))

cat > "$intento_dir/.estado" <<EOF2
PARCIAL="$parcial"
PARCIAL_SLUG="$pslug"
START_TIME=$start_time
END_TIME=$end_time
EXAM_MINUTES=$EXAM_MINUTES
EOF2

exec bash "$DIR/sesion_examen.sh" "$CACHE_DIR" "$INTENTOS_DIR" "$intento_dir"
