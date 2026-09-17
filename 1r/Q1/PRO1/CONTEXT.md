# PRO1 — Programació 1

## Temario
Pendiente de confirmar: no se dispone del temari oficial de l'assignatura (no hay PDF/enunciado de programa en `material/`). Los temas cubiertos hasta ahora se derivan de los ejercicios resueltos (ver STATE.md): tipos básicos, punteros y aritmética de punteros, cadenas de estilo C (`char*`), funciones auxiliares, recursividad, `std::string`, E/S con `std::cin`/`std::cout`.

## Convenciones (estilo, juez, flags de compilación)
- Estructura: `ejercicios/{P_,X_}/<CODI>/<CODI>.cpp`. `P_` = problemas de Jutge.org, `X_` = exámenes/ejercicios extra. Una carpeta por ejercicio, nombrada por el código del Jutge (p.ej. `P48107`), con un único `.cpp` del mismo nombre.
- Estilo de código: cabecera ASCII estándar de 42 en cada `.cpp` (bloque con nombre de archivo, autor, fechas de creación/actualización). Indentación con tabs, tipo y nombre de función separados por tab (`void\tft_div(...)`), llaves en línea propia.
- Iteración con punteros puros (`*p`, `p++`, `while(*p)`), nunca índices (`str[i]`, `i++`).
- Prioridad de diseño en ejercicios planos: correctitud > enunciado > casos límite > complejidad razonable > simplicidad > compatibilidad con el juez > AC.
- Prohibido en ejercicios planos: abstracciones, helpers innecesarios, hash tables, optimización prematura. Señalar explícitamente si hay sobreingeniería.
- Test local:
  ```bash
  clang++ -Wall -Wextra -fsanitize=address,undefined -O0 <CODI>.cpp -o solution
  ./solution < in.txt > out.txt
  diff out.txt exp.txt
  ```
- Cuidado: `P_/P89265/P89265` es un binario compilado ya trackeado por accidente — no repetir el patrón; el `.gitignore` raíz (`ex[0-9][0-9]`) no cubre binarios sin extensión dentro de `P_`/`X_`.
- Commits: Conventional Commits con scope el código del ejercicio (`feat(P48107)`, `fix(...)`, `docs(...)`, `del(...)`, `refactor(...)`). Sin `Co-Authored-By: Claude...` en este repo.

## Fechas clave
Fuente: horari oficial a raco.fib.upc.edu (curs 2026-2027).

- Parcial: 29/10/2026 — Torn 1 15:30-17:30, Torn 2 18:00-20:00 (aules laboratori).
- Final: 08/01/2027 — Torn 1 08:00-11:00, Torn 2 11:30-14:30 (aules laboratori).
- Recuperació: 06/02/2027 10:00-13:00 (Grup 10 i Grup 20, aules laboratori).
