---
project: enginyeria-informatica
type: context
tags: [academico, gei]
aliases: ["Enginyeria contexto"]
---

# Enginyeria Informàtica: GEI, FIB-UPC

**Ruta:** `~/Documents/Enginyeria-Informatica`
**Curso:** 2026-2027, 1r curs, Q1
**Objetivo:** media > 8, orientación a Enginyeria de Computadors

## Asignaturas (Q1)

| Código | Asignatura | Ruta |
|---|---|---|
| FM | Fonaments Matemàtics | `1r/Q1/FM` |
| IC | Introducció a la Computació | `1r/Q1/IC` |
| PRO1 | Programació 1 | `1r/Q1/PRO1` |
| F | Física | `1r/Q1/F` |

Horario semanal en `Admin/horari.md`.

## Organización del repo

- Una **rama por asignatura** (`FM`, `Fisica`, `IC`, `PRO1`) sobre `main`, con
  worktrees en `.claude/worktrees/`. Remoto en `origin`.
- Cada asignatura lleva su trío de canarios en su carpeta: `CONTEXT.md` (qué es y
  cómo se trabaja), `PITFALLS.md` (errores en los que ya se ha caído), `STATE.md`
  (dónde se quedó la cosa).
- Material y enunciados en `material/`, teoría en `teoria/`, resoluciones en
  `ejercicios/`.
- Subagente de proyecto `branch-worker` en `.claude/agents/`: trabaja dentro de un
  worktree, solo toca `.md`, sin Bash ni git.

Criterio académico: ver CLAUDE.md global.

## Notas de este proyecto

- [[projects/enginyeria-informatica/STATE]]
- [[projects/enginyeria-informatica/PITFALLS]]
