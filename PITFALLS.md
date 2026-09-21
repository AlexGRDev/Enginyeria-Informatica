---
project: enginyeria-informatica
type: pitfalls
tags: [academico, gei, pitfalls]
aliases: ["Enginyeria pitfalls"]
---

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

← [[projects/enginyeria-informatica/CONTEXT]]
