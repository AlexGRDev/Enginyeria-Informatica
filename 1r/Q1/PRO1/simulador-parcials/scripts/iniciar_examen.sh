#!/usr/bin/env bash
# Elige un parcial al azar de los que hay en cache, muestra los enunciados de
# todos sus problemas de golpe (como el examen real), crea una carpeta de
# intento con un .cpp vacio por problema (cabecera 42 incluida) y arranca un
# cronometro visible en terminal.
set -euo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$DIR/common.sh"

CACHE_DIR="${1:-.cache}"
INTENTOS_DIR="${2:-intentos}"
EXAM_MINUTES="${3:-90}"

# Solo se puede elegir entre los parciales que ya tengan cache poblada.
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

echo "=================================================================="
echo " PARCIAL SELECCIONADO: $parcial"
echo "=================================================================="
echo

problemas=("$pdir"/*/)
for probdir in "${problemas[@]}"; do
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

# Crea la carpeta de intento con un .cpp vacio por problema.
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
	cat >> "$dest" <<'EOF'

#include <iostream>

int	main(void)
{
	return (0);
}
EOF
done

echo "=================================================================="
echo " Intento creado en: $intento_dir"
echo " Tienes $EXAM_MINUTES minutos. Cronometro en marcha."
echo " Cuando acabes (o se acabe el tiempo): Ctrl+C y luego 'make grade'."
echo "=================================================================="
echo

total_seg=$((EXAM_MINUTES * 60))
inicio=$(date +%s)
while :; do
	ahora=$(date +%s)
	transcurrido=$((ahora - inicio))
	restante=$((total_seg - transcurrido))
	if [ "$restante" -le 0 ]; then
		printf "\r¡TIEMPO AGOTADO!                                   \n"
		break
	fi
	printf "\rTiempo restante: %02d:%02d   " $((restante / 60)) $((restante % 60))
	sleep 1
done
