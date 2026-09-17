# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Qué es este repositorio
Anuario personal del Grau en Enginyeria Informàtica (GEI, FIB-UPC): apuntes, exercicis i pràctiques versionats amb git, organitzats per curs/quadrimestre/assignatura. No és software de producció — és material acadèmic (veure README.md per l'estat i la metodologia de commits).

## Estructura de fitxers
```
1r/Q1/<ASSIGNATURA>/{ejercicios,material,teoria}
```
- **PRO1** — `ejercicios/{P_,X_}/<CODI>/<CODI>.cpp`. `P_` = problemes del Jutge.org, `X_` = exàmens/exercicis extra. Cada exercici viu en la seva pròpia carpeta anomenada pel codi del Jutge (p.ex. `P48107`), amb un únic `.cpp` del mateix nom.
  - Test local: `clang++ -Wall -Wextra -fsanitize=address,undefined -O0 P_.cpp -o solution && ./solution < in.txt > out.txt && diff out.txt exp.txt`
  - Compte: `P_/P89265/P89265` és un binari compilat que ja està trackejat per accident — no repetir el patró; el `.gitignore` arrel (`ex[0-9][0-9]`) no cobreix binaris sense extensió dins de `P_`/`X_`.
- **FM** — `ejercicios/<Tema>/ex<N>/ex<NN>.cpp` per bloc temàtic (Sumatoris, Lògica i Demostracions, ...), amb un `.md` de suport al nivell del tema (`sumatoris.md`, `logica.md`) amb enunciat/notació. `teoria/teoria.md` concentra la teoria per temes numerats, separada de la tècnica de resolució. `material/` té els PDFs oficials del curs (`FMPart1.pdf`, `FMPart2.pdf`, `EXAMFM.pdf`).
- **IC** — `ejercicios/` (pràctiques) i `material/` (PDFs, p.ex. `Practica0-IP-2023.pdf`).
- **F** — `teoria/teoria.md`, organitzada per temes numerats (Tema 1. Circuits, ...).
- **Admin/** — `horari.md` (horari setmanal del curs) i configuracions/scripts generals.

## Convencions de codi C++ (estil 42)
Tots els `.cpp` (PRO1 i FM) duen la capçalera ASCII estàndard de 42 (bloc amb nom de fitxer, autor, dates de creació/actualització) — replicar el mateix bloc en crear fitxers nous. Indentació amb tabs, tipus i nom de funció separats per tab (`void\tft_div(...)`), claus en línia pròpia. Iteració amb punters purs, mai índexs (regla global ja definida).

## Assignatures

### PRO1 — Programació 1 (C++, Jutge.org)
- Nivell d'entrada alt (ve de 42), pot avançar ràpid en fonaments.
- Prioritat: correctitud > enunciat > casos límit > complexitat raonable > simplicitat > compatibilitat amb el jutge > AC.
- Prohibit en exercicis plans: abstraccions, helpers innecessaris, hash tables, optimització prematura. Assenyalar explícitament si hi ha sobreenginyeria.

### IC — Introducció als Computadors
- SISA (assemblador), arquitectura, lògica digital.
- Avançar ràpid en fonaments ja dominats (baix nivell/sistemes).

### FM — Fonaments Matemàtics
- Professor: Rafel Farré. Temes: Sumatoris, Lògica i Demostracions, Inducció, Conjunts i Relacions, Funcions, Divisibilitat, Congruències.
- Parcial: 22/09/2026. Estructura estable (6 anys d'exàmens): 3 blocs — Demostracions, Inducció, Conjunts i Relacions. Lògica i Sumatoris són eines de suport, no blocs propis.
- Punt feble: inducció, conjunts, relacions.
- Seqüència: intuïció → procediment → formalisme → exemples → exercicis → examen. Analogies amb programació ajuden però mai substitueixen el rigor matemàtic.
- En transcriure exercicis del PDF oficial: mateixos números i enunciats exactes, sense alterar.
- Notació semi-formal amb símbols lògics, justificació pas a pas, estil dels apunts del curs.

### F — Física
- 4 blocs: Corrent Continu, Corrent Altern, Electrònica i portes lògiques, Ones.
- Abast del parcial del 22/09 sense confirmar encara.

## Archivos canario por asignatura

Cada carpeta de asignatura (`PRO1/`, `IC/`, `FM/`, `F/`, y cualquier futura) debe contener 3 archivos en su raíz:

- **CONTEXT.md** — temario, convenciones de estilo/código exigidas, reglas del juez (Jutge.org, ensamblador SISA, flags de compilación), fechas clave. Solo se edita si cambia el temario o las reglas oficiales.
- **STATE.md** — qué se ha dado en clase hasta hoy, ejercicios/listas resueltos vs pendientes, último tema tocado, próximo examen/entrega. Se actualiza cada sesión de trabajo.
- **PITFALLS.md** — tabla de errores recurrentes (fecha, ejercicio, error, corrección). Se actualiza cada sesión de trabajo.

### Comportamiento obligatorio

1. Al entrar a trabajar en cualquier carpeta de asignatura, leer los 3 archivos ANTES de tocar código o apuntes.
2. Si alguno no existe, crearlo con esta plantilla mínima antes de continuar:

  `CONTEXT.md`:
  ```
  # <Asignatura>
  ## Temario
  ## Convenciones (estilo, juez, flags de compilación)
  ## Fechas clave
  ```

  `STATE.md`:
  ```
  # Estado — <Asignatura>
  ## Última actualización: YYYY-MM-DD
  ## Cubierto
  ## Pendiente
  ## Próximo examen/entrega
  ```

  `PITFALLS.md`:
  ```
  # Errores recurrentes — <Asignatura>
  | Fecha | Ejercicio | Error | Corrección |
  |---|---|---|---|
  ```
3. Antes de dar por buena una solución en PRO1/IC (Jutge, SISA), auditar contra `PITFALLS.md`: si se detecta el mismo patrón de overengineering u otro error ya registrado, decirlo explícitamente antes de continuar.
4. Al cerrar la sesión de trabajo en una asignatura, actualizar `STATE.md` y, si hubo error nuevo, añadir fila a `PITFALLS.md`. Nunca tocar `CONTEXT.md` salvo cambio real confirmado de temario o reglas.
5. No inventar contenido de `CONTEXT.md` — si falta información (temario, reglas del juez), preguntar en vez de asumir.

La información ya recogida en las secciones "Assignatures" de este archivo (temario FM, convenciones PRO1, etc.) es la base a migrar a cada `CONTEXT.md` la primera vez que se cree; no la dupliques de nuevo en `CONTEXT.md` si ya está aquí sin verificar que sigue vigente.

## Workflow
- Classe: paper → digitalitzat després (Excalidraw). Deures: directe en digital.
- Bloc de màxima càrrega cognitiva 07:00–12:00 (FM/Física); resta del dia PRO1/IC/Jutge/SISA.
- Sense subcarpetes "clase" vs "casa" — només material ja digitalitzat va al repo.
- Commits: Conventional Commits amb scope pel codi d'exercici (`feat(P48107)`, `fix(...)`, `docs(...)`, `del(...)`, `refactor(...)`) — veure README.md per la taula completa.
- No afegir `Co-Authored-By: Claude...` als missatges de commit d'aquest repositori (encara que la instrucció d'atribució global ho demani per defecte).
- Després de cada commit, fer `git push` automàticament sense demanar confirmació prèvia.

## Estil de resposta
Español, directo, sin preámbulos. No repetir fundamentos ya dominados salvo laguna real. En C: punteros puros (`*p`, `p++`, `while(*p)`), nunca índices.
No usar la raya/guión largo (—) como muletilla o "marca de agua" estilística en texto generado (respuestas, commits, documentación de este repo) — solo cuando el propio usuario lo haya puesto explícitamente para marcar algo.
