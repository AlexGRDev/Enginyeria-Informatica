# Pitfalls: Enginyeria Informàtica

Cada asignatura tiene su `PITFALLS.md` en su carpeta del repo
(`1r/Q1/<asignatura>/PITFALLS.md`). Esta nota recoge solo lo transversal.

## Editar `.claude/agents/` en `main` no llega a los worktrees

Fecha: 2026-09-21.

`.claude/agents/*.md` está trackeado en git, así que **cada worktree tiene su
propia copia**. Una edición en el checkout de `main` no la ve una sesión
lanzada desde `.claude/worktrees/<rama>`: esa sigue leyendo su versión vieja.
Para que surta efecto hacen falta commit en `main` y fast-forward a las cuatro
ramas, igual que con el `CLAUDE.md`.

El script del hook es el caso contrario: **se aplica al momento**, porque el
frontmatter lo referencia por ruta absoluta
(`/Users/alexg/Documents/Enginyeria-Informatica/.claude/hooks/branch-worker-guard.sh`),
así que los cinco checkouts ejecutan el mismo fichero aunque cada uno tenga su
copia versionada. Consecuencia práctica: al depurar el guard, editar la copia
del checkout principal; editar la de un worktree no cambia nada.

Cómo se detectó: un test del hook no disparaba desde el worktree de PRO1
mientras sí lo hacía desde la raíz del repo.

## Frontmatter YAML inválido en `.claude/agents/` = agente fuera del roster

Fecha: 2026-09-21.

Frontmatter YAML inválido en `.claude/agents/` = el agente desaparece del roster
sin error. Descriptions con `:` van en escalar de bloque (`>-`). Tras editar
agentes, comprobar roster en sesión nueva.

## Pushes casi simultáneos a dos ramas: carrera en el merge automático

Fecha: 2026-09-21.

`.github/workflows/auto-merge.yml` crea y mergea la PR de una rama hacia `main`
en cada push. Si se hace push casi a la vez a dos ramas de asignatura distintas
(pasó con `FM` y `Fisica`), ambas crean su PR y ambas intentan mergear casi al
mismo tiempo. La primera en mergear mueve `main`; cuando la segunda ejecución
intenta mergear justo después, GitHub responde "GraphQL: Base branch was
modified. Review and try the merge again." y el job fallaba sin reintentar.
Como el job solo actuaba cuando *no* existía ya una PR abierta para esa rama,
una vez creada la PR y fallado el merge por la carrera, quedaba huérfana para
siempre: nada la volvía a intentar mergear.

Corrección: el job ahora reintenta el merge hasta 5 veces con backoff
(`sleep 5s`) para absorber la ventana de carrera, y actúa también cuando la PR
ya existe, no solo al crearla — así una PR huérfana por esta carrera se
resuelve sola en el siguiente push a la rama que la originó.

Cómo se detectó: la PR #12 de `FM` quedó abierta ~40 minutos sin mergear tras
un push casi simultáneo con `Fisica`, mientras la de `Fisica` sí se mergeó sin
problema.

← [CONTEXT.md](CONTEXT.md)
