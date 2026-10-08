# Estado — F

## Última actualización: 2026-10-06

## Cubierto
**2026-10-05**: Pràctica 2 (Simulació de circuits de corrent continu) —
problemes previs teòrics **1.3, 1.4 i 1.5** resolts amb valors NOMINALS de les
resistències, veure `ejercicios/PracticaP2_CorrentContinu.md`. Inclou divisor
de tensió (1.3: I≈16,7mA, V_R1≈1,67V, V_R2≈3,33V), resistència equivalent del
circuit en rombe (1.4: R_eq=100Ω, I_ε=10mA) i el mateix circuit amb pont de
Wheatstone equilibrat demostrat per lleis de Kirchhoff (1.5: R_eq=100Ω,
I_ε=10mA, I_R5=0A).

**2026-10-06**: afegits a `ejercicios/PracticaP2_CorrentContinu.md` els
valors dels apartats **2.1, 2.2 i 2.3** amb resistències "amb soroll" del DNI
(26613172X), calculats analíticament (NO és una simulació real executada a
LTspice/CircuitLab — veure avís al document). Inclou divisor de tensió (2.1:
I≈16,78mA), circuit en rombe (2.2: Req≈98,75Ω, I1≈5,05mA, I2≈5,08mA) i el
mateix circuit + R5 (2.3: amb el pont ja no exactament equilibrat pel soroll,
I5≈0,11mA, Req≈98,73Ω). Adoptat el supòsit que cada circuit reinicia el
comptador de dígits del DNI excepte 2.3, que continua des de 2.2 (afegeix
R5); queda explícit al document que el professor podria haver volgut l'altra
interpretació (comptador continu sense reiniciar).

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
- Pràctica 2: els valors numèrics de 2.1-2.3 (amb soroll del DNI) ja estan
  calculats a `ejercicios/PracticaP2_CorrentContinu.md`, però segueix
  pendent, i és feina manual de l'usuari que no es pot fer aquí: (a) muntar
  els 3 circuits de debò a LTspice o CircuitLab i fer les captures de
  pantalla reals (entrega obligatòria a part); (b) aconseguir i omplir la
  plantilla oficial `subgrup_P2_cognom_nom.odt` del Racó (no la tenim al
  repo); (c) pujar l'entrega al Racó — termini sense confirmar: hi ha
  indicis contradictoris de si és avui 2026-10-05 23:59 o si es va ampliar,
  cal confirmar-ho amb l'usuari abans de donar-ho per bo.

## Próximo examen/entrega
Parcials: 03/11/2026 i 23/12/2026. Final: 18/01/2027.
Pràctica 1 laboratori (oscil·loscopi/polímetre): entrega en paper dels exercicis previs 2026-09-18.
