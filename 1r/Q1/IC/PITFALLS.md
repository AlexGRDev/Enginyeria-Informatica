# Errores recurrentes — IC

| Fecha | Ejercicio | Error | Corrección |
|---|---|---|---|
| 2026-10-08 | PRAC3 | `LibPrac3-07-08-Q1.clf` apareció truncado de 67 KB a 18 bytes (contenido `(F1(y0000000E)(t))`) en el checkout raíz; causa probable: guardado desde LogicWorks sobre la librería de partida (no confirmada) | Restaurado con `git restore`. No guardar sobre las librerías `.clf` de partida; antes de commitear en IC, revisar `git diff --stat` de los `.clf`/`.cct`. |
