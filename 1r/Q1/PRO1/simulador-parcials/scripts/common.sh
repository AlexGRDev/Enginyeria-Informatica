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
