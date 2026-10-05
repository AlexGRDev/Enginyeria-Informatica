# Pràctica 2 — Simulació de circuits de corrent continu

Resolució dels problemes previs **1.3, 1.4 i 1.5** (apartats **2.1, 2.2 i 2.3**
del full de la pràctica). Es fan servir sempre valors **NOMINALS** de les
resistències — sense el soroll del DNI, que correspon a la part de simulació
(LTspice/CircuitLab) feta a part per l'usuari i que no forma part d'aquesta
entrega.

---

## 1.3 — Divisor de tensió (apartat 2.1 del full)

Dades: `ε = 5 V`, `R1 = 100 Ω`, `R2 = 200 Ω` (valors nominals), R1 i R2 en
sèrie amb la fem.

### Intensitat

`I = ε/(R1+R2) = 5/(100+200) = 5/300 ≈ 0,0167 A ≈ 16,7 mA`

### Caigudes de tensió

`V_R1 = I·R1 = 0,0167×100 ≈ 1,67 V`
`V_R2 = I·R2 = 0,0167×200 ≈ 3,33 V`

### Comprovació

`V_R1 + V_R2 = 1,67 + 3,33 = 5,00 V = ε` ✓

### Resum ràpid

| Magnitud | Valor |
|---|---|
| I | 16,7 mA |
| V_R1 | 1,67 V |
| V_R2 | 3,33 V |

**Observació**: les dues ddp (1,67 V i 3,33 V) són menors que la fem (5 V) →
per això es diu divisor de tensió.

---

## 1.4 — Resistència equivalent, Circuit 1 (apartat 2.2 del full)

Circuit de la Figura 6: quatre resistències iguals `R = 100 Ω` formant un
"rombe" entre els punts A, B, C, D — dos camins en paral·lel entre A i B:

- Camí 1 = A→C→B (`R_AC` + `R_CB` en sèrie)
- Camí 2 = A→D→B (`R_AD` + `R_DB` en sèrie)

### Resistència equivalent

Cada camí: `R_camí = R + R = 100+100 = 200 Ω`

Com els dos camins són iguals i estan en paral·lel:

`R_eq = (200×200)/(200+200) = 40000/400 = 100 Ω`

### Intensitats i tensions (amb ε = 1 V entre A i B)

`I_ε = ε/R_eq = 1/100 = 0,01 A = 10 mA`

Com els dos camins són idèntics, la intensitat es reparteix per igual:

`I1 (camí A-C-B) = I2 (camí A-D-B) = I_ε/2 = 5 mA` cadascun

Dins de cada camí, com són dues resistències en sèrie, la intensitat és la
mateixa a les dues: per exemple al camí A-C-B, la intensitat per `R_AC` i per
`R_CB` és 5 mA cadascuna.

Tensions (respecte de A=1V, B=0V):

`V_C = ε - I1·R_AC = 1 - 0,005×100 = 0,5 V`

Per simetria `V_D = 0,5 V` també.

### Resum ràpid

| Magnitud | Valor |
|---|---|
| R_eq | 100 Ω |
| I_ε | 10 mA |
| I1 = I2 | 5 mA |
| V_C = V_D | 0,5 V |

---

## 1.5 — Resistència equivalent, Circuit 2 (apartat 2.3 del full)

Mateix circuit de 1.4, afegint una cinquena resistència `R5 ≈ 100 Ω` entre els
punts C i D (problema 17 del dossier de problemes de Física, Corrent
Continu — és un pont de Wheatstone). Cal demostrar-ho amb les lleis de
Kirchhoff (no només per simetria "a ull").

### Demostració amb les lleis de Kirchhoff

Prenent B com a referència (`V_B = 0`) i `V_A = ε`, aplicant la primera llei
de Kirchhoff (llei dels nusos) als nusos C i D:

**Nus C**:
`(V_A - V_C)/R - (V_C - V_B)/R - (V_C - V_D)/R5 = 0`
→ `ε/R - 2·V_C/R - (V_C - V_D)/R5 = 0` ... (i)

**Nus D**:
`(V_A - V_D)/R - (V_D - V_B)/R + (V_C - V_D)/R5 = 0`
→ `ε/R - 2·V_D/R + (V_C - V_D)/R5 = 0` ... (ii)

**Sumant (i) + (ii)**:
`2ε/R - 2(V_C+V_D)/R = 0` → `V_C + V_D = ε`

**Restant (i) − (ii)**:
`-2(V_C-V_D)/R - 2(V_C-V_D)/R5 = 0` → `(V_C-V_D)·[-2/R - 2/R5] = 0`

Com el claudàtor no és zero (R i R5 són finites i positives), necessàriament
`V_C - V_D = 0`, és a dir `V_C = V_D`.

Combinant amb `V_C + V_D = ε`: `V_C = V_D = ε/2`.

### Conclusió (pont equilibrat)

- Intensitat per R5: `I_R5 = (V_C - V_D)/R5 = 0/100 = 0 A` — no hi circula
  cap corrent, independentment del valor de R5 (és un pont de Wheatstone
  equilibrat perquè les relacions `R_AC/R_CB = R_AD/R_DB = 1` es compleixen).
- Com R5 no porta corrent, el circuit es comporta exactament igual que a
  l'apartat 1.4: `R_eq = 100 Ω` (sense canvis).
- Intensitat total: `I_ε = ε/R_eq = 1/100 = 0,01 A = 10 mA` (igual que abans).

### Resum ràpid

| Magnitud | Valor |
|---|---|
| R_eq | 100 Ω |
| I_ε | 10 mA |
| I_R5 | 0 A |

---

## Procedència de les dades

- Enunciat: `53_P2_GarciaRodriguezAlex.pdf` (full de la Pràctica 2 — Simulació
  de circuits de corrent continu).
- Problema 1.5 correspon al problema 17 del dossier de problemes de Física,
  Corrent Continu (pont de Wheatstone).
- Valors de resistències nominals (sense soroll de DNI); la part de simulació
  amb LTspice/CircuitLab i valors ajustats pel DNI es fa a part per l'usuari i
  no forma part d'aquesta entrega en paper.
