## Sumatoris

> **NOTA — Fórmula del sumatori**
> ```
>    n
>    Σ  ai = (am + am+1 + ... + an-1 + an)
>   i=m
> ```

---

### Passos per resoldre'ls

1. Mira si hi ha signes alterns → necessites `(-1)^i` o `(-1)^(i+1)`
2. Troba el terme general `ai` (patró: aritmètica, potència, fracció...)
3. Ajusta l'índex perquè al primer valor de `i` et doni el 1r terme
4. Troba fins a quin `i` arriba l'últim terme

---

## Lògica Proposicional

### Enunciat / proposició

> Frase susceptible de ser certa o falsa. Afirma alguna cosa amb sentit (certa o falsa).

- **Són enunciats:** `2+3=6`, "la pissarra és blava", "són les 7 en punt", "si 2+3=6 llavors la pissarra és blava"
- **NO són enunciats:** `2+3` (no afirma res), preguntes (`Quina hora és?`), ordres (`Esborreu la pissarra!`)

Hi ha enunciats **atòmics** (indescomponibles: `p`, `q`, `r`...) i enunciats **construïts** a partir d'atòmics amb connectives.

---

### Fórmules

**Alfabet:**
- Lletres proposicionals (àtoms): `p, q, r, s...`
- Connectives binàries: `∧ ∨ → ↔`
- Connectiva unària: `¬`
- Parèntesis: `( )`

> **NOTA — Definició recursiva de fórmula**
> 1. Les lletres proposicionals són fórmules.
> 2. Si `φ` és fórmula, `¬φ` també ho és.
> 3. Si `φ, ψ` són fórmules i `∗` és una connectiva binària, `(φ ∗ ψ)` també ho és.

**Convenis d'escriptura:**
- Mai es posen parèntesis a la negació: `¬p`, NO `(¬p)`
- Els parèntesis exteriors se suprimeixen: `(p ∨ q) → r`, NO `((p ∨ q) → r)`
- *(No s'usa a l'assignatura, però es pot trobar)* ordre de prioritat sense parèntesis: `∧, ∨, →, ↔`

---

### Passos per construir una taula de veritat

1. Identifica els àtoms de la fórmula (`p`, `q`, `r`...) → són les columnes d'entrada
2. Genera totes les combinacions de valors (2ⁿ files per a n àtoms)
3. Calcula primer les subfórmules més senzilles (columnes auxiliars) i ves construint cap a la fórmula completa
4. `1` = certa, `0` = falsa

> **NOTA — Taules de veritat de les connectives**
>
> | φ | ¬φ |
> |---|---|
> | 0 | 1 |
> | 1 | 0 |
>
> | φ | ψ | φ∧ψ | φ∨ψ | φ→ψ | φ↔ψ |
> |---|---|---|---|---|---|
> | 0 | 0 | 0 | 0 | 1 | 1 |
> | 0 | 1 | 0 | 1 | 1 | 0 |
> | 1 | 0 | 0 | 1 | 0 | 0 |
> | 1 | 1 | 1 | 1 | 1 | 1 |

A `φ → ψ`: `φ` és l'**antecedent**, `ψ` és el **conseqüent**.

**Exemple resolt** — taula de `¬(p→¬r) ↔ (p∨¬q)`:

| p | q | r | ¬r | p→¬r | ¬(p→¬r) | ¬q | p∨¬q | ¬(p→¬r) ↔ (p∨¬q) |
|---|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 0 | 0 | 1 | 0 | 1 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 | 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 0 | 0 | 1 | 0 | 1 | 1 |

---

### Tipus de fórmules

| Tipus | Definició | Taula de veritat |
|---|---|---|
| **Tautologia** | sempre certa | columna de `1` |
| **Contradicció** | sempre falsa | columna de `0` |
| **Satisfactible** | certa per alguna assignació | conté algun `1` |

> Insatisfactible = Contradicció

**Exemples de tautologies:** `p∨¬p`, `p→p`, `(p∧q)→p`, `p→(p∨q)`, `p→(q→p)`, `(p∧(p→q))→q`, `(¬q∧(p→q))→¬p`

**Exemples de contradiccions:** `p∧¬p`, `(p∧¬q)∧(p↔q)`, la negació de qualsevol tautologia

---

### Equivalència de fórmules

> **NOTA — Definició**
> Dues fórmules `φ, ψ` són **equivalents** (`φ ≡ ψ`) quan prenen els mateixos valors de veritat en totes les assignacions (mateixa taula de veritat).

- Totes les tautologies són equivalents entre si → es denoten per `1`
- Totes les contradiccions són equivalents entre si → es denoten per `0`

---

### Passos per demostrar equivalències sintàcticament (sense taules de veritat)

