#!/usr/bin/env bash
# Descarga los 7 parciales de Q1 desde el repo fuente (smyha/smyha-FIB-UPC_PRO1)
# y los guarda en la cache local, separando enunciado y solucion de referencia
# de cada .cc. NO se vendoriza nada al repo: todo esto vive solo en .cache/
# (excluido de git).
set -euo pipefail

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
source "$DIR/common.sh"

CACHE_DIR="${1:-.cache}"

for parcial in "${PARCIALES[@]}"; do
	pslug=$(slug "$parcial")
	pdir="$CACHE_DIR/$pslug"

	if [ -d "$pdir" ] && [ -n "$(ls -A "$pdir" 2>/dev/null)" ]; then
		echo "[fetch] $parcial ya esta en cache, se omite."
		continue
	fi

	echo "[fetch] Descargando: $parcial ..."
	mkdir -p "$pdir"

	encoded=$(python3 -c "import urllib.parse,sys; print(urllib.parse.quote(sys.argv[1]))" "$parcial")
	listing=$(curl -sf -H "User-Agent: simulador-parcials-pro1" "$API_BASE/$encoded")

	echo "$listing" | jq -c '.[]' | while read -r item; do
		name=$(echo "$item" | jq -r '.name')
		url=$(echo "$item" | jq -r '.download_url')

		code=$(echo "$name" | grep -oE '^X[0-9]+' || true)
		if [ -z "$code" ]; then
			echo "[fetch] AVISO: no se pudo extraer el codigo del fichero '$name', se omite." >&2
			continue
		fi

		probdir="$pdir/$code"
		mkdir -p "$probdir"
		raw="$probdir/.raw.cc"
		curl -sf -H "User-Agent: simulador-parcials-pro1" "$url" -o "$raw"

		enun="$probdir/enunciado.txt"
		sol="$probdir/solucion_referencia.cc"
		: > "$enun"
		: > "$sol"

		# Separa el bloque de comentarios "//" inicial (enunciado) del resto
		# (solucion de referencia). Algunos ficheros fuente no tienen un
		# enunciado real, solo un comentario de titulo, o directamente ningun
		# comentario inicial: en ese caso enunciado.txt queda vacio o muy
		# corto, no es un bug del parser, es asi en los datos de origen.
		awk -v enun="$enun" -v sol="$sol" '
			BEGIN { header = 1 }
			{
				if (header && ($0 == "" || $0 ~ /^[ \t]*\/\//)) {
					print > enun
				} else {
					header = 0
					print > sol
				}
			}
		' "$raw"

		echo "$name" > "$probdir/nombre_original.txt"
		rm -f "$raw"
	done
done

echo "[fetch] Cache lista en $CACHE_DIR"
