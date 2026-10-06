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

---

## Valors de simulació (2.1, 2.2, 2.3) — resistències amb soroll del DNI

> **Avís important**: els valors d'aquesta secció NO són una captura real
> d'una simulació executada a LTspice o CircuitLab. Són valors calculats
> analíticament (llei d'Ohm + lleis de Kirchhoff), resolent les mateixes
> equacions que resoldria el simulador per a un circuit resistiu en DC.
> Serveixen per **comparar/verificar** la simulació real que encara cal fer,
> no per substituir-la. Segueix pendent, per a cada apartat (2.1, 2.2, 2.3):
> muntar el circuit de debò a LTspice o CircuitLab i fer la seva pròpia
> captura de pantalla — és una entrega obligatòria a part (l'enunciat demana
> explícitament "Captura de pantalla del circuit implementat amb una eina de
> simulació" a cada apartat).

### DNI utilitzat i mètode de soroll

DNI: `26613172X` → dígits (sense la lletra): `n1=2, n2=6, n3=6, n4=1, n5=3,
n6=1, n7=7, n8=2`.

Mètode de l'enunciat: `Ri* = Ri + nᵢ - 5`.

**Supòsit de numeració adoptat** (l'enunciat és ambigu en això): cada circuit
reinicia el comptador de dígits a `n1` en generar les seves pròpies
resistències R1, R2..., EXCEPTE el circuit de 2.3, que reutilitza exactament
les mateixes R1-R4 ja generades a 2.2 (perquè l'enunciat diu literalment
"Modifiqueu el circuit de l'apartat 2.2 afegint una resistència R5") i
simplement continua el comptador de dígits en `n5` per a la R5 nova.
**Si el professor va voler una altra interpretació** (dígits consumits de
forma contínua a través de tots els circuits sense reiniciar), els valors
numèrics canviarien.

---

### 2.1 — Divisor de tensió (resistències amb soroll)

Dígits usats: `n1=2` (per R1), `n2=6` (per R2).

- `R1* = 100 + 2 - 5 = 97 Ω`
- `R2* = 200 + 6 - 5 = 201 Ω`
- `I = ε/(R1*+R2*) = 5/(97+201) = 5/298 ≈ 0,01678 A ≈ 16,78 mA`
- `VAB (caiguda a R1*, el connectat a terra) = I·R1* ≈ 1,628 V`
- `VBC (caiguda a R2*) = I·R2* ≈ 3,372 V`
- Comprovació: `1,628 + 3,372 = 5,000 V = ε` ✓

| Magnitud | te (nominal) | ex (amb soroll DNI) |
|---|---|---|
| I | 16,7 mA | 16,78 mA |
| VAB | 1,67 V | 1,628 V |
| VBC | 3,33 V | 3,372 V |

---

### 2.2 — Resistència equivalent, Circuit 1 (resistències amb soroll)

Dígits usats: `n1=2` (R1), `n2=6` (R2), `n3=6` (R3), `n4=1` (R4). Mapeig de
nusos (igual que a l'apartat 1.4): camí A-C-B = R1 (A-C) + R3 (C-B); camí
A-D-B = R2 (A-D) + R4 (D-B).

- `R1* = 100+2-5 = 97 Ω` ; `R2* = 100+6-5 = 101 Ω` ; `R3* = 100+6-5 = 101 Ω` ; `R4* = 100+1-5 = 96 Ω`
- Camí A-C-B: `R1*+R3* = 97+101 = 198 Ω` → `I1 = ε/198 = 1/198 ≈ 0,00505 A ≈ 5,05 mA`
- Camí A-D-B: `R2*+R4* = 101+96 = 197 Ω` → `I2 = ε/197 = 1/197 ≈ 0,00508 A ≈ 5,08 mA`
- `Iε = I1+I2 ≈ 10,13 mA`
- `Req = ε/Iε = 1/0,01013 ≈ 98,75 Ω` (equivalentment: `(198×197)/(198+197) ≈ 98,75 Ω`)
- `VC = ε - I1·R1* = 1 - 0,00505×97 ≈ 0,510 V`
- `VD = ε - I2·R2* = 1 - 0,00508×101 ≈ 0,487 V`

| Magnitud | te (nominal) | ex (amb soroll DNI) |
|---|---|---|
| VC | 0,5 V | 0,510 V |
| VD | 0,5 V | 0,487 V |
| I1 | 5 mA | 5,05 mA |
| I2 | 5 mA | 5,08 mA |
| Iε | 10 mA | 10,13 mA |
| Req | 100 Ω | 98,75 Ω |

---

### 2.3 — Resistència equivalent, Circuit 2 (mateix circuit + R5 amb soroll)

Mateixes R1*-R4* que a 2.2 (97, 101, 101, 96 Ω). Dígit següent `n5=3` per R5:
`R5* = 100+3-5 = 98 Ω`.

Com els valors de R1*-R4* ja no són exactament iguals (97, 101, 101, 96 en
lloc de tots 100), el pont deixa d'estar perfectament equilibrat → SÍ
circula una petita intensitat per R5* (a diferència de l'apartat teòric 1.5,
on amb valors nominals iguals el pont estava equilibrat i `I_R5 = 0`).

Resolent per les lleis de Kirchhoff als nusos C i D (mateix mètode que a 1.5
però amb els valors amb soroll, sense poder simplificar per simetria):

- `VC ≈ 0,504 V`
- `VD ≈ 0,493 V`
- `I1 (= I_AC = (VA-VC)/R1*) ≈ 5,11 mA`
- `I5 (= (VC-VD)/R5*) ≈ 0,11 mA` (circula de C cap a D)
- `Iε ≈ 10,13 mA`
- `Req = ε/Iε ≈ 98,73 Ω` (pràcticament igual que a 2.2, perquè R5 amb el pont
  quasi equilibrat té un efecte de segon ordre sobre la resistència
  equivalent)

| Magnitud | te (nominal) | ex (amb soroll DNI) |
|---|---|---|
| VC | 0,5 V | 0,504 V |
| VD | 0,5 V | 0,493 V |
| I1 | 5 mA | 5,11 mA |
| I5 | 0 mA | 0,11 mA |
| Iε | 10 mA | 10,13 mA |
| Req | 100 Ω | 98,73 Ω |

---

### Resum de resistències generades (DNI: 26613172X)

Valors a proporcionar a l'informe, junt amb el número de DNI (segons demana
l'enunciat: "Proporcioneu els valors obtinguts de les resistències R1, R2,
..., R6 a l'informe, junt amb el vostre número de DNI"):

| Resistència | Apartat | Dígit DNI | Valor nominal | Valor amb soroll (Ri* = Ri + nᵢ - 5) |
|---|---|---|---|---|
| R1 | 2.1 | n1=2 | 100 Ω | 97 Ω |
| R2 | 2.1 | n2=6 | 200 Ω | 201 Ω |
| R1 | 2.2 / 2.3 | n1=2 | 100 Ω | 97 Ω |
| R2 | 2.2 / 2.3 | n2=6 | 100 Ω | 101 Ω |
| R3 | 2.2 / 2.3 | n3=6 | 100 Ω | 101 Ω |
| R4 | 2.2 / 2.3 | n4=1 | 100 Ω | 96 Ω |
| R5 | 2.3 | n5=3 | 100 Ω | 98 Ω |
