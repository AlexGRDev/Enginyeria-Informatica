## Sumatoris — Exercicis

**Passeu a notació amb sumatori:**

1. (R) -2+0+2+4+6+⋯+50
2. 3+5+7+⋯+55
3. 2-4+6-⋯+50
4. -1²+3²-5²+7²-⋯-49²
5. (R) 2/1³ + 5/5³ + 8/9³ + 11/13³ + ⋯ + 47/61³
6. -3+0+3+6+9+12+⋯+60
7. 1³-4³+7³-10³+⋯+61³
8. (R) 1/3 - 1/7 + 1/11 - 1/15 + ⋯ - 1/39
9. -2/1 + 4/4³ - 6/7³ + 8/10³ - ⋯ - 42/61³

---

## EX1 - Resolució

**Enunciat:** -2+0+2+4+6+⋯+50

- [x] **1. Signes alterns?** No
- [x] **2. Patró:** diferència entre termes consecutius:
  - `0 - (-2) = 2`
  - `2 - 0 = 2`

  → El patró és: `-2 + 2i`

- [x] **3. Índex:** amb `i = 0`, comprova que dona el 1r terme:
  - `-2 + 2(0) = -2`
- [x] **4. Final:** amb la fórmula trobada, amb quin `i` s'obté el darrer terme (50)?
  - `-2 + 2i = 50`
  - `2i = 50 + 2`
  - `2i = 52`
  - `i = 52 / 2`
  - `i = 26`
**Notació final:**
```
   26
    Σ  (-2 + 2i)
   i=0
```

## EX2 — Resolució

**Enunciat:** 3+5+7+⋯+55

- [x] **1. Signes alterns?** No
- [x] **2. Patró:** diferència entre termes consecutius:
  - `5 - 3 = 2`
  - `7 - 5 = 2`

  → El patró és: `2n + c`

- [x] **3. Índex:** amb `n = 0`, quin valor de `c` fa que doni el 1r terme?
  - `2(0) + c = 3` → c = 3
- [x] **4. Final:** amb la fórmula trobada, amb quin `n` s'obté el darrer terme (55)?
  - `2n + 3 = 55`
  - `2n = 55 - 3`
  - `2n = 52`
  - `n = 52 / 2`
  - `n = 26`
**Notació final:**
```
   26
    Σ  (2n + 3)
   n=0
```

## EX3 - Resolució

**Enunciat:** 2-4+6-⋯+50

- [x] **1. Signes alterns?** Sí — el 1r terme és positiu, així que necessitem `(-1)^(i+1)`
- [x] **2. Patró:** diferència entre magnituds dels termes consecutius:
  - `4 - 2 = 2`
  - `6 - 4 = 2`

  → El patró és: `(-1)^(i+1) · 2i`

- [x] **3. Índex:** amb `i = 1`, comprova que dona el 1r terme:
  - `(-1)^(1+1) · 2(1) = (-1)^2 · 2 = 1 · 2 = 2`
- [x] **4. Final:** amb quin `i` s'obté el darrer terme (50)?
  - Signe: com el darrer terme (50) és positiu, `(-1)^(i+1) = +1`
  - Magnitud: `2i = 50`
  - `i = 50 / 2`
  - `i = 25`
  - Comprovació signe: `(-1)^(25+1) = (-1)^26 = +1`
**Notació final:**
```
   25
    Σ  (-1)^(i+1) · 2i
   i=1
```