1. Substitueix `→` i `↔` per la seva traducció en `∧, ∨, ¬` (taula de traducció, més avall)
2. Aplica **De Morgan** per "entrar" les negacions al màxim
3. Aplica **distributiva** (i altres propietats bàsiques) fins arribar a l'altra fórmula
4. Si no és mecànic (p. ex. absorció), pot caldre introduir un neutre/complementari (`∧1`, `∨¬φ`) com a pas intermedi

> **NOTA — El color vermell (als apunts oficials) marca les propietats bàsiques** a partir de les quals es dedueixen formalment totes les altres.

**Taula d'equivalències importants** (`φ` és la dual canviant `∧↔∨` i `0↔1`):

| Nom | Equivalència | Dual |
|---|---|---|
| Distributiva | `φ∧(ψ∨θ) ≡ (φ∧ψ)∨(φ∧θ)` | `φ∨(ψ∧θ) ≡ (φ∨ψ)∧(φ∨θ)` |
| De Morgan | `¬(φ∧ψ) ≡ ¬φ∨¬ψ` | `¬(φ∨ψ) ≡ ¬φ∧¬ψ` |
| Absorció | `φ∧(φ∨ψ) ≡ φ` | `φ∨(φ∧ψ) ≡ φ` |
| Idempotència | `φ∧φ ≡ φ` | `φ∨φ ≡ φ` |
| Commutativa | `φ∧ψ ≡ ψ∧φ` | `φ∨ψ ≡ ψ∨φ` |
| Associativa | `φ∧(ψ∧θ) ≡ (φ∧ψ)∧θ` | `φ∨(ψ∨θ) ≡ (φ∨ψ)∨θ` |
| Neutre | `φ∧1 ≡ φ` | `φ∨0 ≡ φ` |
| Element absorbent | `φ∨1 ≡ 1` | `φ∧0 ≡ 0` |
| Complementari | `φ∨¬φ ≡ 1` | `φ∧¬φ ≡ 0` |
| Doble negació | `¬¬φ ≡ φ` | — |
| — | `¬1 ≡ 0` | `¬0 ≡ 1` |

**Notes:**
- L'associativa permet suprimir parèntesis: `p∧(q∧r)` → `p∧q∧r`
- Distributiva generalitzada: `φ∧(ψ1∨...∨ψn) ≡ (φ∧ψ1)∨...∨(φ∧ψn)` (i dual amb `∨`/`∧`)

**Traducció de `→`, `↔`:**

| | Directa | Negació |
|---|---|---|
| `→` | `φ→ψ ≡ ¬φ∨ψ` | `¬(φ→ψ) ≡ φ∧¬ψ` |
| `↔` | `φ↔ψ ≡ (φ→ψ)∧(ψ→φ) ≡ (φ∧ψ)∨(¬φ∧¬ψ)` | `¬(φ↔ψ) ≡ (φ∧¬ψ)∨(ψ∧¬φ) ≡ (φ∨ψ)∧(¬ψ∨¬φ)` |

**Equivalències específiques per a demostracions** (sense dual):

| Mètode | Equivalència |
|---|---|
| Contrarecíproc | `φ→ψ ≡ ¬ψ→¬φ` |
| Reducció a l'absurd | `φ ≡ ¬φ→0` &nbsp;&nbsp;\|&nbsp;&nbsp; `φ→ψ ≡ (φ∧¬ψ)→0` |
| `∨` al conseqüent | `ψ∨θ ≡ ¬ψ→θ` &nbsp;&nbsp;\|&nbsp;&nbsp; `φ→(ψ∨θ) ≡ (φ∧¬ψ)→θ` |
| `∨` a l'antecedent | `(ψ∨θ)→φ ≡ (ψ→φ)∧(θ→φ)` |

**Exemple resolt — Absorció** (cas no trivial, requereix pas intermedi):
```
p∧(p∨q) ≡[Neut]  (p∧(p∨q))∧1 ≡[Compl]  (p∧(p∨q))∧(p∨¬p) ≡[Ass]
p∧((p∨q)∧(p∨¬p)) ≡[Distr]  p∧(p∨(q∧¬p)) ≡[Distr]  (p∧p)∨(p∧(q∧¬p)) ≡[Idem,Comm]
p∨(p∧(¬p∧q)) ≡[Ass]  p∨((p∧¬p)∧q) ≡[Compl]  p∨(0∧q) ≡[Elem.Abs]  p∨0 ≡[Neut]  p
```

---

### Lògica de Predicats (Lògica de Primer Ordre / LPO)

> ⚠️ **Corrección de término:** en tus apuntes de clase pone "paridad 1 / 2 / 3" — el término correcto (y el que usa el profesor) es **aritat** (aridad). No tiene nada que ver con "parell/senar". Lo he corregido en todo este bloque para que no se mezcle con el concepto de paridad de Demostraciones.

**Relacions (= predicats)**

Per tenir una relació necessitem un **domini d'individus** (o *univers d'individus*). Cada relació té una **aritat**: un enter ≥ 1 que indica de quants arguments depèn.

