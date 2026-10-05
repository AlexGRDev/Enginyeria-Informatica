# Simulador de parciales de PRO1 (Q1) — no oficial, herramienta personal.
# Ver README.md para que es esto y de donde salen los datos.

CACHE_DIR    := .cache
INTENTOS_DIR := intentos
EXAM_MINUTES ?= 90
ATTEMPT      ?=

.PHONY: all start fetch grade clean help

all: start

help:
	@echo "Simulador de parciales de PRO1 (no oficial)"
	@echo ""
	@echo "  make / make start  Descarga (si falta) la cache de parciales,"
	@echo "                     elige uno al azar, muestra sus enunciados,"
	@echo "                     crea un intento nuevo en $(INTENTOS_DIR)/ y"
	@echo "                     arranca el cronometro (EXAM_MINUTES=$(EXAM_MINUTES))."
	@echo "  make grade         Compila y ejecuta cada .cpp del ultimo intento"
	@echo "                     (o del indicado con ATTEMPT=<ruta>) y muestra"
	@echo "                     la solucion de referencia para comparar a ojo."
	@echo "                     NO es correccion automatica pass/fail."
	@echo "  make clean         Borra la cache descargada y los binarios"
	@echo "                     compilados. NO toca $(INTENTOS_DIR)/ (tu trabajo)."
	@echo "  make help          Esta ayuda."
	@echo ""
	@echo "Variables: EXAM_MINUTES (duracion del cronometro, por defecto 90),"
	@echo "           ATTEMPT (ruta del intento a corregir con 'make grade')."

fetch:
	@bash scripts/fetch_examenes.sh "$(CACHE_DIR)"

start: fetch
	@bash scripts/iniciar_examen.sh "$(CACHE_DIR)" "$(INTENTOS_DIR)" "$(EXAM_MINUTES)"

grade:
	@bash scripts/grade.sh "$(CACHE_DIR)" "$(INTENTOS_DIR)" "$(ATTEMPT)"

clean:
	rm -rf "$(CACHE_DIR)"
	find "$(INTENTOS_DIR)" -name '*.bin' -type f -delete 2>/dev/null || true
	@echo "Cache y binarios compilados eliminados. Los intentos (.cpp) se conservan."
