# IC — Introducció als Computadors

## Temario
Confirmado (nivel general, de CLAUDE.md): SISA (assemblador), arquitectura, lògica digital. Tecnologías del curso: Assembly, C.

Material de curso en `material/` (extraído de los propios PDFs, libro "Introducción a los Computadores" — Juan J. Navarro, Toni Juan, UPC):

- **Cap. 2 — Representación de números naturales** (14 págs.): sistema convencional en base *b*; decimal; binario (bit, vector de bits, valor `Xu = Σ xi·2^i`); rango de representación con *n* dígitos; conversión de base *b* a decimal y de decimal a base *b* (divisiones enteras sucesivas); binario ↔ hexadecimal (agrupación de 4 en 4 bits) y viceversa.
- **Cap. 3 — Circuitos lógicos combinacionales** (58 págs.): definición de circuito combinacional; puertas lógicas; conexión de combinacionales entre sí; análisis (tabla de verdad por columnas); síntesis de combinacionales (suma de minterms, propiedades de AND/OR, puertas de *n* entradas, síntesis con ROM); modelo temporal (tiempos de propagación de puertas y de circuitos combinacionales completos).

**Pendiente de confirmar:** temari oficial completo por bloques/semanas (más allá de los caps. 2 y 3 ya en el repo), profesor, y en qué punto del temario se introduce SISA (assemblador) — los PDFs actuales aún no lo cubren.

## Convenciones (estilo, juez, flags de compilación)
Estructura de carpetas: `ejercicios/` (prácticas) y `material/` (PDFs de teoría, p.ej. `Cap.2.RepresentacionNaturales-2014-07.pdf`, `Cap.3-Combinacionales-2010-09.pdf`). Primera práctica presente: `ejercicios/Practica0/Practica0-IP-2023.pdf`.

Entrega y corrección de prácticas: en **Atenea** (entrega y tests automáticos en la misma plataforma).

Convención de nombre de archivo de entrega: `practica#-subgrup#-nom_cognoms.pdf` (ej. `3-84-John_Smith.pdf`). Subgrupo de Alex: **51**.

**Pendiente de confirmar:**
- Herramienta/simulador SISA usado (nombre del ensamblador/simulador, flags de ensamblado y ejecución).
- Convención de nombres de archivo para código SISA/C de las prácticas (equivalente a `<CODI>.cpp` en PRO1). Nota: `Practica0-IP-2023.pdf` no lo especifica: es un laboratorio de LogicWorks/circuitos combinacionales (informe en papel), sin entregables de código; hay que confirmarlo con una práctica posterior que sí incluya código SISA/C.

## Fechas clave
Fuente: horari oficial a raco.fib.upc.edu (curs 2026-2027).

- Parcial 1: 30/10/2026 13:00-15:00.
- Parcial 2: 21/12/2026 11:00-13:00.
- Final: 12/01/2027 15:00-20:00.
- Recuperació: 06/02/2027 10:00-13:00.
