# FM — Fonaments Matemàtics

## Temario
Profesor: Rafel Farré. Temas: Sumatoris, Lògica i Demostracions, Inducció, Conjunts i Relacions, Funcions, Divisibilitat, Congruències.

Estructura estable del examen parcial (6 años de exámenes): 3 bloques — Demostracions, Inducció, Conjunts i Relacions. Lògica y Sumatoris son herramientas de apoyo, no bloques propios del examen.

## Convenciones (estilo, juez, flags de compilación)
- Estructura: `ejercicios/<Tema>/ex<N>/ex<NN>.cpp` por bloque temático, con un `.md` de apoyo al nivel del tema (`sumatoris.md`, `logica.md`) con enunciado/notación. `teoria/teoria.md` concentra la teoría por temas numerados, separada de la técnica de resolución. `material/` tiene los PDFs oficiales del curso (`FMPart1.pdf`, `FMPart2.pdf`, `EXAMFM.pdf`).
- Al transcribir ejercicios del PDF oficial: mismos números y enunciados exactos, sin alterar.
- Notación semi-formal con símbolos lógicos, justificación paso a paso, estilo de los apuntes del curso.
- Secuencia pedagógica: intuición → procedimiento → formalismo → ejemplos → ejercicios → examen. Las analogías con programación ayudan pero nunca sustituyen el rigor matemático.
- Los `.cpp` de FM (cuando se usan como apoyo, p.ej. Sumatoris) llevan la misma cabecera ASCII de 42 que PRO1, con iteración por punteros puros.
- Punto débil identificado: inducción, conjuntos, relaciones — reforzar especialmente estos bloques.
- Notación de fórmulas lógicas: LaTeX inline `$...$` (comandos \wedge, \vee, \neg, \to, \leftrightarrow, \forall, \exists, \equiv...) en vez de unicode entre backticks — convención adoptada el 2026-09-17 tras instalar `render-latex.nvim` en Neovim. Las tablas de valores de verdad (0/1) y el bloque de demostración con ```código``` quedan igual, sin LaTeX.

## Fechas clave
- Parcial: 22/09/2026.
