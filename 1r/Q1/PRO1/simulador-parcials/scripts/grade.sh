#!/usr/bin/env bash
# Ayuda a la autocorreccion de un intento: compila cada .cpp del usuario con
# los mismos flags que el resto del repo, lo ejecuta de forma interactiva
# (el usuario introduce su propia entrada, no hay casos de test oficiales) y
# muestra justo despues la solucion de referencia para comparar a ojo.
#
# ESTO NO ES UN CORRECTOR AUTOMATICO: no hay pass/fail, solo ayuda visual.
set -uo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$DIR/common.sh"

CACHE_DIR="${1:-.cache}"
INTENTOS_DIR="${2:-intentos}"
ATTEMPT="${3:-}"

if [ -z "$ATTEMPT" ]; then
	ATTEMPT=$(ls -1dt "$INTENTOS_DIR"/*/ 2>/dev/null | head -1)
fi

if [ -z "$ATTEMPT" ] || [ ! -d "$ATTEMPT" ]; then
	echo "No se encontro ningun intento en '$INTENTOS_DIR'. Ejecuta 'make' primero." >&2
	exit 1
fi

ATTEMPT="${ATTEMPT%/}"
base=$(basename "$ATTEMPT")
parcial_slug=$(echo "$base" | sed -E 's/^[0-9]{8}-[0-9]{6}-//')

echo "=================================================================="
echo " AUTOCORRECCION del intento: $base"
echo " Parcial: $parcial_slug"
echo
echo " AVISO: esto NO es un corrector automatico (pass/fail). No hay"
echo " casos de test oficiales para estos exámenes. Introduce tu propia"
echo " entrada de prueba y compara la salida con la solucion de"
echo " referencia a ojo."
echo "=================================================================="

shopt -s nullglob
cpps=("$ATTEMPT"/*.cpp)
shopt -u nullglob

if [ ${#cpps[@]} -eq 0 ]; then
	echo "No hay ningun .cpp en $ATTEMPT." >&2
	exit 1
fi

for cpp in "${cpps[@]}"; do
	code=$(basename "$cpp" .cpp)
	probdir="$CACHE_DIR/$parcial_slug/$code"
	bin="$ATTEMPT/${code}.bin"

	echo
	echo "------------------------------------------------------------------"
	echo " Problema $code"
	echo "------------------------------------------------------------------"

	if ! clang++ -Wall -Wextra -fsanitize=address,undefined -O0 "$cpp" -o "$bin"; then
		echo "[grade] ERROR DE COMPILACION en $code, se omite la ejecucion." >&2
		continue
	fi

	echo "--- Tu programa (introduce la entrada de prueba; Ctrl+D para EOF) ---"
	"$bin"

	echo
	echo "--- Solucion de referencia ($code) ---"
	if [ -s "$probdir/solucion_referencia.cc" ]; then
		cat "$probdir/solucion_referencia.cc"
	else
		echo "(no se encontro solucion de referencia en cache para $code)"
	fi
	echo "--- Fin de $code: compara las dos salidas a ojo ---"
done
