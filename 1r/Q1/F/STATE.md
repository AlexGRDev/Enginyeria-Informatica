# Estado — F

## Última actualización: 2026-09-21

## Cubierto
**2026-09-21**: revertida la convención de notación de fórmulas fijada el 2026-09-17
(bloques LaTeX `$$...$$` con `render-latex.nvim`) de vuelta a unicode/texto plano.
Se convirtieron 18 bloques LaTeX en `teoria/teoria.md` (Tema 1 y Oscil·loscopi) a
notación inline entre backticks con símbolos unicode (√, ·, Ω, →, ∫, ∇). Ver
`CONTEXT.md` para la convención actualizada.

**Tema 1. Circuits — Càrrega i corrent elèctric** (bloc Corrent Continu):
- Conceptes bàsics de càrrega elèctrica (quantització, conservació).
- Llei de Coulomb i camp elèctric.
- Treball del camp elèctric i potencial elèctric (relació `E`/`V`, forma diferencial `E = -∇V`).
- Corrent elèctric: descripció macroscòpica (`I = dQ/dt`) i microscòpica (`I = n·q·v_d·A`, densitat de corrent `J`).
- Llei d'Ohm (forma macroscòpica `V=IR` i microscòpica/local `J=σE`).

**Oscil·loscopi — resum** (basat en `material/Intro_oscilloscopi.pdf`, inclou apèndix C
del `apunts_Part1_tema1.pdf`): funcionament CRT, camí del senyal vertical
(atenuador→amplificador→plaques), controls V/div i TIME/DIV, acoblament AC/DC/GND,
trigger (nivell/pendent), exemple numèric del PDF (0.5 V/div, 1.5 V → 3 divisions),
mesures d'amplitud/període/freqüència a partir de la reticula.

**Pràctica 1 (oscil·loscopi i polímetre) — exercicis previs 1.2 i 2.1
resolts** el 2026-09-18 amb urgència d'entrega en paper (1h): veure
`ejercicios/PracticaOscilloscopi.md`. Inclou lectura de la Figura 4
(H=5 div, L=5 div → Vpp=10V, V0=5V, Vef≈3,54V, T=1,0ms, f=1kHz, amb errors
de resolució c1-c4) i el circuit resistiu de la Figura 5 (Rteo=75Ω,
I=133,3mA, I1=I2=I3=66,7mA, I4=I5=33,3mA). Pendent de contrastar amb la
nota real del professor (no verificat per cap font oficial més enllà de
l'enunciat mateix — revisar si hi ha hagut errors quan torni la pràctica
corregida).

## Pendiente
- Resto del bloc Corrent Continu no reflejado aún en `teoria.md` (si lo hay).
- Bloques Corrent Altern, Electrònica i portes lògiques, Ones — sin empezar en el repo.
- Material PDF ya disponible en `material/` para los bloques Corrent Altern (`P2_CorrentAltern.pdf`), Electrònica i portes lògiques (`P3_Electronica.pdf`) y Ones (`P4_Ones.pdf`) — pendiente de revisar cuando se empiecen esos bloques en clase.
- Revisar la resolució de `ejercicios/PracticaOscilloscopi.md` (1.2 i 2.1) contra la correcció real del professor de laboratori — feta sota pressió de temps, sense segona verificació humana.
- Falta fer/lliurar la resta de la pràctica 1 (1.3, 2.2 i la taula de mesures) al laboratori amb dades reals (no és feina de despatx, és al lab).

## Próximo examen/entrega
Parcial: 03/11/2026 (en ~7 semanas desde la última actualización).
Pràctica 1 laboratori (oscil·loscopi/polímetre): entrega en paper dels exercicis previs 2026-09-18.