| Aritat | Què és | Exemple (domini ℤ)  |
|--------|--------|---------------------|
| 1 | propietat d'un sol individu — cada element del domini la té o no | "ser parell", "ser un quadrat", "ser múltiple de 4" |
| 2 (binària) | propietat/relació entre parelles d'individus | `x < y`, `x = y`, "ser congruents mòdul 5" |
| 3 | relaciona tres individus | "x està entre y i z", "x és congruent amb y mòdul z" |

> En aquest context, **predicat** i **relació** són sinònims (predicat és una mica més ambigu).

**Fórmules atòmiques**

Cada relació es representa amb un **símbol de relació** (= símbol de predicat), amb la mateixa aritat que la relació.

> **NOTA Definició**
> Una fórmula atòmica és de la forma `R(x1, x2, ..., xn)`, on `R` és un símbol de relació d'aritat `n`.

- A les relacions binàries habituals (`=, <, >, ≤, ∈`) es fa servir notació **infixa**: `x < y` en lloc de `<(x,y)`
- Poden aparèixer expressions més complicades ("termes") en lloc de variables soltes: `0`, `1`, `y²`, `x²+2x`...

*Exemple:* amb `P` d'aritat 1, `Q, <` d'aritat 2, `R` d'aritat 3 → `P(x)`, `Q(y,x)`, `x<y`, `R(x,y,z)` són fórmules atòmiques.

**Fórmules de LPO**

Es formen combinant les atòmiques amb `∧ ∨ → ↔ ¬` i els **quantificadors**:
- `∀` — quantificador **universal**
- `∃` — quantificador **existencial**

> **NOTA — Definició recursiva de fórmula en LPO**
> 1. Les fórmules atòmiques són fórmules.
> 2. Si `φ, ψ` són fórmules i `∗` connectiva binària, `(φ∗ψ)` és fórmula.
> 3. Si `φ` és fórmula, `¬φ` també ho és.
> 4. Si `φ` és fórmula i `x` una variable, `∀xφ` i `∃xφ` també ho són.

*(Igual que a lògica proposicional: parèntesis només a connectives binàries, mai als quantificadors ni a la negació, i se suprimeix el parèntesi exterior.)*

**Significat**

Per avaluar una fórmula de LPO calen dues coses:
1. Un **domini d'individus** (amb almenys un element)
2. La **interpretació** dels símbols de relació (relacions concretes del domini, de la mateixa aritat)

- `∀xφ` — **tots** els individus `x` del domini compleixen `φ`
- `∃xφ` — **hi ha (almenys) un** individu `x` del domini que compleix `φ`

*Exemple* (domini ℤ; `P(x)`="x és parell", `Q(x)`="x és quadrat", `M(x)`="x és múltiple de 4"):

| Fórmula | Significat |
|---|---|
| `∀x(M(x)→P(x))` | Tot múltiple de 4 és parell |
| `∃x(P(x)∧¬M(x))` | Hi ha parells que no són múltiples de 4 |
| `∀x((P(x)∧Q(x))→M(x))` | Tot parell quadrat és múltiple de 4 |
| `P(2)∧¬Q(2)∧¬M(2)` | 2 és parell però no és quadrat ni múltiple de 4 |

> A vegades el domini s'indica a la mateixa fórmula: `∀x∈ℤ(M(x)→P(x))`. **Ull:** `∀x∈ℤ∃y∈ℕ x<y` NO és una fórmula de LPO tal qual — cal afegir un predicat `N(x)` ("x és natural") i escriure `∀x∃y(N(y)∧x<y)`.

**Equivalències en LPO**

| | |
|---|---|
| `¬∀xφ ≡ ∃x¬φ` | `¬∃xφ ≡ ∀x¬φ` |
| `∀x∀yφ ≡ ∀y∀xφ` | `∃x∃yφ ≡ ∃y∃xφ` |
| `∀x(φ∧ψ) ≡ ∀xφ∧∀xψ` | `∃x(φ∨ψ) ≡ ∃xφ∨∃xψ` |

> ⚠️ **Trampas típicas de examen NO son equivalentes en general:**
> - `∀x∃yφ` ≢ `∃y∀xφ` (cambiar el orden de cuantificadores distintos SÍ importa)
> - `∀x(φ∨ψ)` ≢ `∀xφ∨∀xψ`
> - `∃x(φ∧ψ)` ≢ `∃xφ∧∃xψ`
>
> *Contraejemplo clásico (dominio ℕ):* `∀x∃y (x<y)` es cierta pero `∃y∀x (x<y)` es falsa.


>NOTA: algunas equivalencias inportantes:
1, distributiva:
2. de Morgan: primite meter un not dentro de un paentecis, si pasamos los operadores logicos dentro del perntesis se inveierten
---

### Notes de color (convenis)

- Negre → exercicis de **Teoria**
- Blau → exercicis de **LAB**
- Verd → exercicis resolts al document d'Exercicis Resolts
- `(R)` → recomanat
