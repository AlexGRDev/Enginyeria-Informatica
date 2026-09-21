# Pràctica 1 — Funcionament de l'oscil·loscopi i del polímetre

Entrega prèvia al laboratori: només cal lliurar la resolució dels apartats
**1.2 Exercici previ** i **2.1 Exercici previ**. Tota la resta de l'enunciat
(1.3, 2.2 i la taula de mesures) es respon **durant** la pràctica al
laboratori amb l'aparell real — no forma part d'aquesta entrega en paper.

**Nota sobre les dades**: aquests dos exercicis previs són autocontinguts —
totes les dades (A, B, la gràfica; R1..R5, ε) ja venen donades a
l'enunciat. No calen mesures reals de laboratori per resoldre'ls (aquestes
es prenen a la pràctica mateixa amb l'oscil·loscopi i el polímetre, i
s'apunten a la taula de la pàgina 6, que no s'entrega ara).

---

## 1.2 Exercici previ (oscil·loscopi)

Dades: `A = 2 V/div` (coeficient de deflexió), `B = 0.2 ms/div` (base de
temps). Cada divisió = 5 subdivisions.

### a) Valors H i L llegits a la Figura 4

## H = 5 divisions      L = 5 divisions

(H = distància vertical màxim-mínim; L = distància horitzontal entre dos
màxims consecutius, comptades directament sobre la reticula de la Figura 4.)

### b) Determineu

**b1) Tensió pic a pic**
`Vpp = A·H = 2 V/div × 5 div`

## Vpp = 10 V

**b2) Amplitud i valor eficaç**
`V0 = Vpp/2 = 10/2`

## V0 = 5 V

`Vef = V0/√2 = 5/1.4142`

## Vef ≈ 3,54 V

**b3) Període**
`T = B·L = 0.2 ms/div × 5 div`

## T = 1,0 ms  (= 1,0·10⁻³ s)

**b4) Freqüència**
`f = 1/T = 1/(1,0·10⁻³ s)`

## f = 1000 Hz = 1 kHz

### c) Error absolut i relatiu (2 xifres significatives)

Escala mínima llegible = 1 subdivisió. Error de resolució = meitat d'una
subdivisió (regla de l'aparell analògic).

- Subdivisió vertical = A/5 = 2/5 = 0,4 V → error en H: ΔH = 0,1 div → en volts: **ΔVpp = A·ΔH = 2×0,1 = 0,2 V**
- Subdivisió horitzontal = B/5 = 0,2/5 = 0,04 ms → error en L: ΔL = 0,1 div → **ΔT = B·ΔL = 0,2×0,1 = 0,02 ms**

**c1) Vpp**

## Vpp = (10,0 ± 0,2) V     (error relatiu 2 %)

**c2) V0 i Vef**
ΔV0 = ΔVpp/2 = 0,1 V ; ΔVef = ΔV0/√2 ≈ 0,07 V

## V0 = (5,0 ± 0,1) V   →   4,0 %      Vef = (3,54 ± 0,07) V   →   2,0 %

**c3) Període T**

## T = (1,00 ± 0,02) ms     (error relatiu 2 %)

**c4) Freqüència f**
Δf/f = ΔT/T = 2 % → Δf = 1000×0,02 = 20 Hz

## f = (1,00 ± 0,02) kHz  =  (1000 ± 20) Hz     (error relatiu 2 %)

---

## 2.1 Exercici previ (polímetre — circuit resistiu)

Dades (Figura 5): `R1=50 Ω, R2=100 Ω, R3=50 Ω, R4=200 Ω, R5=200 Ω`,
`ε = 10 V`, resistència interna de la font = 0.

**Topologia**: entre A i B hi ha dues branques en paral·lel:
- Branca inferior: R1 i R2 en **sèrie** (mateix corrent I1=I2).
- Branca superior: (R4 ∥ R5) en **sèrie** amb R3 (corrent I3 total, que es
  reparteix entre I4 i I5).

### Resistència equivalent teòrica

`R4∥R5 = (200×200)/(200+200) = 100 Ω`
Branca superior = 100 + 50 = 150 Ω
Branca inferior = 50 + 100 = 150 Ω
`Rteo = (150×150)/(150+150)`

## Rteo = 75 Ω

### Intensitat total

`I = ε / Rteo = 10 / 75`

## I = 0,1333 A ≈ 133,3 mA

Les dues branques tenen la mateixa resistència (150 Ω cadascuna) → el
corrent total es reparteix **per igual**:

## I1 = I2 = I3 = I/2 = 66,7 mA

R4 i R5 són iguals (200 Ω) → I3 es reparteix per igual entre elles:

## I4 = I5 = I3/2 = 33,3 mA

### Caigudes de tensió (V = I·R)

| Resistència | Corrent | V = I·R |
|---|---|---|
| R1 = 50 Ω | I1 = 66,7 mA | **V1 = 3,33 V** |
| R2 = 100 Ω | I2 = 66,7 mA | **V2 = 6,67 V** |
| R3 = 50 Ω | I3 = 66,7 mA | **V3 = 3,33 V** |
| R4 = 200 Ω | I4 = 33,3 mA | **V4 = 6,67 V** |
| R5 = 200 Ω | I5 = 33,3 mA | **V5 = 6,67 V** |

Comprovació: V1+V2 = 3,33+6,67 = 10 V = ε ✓ i V3+V4(=V5) = 3,33+6,67 = 10 V = ε ✓

### Resum ràpid per copiar

## Rteo = 75 Ω · I = 133,3 mA
## I1=I2=I3 = 66,7 mA · I4=I5 = 33,3 mA
## V1=V3 = 3,33 V · V2=V4=V5 = 6,67 V

---

## Procedència de les dades

- Enunciat: `practica-oscilloscopi.pdf` (manual oficial FIB Física —
  Pràctiques de laboratori, "Funcionament de l'oscil·loscopi i del
  polímetre").
- S'ha revisat el xip de WhatsApp "Grup 50" (`_chat.txt` + 27 imatges,
  14–18/09/2026) buscant dades reals de laboratori (captures de
  l'oscil·loscopi, fotos de mesures). **No calien**: els dos exercicis
  previs es resolen íntegrament amb les dades del propi enunciat. L'única
  imatge rellevant trobada al xip (`00003599-PHOTO-2026-09-17-18-09-13.jpg`,
  17/09 18:09) és una foto d'un mòbil de la mateixa pàgina 8 del manual
  (Figura 4 inclosa) — confirma les dades ja usades aquí (A=2V/div,
  B=0.2ms/div), no n'aporta de noves. La resta d'imatges del xip són alienes
  a aquesta pràctica (dubtes d'IC/lògica, stickers).
