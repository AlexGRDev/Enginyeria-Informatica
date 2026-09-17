### Tema 1. Circuits — Càrrega i corrent elèctric

## 1. Conceptes bàsics de la càrrega elèctrica

- La càrrega elèctrica és una propietat fonamental de certes partícules (protó: `+e`, electró: `-e`).
- **Quantització**: qualsevol càrrega macroscòpica és múltiple enter de la càrrega elemental,
  `q = n·e`, amb `e = 1.602×10⁻¹⁹ C`.
- **Conservació**: la càrrega total d'un sistema aïllat es manté constant.

## 2. Força entre càrregues — Llei de Coulomb

**Intuïció**: dues càrregues del mateix signe es repel·len, de signe oposat s'atrauen. La força
depèn del producte de les càrregues i decreix amb el quadrat de la distància (com la gravetat,
però pot ser atractiva o repulsiva).

**Formalisme**: per a dues càrregues puntuals `q1`, `q2` separades una distància `r`:

`F⃗ = k · (q1·q2 / r²) · r̂`

on `k = 1/(4πε₀) ≈ 8.99×10⁹ N·m²/C²` (constant de Coulomb), i `r̂` és el vector unitari que va
de la càrrega que exerceix la força cap a la càrrega sobre la qual s'aplica.

- Mòdul: `F = k |q1||q2| / r²`
- Si `q1·q2 > 0` → força repulsiva (sentit de `r̂`, allunyant-se).
- Si `q1·q2 < 0` → força atractiva (sentit `-r̂`, apropant-se).
- Principi de superposició: la força total sobre una càrrega és la suma vectorial de les forces
  exercides per cada una de les altres càrregues per separat.

**Camp elèctric** (força per unitat de càrrega de prova `q0`):

`E⃗ = F⃗/q0`, i per a una càrrega puntual `Q`: `E⃗ = k·(Q/r²)·r̂`

## 3. Treball del camp elèctric i potencial elèctric

**Intuïció**: el camp elèctric és conservatiu (com el gravitatori), així que el treball que fa
sobre una càrrega en moure-la entre dos punts no depèn del camí, només dels punts inicial i
final. Això permet definir una energia potencial i, dividint per la càrrega, un "potencial"
que caracteritza el punt de l'espai independentment de quina càrrega de prova hi posem.

**Treball del camp elèctric** sobre una càrrega `q` que es mou d'un punt `A` a un punt `B`:

`W(A→B) = ∫(de A a B) F⃗·dl⃗ = q · ∫(de A a B) E⃗·dl⃗`

Com que `E` és conservatiu, aquest treball es pot escriure com la diferència d'una energia
potencial elèctrica `Ep`:

`W(A→B) = -ΔEp = Ep(A) - Ep(B)`

**Potencial elèctric** `V` (energia potencial per unitat de càrrega): es defineix prenent com a
referència el potencial nul a l'infinit, com el treball que faria el camp portant una càrrega
unitat des del punt `r` fins a l'infinit:

`V(r) = U(r)/q = ∫(de r a ∞) E⃗·dl⃗`, amb `[V] = V (volt) = J/C`

Per a una càrrega puntual `Q`:

`V(r) = k·Q/r`

**Diferència de potencial** entre dos punts `r1`, `r2` — coincideix amb el treball que fa el camp
sobre una càrrega unitat en anar de `r1` a `r2`:

`V1 - V2 = ∫(de r1 a r2) E⃗·dl⃗`

i relació general amb el treball sobre una càrrega `q` qualsevol:

`V_A - V_B = W(A→B)/q`  ⇒  `W(A→B) = q · (V_A - V_B)`

**Relació lineal entre `E` i la diferència de potencial** (per a un desplaçament del punt `A` al
punt `B`):

`V_A - V_B = -E⃗ · (r⃗_B - r⃗_A)`

**Projecció del camp** sobre la recta `AB` (mòdul, útil quan només interessa la component al
llarg del desplaçament):

`|E⃗_proj| = |V_A - V_B| / d_AB`, amb `d_AB = |r⃗_B - r⃗_A|`

**Condició d'exactitud** d'aquesta relació simplificada `|E| = |ΔV|/d`: és exacta si es dona
almenys una d'aquestes dues situacions:
1. El camp `E` és constant al llarg de tot el trajecte entre `A` i `B`.
2. La distància `d_AB` és molt petita (`Δr → 0`), de manera que el camp es pot considerar
   localment uniforme — cas límit que dona la forma diferencial ja vista:

`E⃗ = -∇V`  (en 1D: `E_x = -dV/dx`)

## 4. Corrent elèctric (intensitat)

**Descripció macroscòpica**: la intensitat és el ritme de pas de càrrega per una secció del
conductor:

`I = dQ/dt`, amb `[I] = A (ampere) = C/s`

**Descripció microscòpica**: en un conductor (metall, per exemple) hi ha un gran nombre de
portadors de càrrega mòbils (típicament electrons de conducció) que es desplacen amb una certa
*velocitat de deriva* `v_d` sota l'acció d'un camp elèctric.

- **Conductors**: tenen molts portadors mòbils (electrons lliures).
- **Aïllants**: pràcticament no tenen portadors mòbils.
- **Semiconductors**: densitat de portadors intermèdia, ajustable (dopatge), clau en electrònica.

