#!/usr/bin/env bash
# Config compartida del simulador de parciales de PRO1 (Q1).
# No ejecutable por si solo: se hace `source` desde los otros scripts.

REPO_OWNER="smyha"
REPO_NAME="smyha-FIB-UPC_PRO1"
API_BASE="https://api.github.com/repos/${REPO_OWNER}/${REPO_NAME}/contents/Examens"

# Las 7 carpetas de parciales de Q1 del repo fuente (verificadas a mano, 2026-10-05).
PARCIALES=(
	"19-20Q1 Control 2 Torn 1"
	"20-21 Q1 C1 T1"
	"20-21 Q1 C2 T1"
	"20-21 Q1 C3 T1"
	"21-22 Q1 C1 T1"
	"21-22 Q1 C2 T1"
	"21-22 Q1 C3 T1"
)

# Convierte "20-21 Q1 C1 T1" -> "20-21_Q1_C1_T1" (nombre seguro de directorio).
slug() {
	echo "$1" | tr ' ' '_'
}

# Crea el .cpp (cabecera 42 + stub) de un problema dentro del intento.
# Usa $DIR (directorio de scripts/, ya fijado por el script que hace source
# de este fichero) para localizar header_template.cpp.
crear_cpp_problema() {
	local code="$1" intento_dir="$2"
	local filename="${code}.cpp"
	local dest="$intento_dir/$filename"
	local fecha
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
}

# Reescribe por completo el fichero .estado desde las variables en memoria
# actuales. Deliberadamente NO usa sed -i para tocar solo CURRENT_IDX: ya
# hubo un bug real por diferencias BSD/GNU sed con delimitadores
# conflictivos, así que se regenera entero.
guardar_estado() {
	local estado_path="$1"
	cat > "$estado_path" <<EOF2
PARCIAL="$PARCIAL"
PARCIAL_SLUG="$PARCIAL_SLUG"
START_TIME=$START_TIME
END_TIME=$END_TIME
EXAM_MINUTES=$EXAM_MINUTES
PROBLEMS="$PROBLEMS"
CURRENT_IDX=$CURRENT_IDX
EOF2
}
