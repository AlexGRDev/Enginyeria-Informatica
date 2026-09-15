## 0. Sumatoris

> **NOTA — Fórmula del sumatori**
> ```
>    n
>    Σ  ai = am + am+1 + ... + an-1 + an
>   i=m
> ```

**Exemples:**
- `Σ(i=1..100) i = 1+2+...+100`
- `Σ(i=1..30) (-1)^i (2i-1) = -1+3-5+...+59`  *(signes alterns → `(-1)^i`)*

### Passos per resoldre'ls
1. Signes alterns? → necessites `(-1)^i` o `(-1)^(i+1)`
2. Troba el terme general `ai` (patró: aritmètica, potència, fracció...)
3. Ajusta l'índex perquè al primer valor de `i` et doni el 1r terme
4. Troba fins a quin `i` arriba l'últim terme

---

### Propietats i canvi d'índex

> ```
>  Σ(ai+bi) = Σai + Σbi        (linealitat)
>  Σ c·ai   = c·Σai            (treure constant)
> ```

**Canvi d'índex:** per fer que un sumatori comenci a `j=0`, substitueix `i = j+k` (o `i = j-k`) i ajusta límits i terme general en conseqüència — és el pas 3 anterior aplicat a l'inrevés.

**Sumes conegudes** (surten dins altres exercicis):
```
Σ(k=1..n) k  = n(n+1)/2          Σ(k=1..n) k² = n(n+1)(2n+1)/6
```

---

### Progressions

**Aritmètica** (`ai+1 = ai+d` → `ai = a0+i·d`):
> `Σai = (am+an)(n-m+1)/2`  — *(n-m+1 = nombre de termes; s'aparella 1r amb últim, 2n amb penúltim... cada parella suma `am+an`)*

**Geomètrica** (`ai+1 = r·ai` → `ai = a0·r^i`, r≠1):
> `Σai = (a(n+1)-am)/(r-1)`  — *(multiplica tot el sumatori per `(r-1)`, telescopa)*

---

### Productoris

> `∏ai = am · a(m+1) · ... · an`

```
∏(ai·bi) = ∏ai · ∏bi        ∏(ai^c) = (∏ai)^c        ∏(c·ai) = c^(n-m+1) · ∏ai
```

---

## 1.1 Lògica Proposicional

**Enunciat:** frase susceptible de ser certa o falsa. `2+3` NO és enunciat (no afirma res); una pregunta o ordre tampoc.

**Fórmula:** àtoms `p,q,r...` + connectives `∧ ∨ → ↔` + `¬` + `( )`.
- Mai parèntesis a la negació (`¬p`, no `(¬p)`); se suprimeix el parèntesi exterior.

### Passos per construir una taula de veritat
1. Identifica els àtoms → columnes d'entrada (2ⁿ files)
2. Calcula primer les subfórmules més senzilles (columnes auxiliars), ves construint cap a la fórmula completa
3. `1`=certa, `0`=falsa

> | φ | ψ | ¬φ | φ∧ψ | φ∨ψ | φ→ψ | φ↔ψ |
> |---|---|---|---|---|---|---|
> | 0 | 0 | 1 | 0 | 0 | 1 | 1 |
> | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
> | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
> | 1 | 1 | 0 | 1 | 1 | 1 | 1 |

A `φ→ψ`: φ=**antecedent**, ψ=**conseqüent**.

**Exemple resolt** — `¬(p→¬r) ↔ (p∨¬q)`:

| p | q | r | ¬r | p→¬r | ¬(p→¬r) | ¬q | p∨¬q | resultat |
|---|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 0 | 0 | 1 | 0 | 1 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 | 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 0 | 0 | 1 | 0 | 1 | 1 |

**Tipus:** Tautologia (sempre `1`) · Contradicció = insatisfactible (sempre `0`) · Satisfactible (algun `1`)

---

### Equivalència de fórmules

`φ≡ψ` quan tenen la mateixa taula de veritat. Totes les tautologies ≡ entre si (`1`); totes les contradiccions ≡ entre si (`0`).

**Taula d'equivalències importants** (dual: canvia `∧↔∨` i `0↔1`):

| Nom | φ | Dual |
|---|---|---|
| Distributiva | `φ∧(ψ∨θ)≡(φ∧ψ)∨(φ∧θ)` | `φ∨(ψ∧θ)≡(φ∨ψ)∧(φ∨θ)` |
| De Morgan | `¬(φ∧ψ)≡¬φ∨¬ψ` | `¬(φ∨ψ)≡¬φ∧¬ψ` |
| Absorció | `φ∧(φ∨ψ)≡φ` | `φ∨(φ∧ψ)≡φ` |
| Idempotència | `φ∧φ≡φ` | `φ∨φ≡φ` |
| Commutativa/Associativa | estàndard | estàndard |
| Neutre | `φ∧1≡φ` | `φ∨0≡φ` |
| Elem. absorbent | `φ∨1≡1` | `φ∧0≡0` |
| Complementari | `φ∨¬φ≡1` | `φ∧¬φ≡0` |
| Doble negació | `¬¬φ≡φ` | — |

**Traducció:** `φ→ψ ≡ ¬φ∨ψ`  ·  `φ↔ψ ≡ (φ→ψ)∧(ψ→φ) ≡ (φ∧ψ)∨(¬φ∧¬ψ)`

### Passos per demostrar equivalències sintàcticament
1. Substitueix `→`,`↔` per la seva traducció
2. Aplica **De Morgan** per entrar les negacions al màxim — *fica el `¬` dins del parèntesi i inverteix `∧`↔`∨`*
3. Aplica distributiva i altres propietats bàsiques fins arribar a l'altra fórmula
4. Si no és mecànic (p.ex. absorció), introdueix `∧1` o `∨¬φ` com a pas intermedi

**Exemple resolt — Absorció** (cas no mecànic):
```
p∧(p∨q) ≡[Neut] (p∧(p∨q))∧1 ≡[Compl] (p∧(p∨q))∧(p∨¬p) ≡[Ass,Distr]
p∧(p∨(q∧¬p)) ≡[Distr,Idem] p∨(p∧(¬p∧q)) ≡[Ass,Compl] p∨(0∧q) ≡[Elem.Abs,Neut] p
```

---

### Notes de color
Negre=Teoria · Blau=LAB · Verd=resolt a Exercicis Resolts · `(R)`=recomanat
