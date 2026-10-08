# Estado: Enginyeria Informàtica

## Última actualización: 2026-10-08

Para el avance por asignatura, ver el `STATE.md` de cada una en su carpeta del
repo. Fuente de verdad, no se duplica aquí.

## Gobernanza del repo
`CLAUDE.md` deduplicado contra el global: fuera la prioridad académica de PRO1,
la sección de ediciones quirúrgicas y el estilo de respuesta, sustituidas por
referencias. De 190 a 181 líneas.

Commit `aa62068` en `main`, propagado por fast-forward a `Fisica`, `FM`, `IC` y
`PRO1`, y empujado a `origin`. Los cinco checkouts comparten blob.

Los worktrees `agent-*` siguen con la versión antigua: son efímeros, se limpian
con `git worktree remove` cuando sobren.

## CI: auto-merge
Corregida hoy en `main` una condición de carrera en `.github/workflows/auto-merge.yml`
que dejaba huérfana la PR automática de una rama cuando dos ramas hacían push
casi a la vez (pasó con `FM` y `Fisica`, PR #12 atascada ~40 min). Detalle en
`PITFALLS.md`.

## Limpieza del checkout raíz (2026-10-08)
En el checkout de `main` había trabajo sin commitear que pertenecía a las ramas
de asignatura. Se movió a su worktree y se commiteó en cada rama:

- `PRO1`: 7 ejercicios (P39057, P42280, P50327, P55622, P60816, P74398, X50286).
- `IC`: el enunciado `Practica3-IF-2023.pdf`.
- `FM`: un dibujo de Excalidraw sin extensión (`1r/Q1/FM/teoria/FM`), guardado
  como `1r/Q1/FM/teoria/apuntes.excalidraw`.

Además se restauró `LibPrac3-07-08-Q1.clf` (estaba truncado a 18 bytes en
`main`) y se eliminó `simulador-parcials/` desde la rama `PRO1`. Detalle del
error en `PITFALLS.md`.

## Fechas clave
El parcial de FM del 22/09/2026 ya pasó. Próximos parciales (según `README.md`):

- PRO1: 29/10/2026.
- IC: 30/10/2026.
- F: 03/11/2026.
- FM: 04/11/2026.

← [CONTEXT.md](CONTEXT.md)