Es defineix `n` com la **densitat volumètrica de portadors de càrrega** (nombre de portadors
per unitat de volum, `n` en `m⁻³`), que depèn del material.

**Relació entre magnituds microscòpiques i la intensitat**: considerant un conductor de secció
`A` amb `n` portadors per unitat de volum, cada un amb càrrega `q` i velocitat de deriva `v_d`,
la càrrega que travessa la secció en un temps `dt` és la continguda en un volum `A·v_d·dt`:

`I = n · q · v_d · A`

i la **densitat de corrent**:

`J⃗ = I/A = n · q · v⃗_d`, amb `[J] = A/m²`

### Taula de referència ràpida

| Magnitud | Símbol | Unitat SI | Relació |
|---|---|---|---|
| Càrrega elemental | `e` | C | `1.602×10⁻¹⁹ C` |
| Constant de Coulomb | `k` | N·m²/C² | `1/(4πε₀) ≈ 8.99×10⁹` |
| Força de Coulomb | `F` | N | `k q1 q2 / r²` |
| Camp elèctric | `E` | N/C = V/m | `F/q0` |
| Potencial elèctric | `V` | V (= J/C) | `Ep/q = kQ/r` |
| Treball del camp | `W` | J | `q (V_A - V_B)` |
| Intensitat | `I` | A (= C/s) | `dQ/dt = n q v_d A` |
| Densitat de portadors | `n` | m⁻³ | — |
| Densitat de corrent | `J` | A/m² | `I/A = n q v_d` |

## 5. Llei d'Ohm

**Intuïció**: en molts materials (conductors òhmics), com més gran és el camp elèctric
(o la diferència de potencial aplicada), més gran és la intensitat de corrent que hi circula,
de manera proporcional.

**Formalisme (forma macroscòpica)**:

`V = I · R`

on `R` és la **resistència** del conductor (`[R] = Ω`, ohm), que depèn de la geometria i del
material:

`R = ρ · L/A`

amb `ρ` la **resistivitat** del material (`[ρ] = Ω·m`), `L` la longitud del conductor i `A` la
secció.

**Forma microscòpica (llei d'Ohm local)**, relacionant densitat de corrent i camp elèctric:

`J⃗ = σ · E⃗`

on `σ = 1/ρ` és la **conductivitat**. Aquesta forma és la que connecta directament amb la
descripció microscòpica del corrent (`J = n q v_d`) vista abans.

### Taula de referència ampliada

| Magnitud | Símbol | Unitat SI | Relació |
|---|---|---|---|
| Resistència | `R` | Ω | `V/I = ρL/A` |
| Resistivitat | `ρ` | Ω·m | — |
| Conductivitat | `σ` | S/m (= (Ω·m)⁻¹) | `1/ρ` |
| Llei d'Ohm (macro) | — | — | `V = I R` |
| Llei d'Ohm (local) | — | — | `J = σ E` |

## Oscil·loscopi — resum

**Què és**: instrument que mostra com varia una tensió elèctrica en funció del temps.
Un feix d'electrons es desvia verticalment segons el senyal d'entrada `v(t)` i
horitzontalment segons una base de temps, de manera que la pantalla dibuixa:

`y(t) = K · v(t)`

**Tub de raigs catòdics (CRT)**: canó d'electrons + plaques de desviació vertical i
horitzontal + pantalla fluorescent. El feix impacta la pantalla i produeix un punt
lluminós; les plaques el desplacen amunt/avall (vertical) i esquerra/dreta (horitzontal).

**Camí del senyal (canal vertical)**:

`v(t) → atenuador (V/div) → amplificador vertical → plaques verticals → feix d'electrons`

- **V/div** (coeficient de deflexió): volts que representa cada divisió vertical de la
  reticula. Divisions visibles = `amplitud (V) / escala (V/div)`.
- **TIME/DIV** (base de temps): temps que representa cada divisió horitzontal; genera
  internament una tensió en dent de serra `v_H(t)` que mou el feix d'esquerra a dreta a
  ritme constant i el retorna ràpid en arribar al final.
- **Acoblament del canal**: `DC` deixa passar tot el senyal; `AC` filtra la component
  contínua amb un condensador (només es veu la part variable); `GND` connecta el canal a
  massa (línia horitzontal) per fixar el nivell de referència a la pantalla.
- **Trigger (activació/sincronització)**: fixa l'instant en què comença cada escombratge
  horitzontal, normalment quan el senyal creua un nivell (`LEVEL`) amb un cert pendent
  (`SLOPE`). Sense un trigger ben ajustat la imatge no és estable i "es mou" horitzontalment.

**Exemple (del PDF, secció "Control V/div")**: amb escala `0.5 V/div` i un senyal
d'amplitud `1.5 V`, la traça ocupa:

`1.5 V / 0.5 V/div = 3 divisions`

**Mesures típiques a partir de la reticula**:
- Amplitud: `divisions verticals × V/div`.
- Període `T`: `divisions horitzontals × TIME/DIV`.
- Freqüència: `f = 1/T`.

**Nota** (detall intern, `Intro_oscilloscopi.pdf`): l'amplificador vertical té més etapes
(preamplificador diferencial, línia de retard, amplificador de sortida) que generen dues
tensions oposades `±(G/2)·v(t)` per a les dues plaques; no cal per l'ús bàsic de l'aparell.
