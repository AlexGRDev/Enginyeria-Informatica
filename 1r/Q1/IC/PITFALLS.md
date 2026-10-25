# Errores recurrentes — IC

<!-- kiwi-gei:pitfalls:inici -->
## Contador de errores (Kiwi GEI)

Generado el 2026-10-25. Ordenado por número de veces: arriba, lo que más hay que reforzar.

| Patrón | Tema | Veces | Última vez | Cómo reforzar |
|---|---|---|---|---|
| Pesos de bit mal asignados (empieza en 2 en vez de 1 o orden invertido) | Representación de números naturales (base b, binario, hexadecimal, conversiones) | 2 | 2026-10-25 | Restar pesos 256, 128, 64, ... desde el mayor que cabe y comprobar sumando. |
| No sabe abordar cronogramas con glitch | Modelo temporal (tiempos de propagación, caminos críticos) | 1 | 2026-10-25 | Propagar cada cambio con el Tp de la puerta y evaluar la salida en cada intervalo. |
| No sabe abordar caminos críticos con bloques | Modelo temporal (tiempos de propagación, caminos críticos) | 1 | 2026-10-25 | Enumerar todos los caminos, incluidos los internos del bloque por par entrada-salida. |
| No sabe abordar caminos críticos y tiempos de propagación | Modelo temporal (tiempos de propagación, caminos críticos) | 1 | 2026-10-25 | Sumar los Tp de las puertas de cada camino entrada-salida y quedarse con el máximo. |
| No sabe abordar el contenido de una ROM | Síntesis de combinacionales (suma de minterms, ROM) | 1 | 2026-10-25 | Dirección = 4·Yu + Xu; recorrer los valores de Yu y marcar los Xu < Yu. |
| No sabe abordar la suma de minterms | Síntesis de combinacionales (suma de minterms, ROM) | 1 | 2026-10-25 | Un minterm por cada fila con salida 1, y contar puertas a partir de ellos. |
| No sabe abordar el análisis de combinacionales por tabla de verdad | Puertas lógicas y análisis de combinacionales (tabla de verdad) | 1 | 2026-10-25 | Evaluar columna a columna x, s, a·b, x·c, co. |
| Tabla de verdad incompleta o sin columnas intermedias | Puertas lógicas y análisis de combinacionales (tabla de verdad) | 1 | 2026-10-25 | Escribir las 8 filas en orden binario y una columna por señal intermedia. |
| No sabe abordar el número mínimo de bits para un rango | Representación de números naturales (base b, binario, hexadecimal, conversiones) | 1 | 2026-10-25 | Buscar el menor n con 2^n > máximo; los dígitos hexadecimales son ceil(n/4). |
| No sabe abordar el rango de representación en base b | Representación de números naturales (base b, binario, hexadecimal, conversiones) | 1 | 2026-10-25 | Con n dígitos en base b el rango es [0, b^n - 1]. |
| No agrupa de 4 en 4 bits al pasar binario a hexadecimal | Representación de números naturales (base b, binario, hexadecimal, conversiones) | 1 | 2026-10-25 | Separar en nibbles desde la derecha y convertir cada uno (1010=A, 1101=D). |
<!-- kiwi-gei:pitfalls:fi -->

| Fecha | Ejercicio | Error | Corrección |
|---|---|---|---|
| 2026-10-08 | PRAC3 | `LibPrac3-07-08-Q1.clf` apareció truncado de 67 KB a 18 bytes (contenido `(F1(y0000000E)(t))`) en el checkout raíz; causa probable: guardado desde LogicWorks sobre la librería de partida (no confirmada) | Restaurado con `git restore`. No guardar sobre las librerías `.clf` de partida; antes de commitear en IC, revisar `git diff --stat` de los `.clf`/`.cct`. |
