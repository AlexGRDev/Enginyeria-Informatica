## 1.1 Lògica — eines per als exercicis

> **NOTA — Equivalència dels àtoms i connectives amb Àlgebra de Boole i C/C++** *(útil per als exercicis 8-17)*
>
> | Lògica Formal (apunts) | Àlgebra de Boole / Circuits | C / C++ |
> |---|---|---|
> | `p, q, r` (o `φ,ψ,θ`) — àtoms | `A, B, C` | `bool p, q, r;` |
> | `1 / 0` (Cert / Fals) | `1 / 0` (HIGH / LOW) | `true / false` |
> | `¬p` | `Ā`, `A'` (NOT) | `!p` |
> | `p∧q` | `A·B`, `AB` (AND) | `p && q` |
> | `p∨q` | `A+B` (OR) | `p \|\| q` |
> | `p⊕q` (disjunció exclusiva) | `A⊕B` (XOR) | `p != q` |
> | `p→q` (traducció: `¬p∨q`) | `Ā+B` | `!p \|\| q` |
> | `p↔q` (traducció: `(p∧q)∨(¬p∧¬q)`) | complement de `A⊕B` (XNOR) | `p == q` |
> | `¬(p∧q)` | complement de `A·B` (NAND) | `!(p && q)` |
> | `¬(p∨q)` | complement de `A+B` (NOR) | `!(p \|\| q)` |
>
> *Nota:* `p⊕q` no surt als apunts de FM com a connectiva pròpia (a l'assignatura només s'usen `∧ ∨ ¬ → ↔`), però és útil tenir-la aquí perquè apareix constantment en IC/Assembly i en C/C++.

---

## Ejercicios 8-17 — Equivalència de notació: Lògica Formal / Àlgebra de Boole / C++

| Lògica Formal (`p,q,r` o `φ,ψ,θ`) | Àlgebra de Boole / Circuits (`A,B,C`) | C / C++ (`p,q,r`) |
|---|---|---|
| `1` / `0` (Cert / Fals) | `1` / `0` (HIGH / LOW, Vcc / GND) | `true` / `false` |
| `¬p` (Negació) | `Ā` o `A'` (NOT) | `!p` |
| `p∧q` (Conjunció) | `A·B` o `AB` (AND) | `p && q` |
| `p∨q` (Disjunció) | `A+B` (OR) | `p \|\| q` |
| `p⊕q` (Disjunció exclusiva) | `A⊕B` (XOR) | `p != q` |
| `p→q` (Implicació) `≡ ¬p∨q` | `Ā+B` | `!p \|\| q` |
| `p↔q` (Equivalència) `≡ ¬(p⊕q)` | `Ā⊕B` complement (XNOR) | `p == q` |
| `¬(p∧q)` (NAND) | `A·B` complement (NAND) | `!(p && q)` |
| `¬(p∨q)` (NOR) | `A+B` complement (NOR) | `!(p \|\| q)` |

**De Morgan, en els tres llenguatges** (el pas que més es fa servir per simplificar):

| Lògica | Boole | C++ |
|---|---|---|
| `¬(p∧q) ≡ ¬p∨¬q` | `A·B` complement `= Ā+B̄` | `!(p&&q) == (!p || !q)` |
| `¬(p∨q) ≡ ¬p∧¬q` | `A+B` complement `= Ā·B̄` | `!(p\|\|q) == (!p && !q)` |

> **Nota tècnica (IC/ARM64):** `NAND` i `NOR` s'anomenen *funcionalment complets*  amb un sol tipus de porta (només NAND, o només NOR) es pot construir qualsevol altra porta lògica (`AND`, `OR`, `NOT`...). És per això que a nivell de fabricació moltes CPUs es dissenyen íntegrament a base de portes NAND.

---

### Notes de color
Negre=Teoria · Blau=LAB · Verd=resolt a Exercicis Resolts · `(R)`=recomanat
