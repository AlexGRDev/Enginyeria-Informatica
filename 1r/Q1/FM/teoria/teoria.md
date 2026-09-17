# 1. Lògica i Demostracions — Teoria

*(Base conceptual: definicions i propietats. Per a la tècnica de resoldre exercicis, veure `lab.md`.)*

## 1.1 Lògica Proposicional

Abans de poder demostrar res formalment, necessitem un llenguatge on els enunciats matemàtics es puguin combinar i avaluar sense ambigüitat. Això és la **lògica proposicional**.

**Enunciat (proposició):** frase susceptible de ser certa o falsa, però no alhora. $2+3$, preguntes o ordres NO són enunciats (no afirmen res); $x+1=2$ tampoc ho és mentre `x` no tingui un valor assignat.

**Fórmula:** una manera formal d'escriure enunciats combinats. S'hi construeix amb:
- **Àtoms** `p, q, r...` (proposicions simples, indivisibles)
- **Connectives binàries** $\land \lor \rightarrow \leftrightarrow$ i la **connectiva unària** $\neg$
- **Parèntesis** `( )`, només per evitar ambigüitat

> **Fórmula atòmica:** un àtom (`p, q, r...`) tot sol, sense combinar amb cap connectiva, és el cas base de la definició recursiva següent i el bloc més elemental amb què es construeix qualsevol fórmula de lògica proposicional.

> Definició recursiva: els àtoms són fórmules; si $\varphi$ és fórmula, $\neg\varphi$ també; si $\varphi,\psi$ són fórmules i $*$ és una connectiva binària, $(\varphi * \psi)$ també ho és.

**Convenis d'escriptura:** mai es posen parèntesis a la negació ($\neg p$, no $(\neg p)$); el parèntesi exterior sempre se suprimeix.

---

### Taules de veritat

Una taula de veritat mostra el valor de veritat d'una fórmula per a **totes** les combinacions possibles dels seus àtoms — és la manera més directa de saber si una fórmula és certa, falsa, o depèn del cas.

**Passos per construir-ne una:**
1. Identifica els àtoms de la fórmula → cada un és una columna d'entrada ($2^n$ files en total, per a n àtoms)
2. Calcula primer les subfórmules més senzilles (columnes auxiliars) i ves construint cap a la fórmula completa, d'esquerra a dreta
3. `1` = certa, `0` = falsa

> | $\varphi$ | $\psi$ | $\neg\varphi$ | $\varphi\land\psi$ | $\varphi\lor\psi$ | $\varphi\rightarrow\psi$ | $\varphi\leftrightarrow\psi$ |
> |---|---|---|---|---|---|---|
> | 0 | 0 | 1 | 0 | 0 | 1 | 1 |
> | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
> | 1 | 0 | 0 | 0 | 1 | 0 | 0 |
> | 1 | 1 | 0 | 1 | 1 | 1 | 1 |

A $\varphi\rightarrow\psi$: $\varphi$ és l'**antecedent** (hipòtesi, premissa), $\psi$ és el **conseqüent** (tesi).

> **Maneres d'escriure $p\rightarrow q$** (totes diuen el mateix, i surten sovint redactades així als enunciats):
> Si p, aleshores q · q si p · p implica q · q es dedueix de p · una condició necessària per a p és q
>
> *Intuïció:* $p\rightarrow q$ és fals **només** quan `p` és cert i `q` és fals — com una promesa que només es trenca si es dona la condició i no es compleix el que es promet.

**Exemple resolt** — construïm pas a pas la taula de $\neg(p\rightarrow\neg r) \leftrightarrow (p\lor\neg q)$. Primer les columnes auxiliars ($\neg r$, $p\rightarrow\neg r$...), i al final la fórmula sencera:

| p | q | r | $\neg r$ | $p\rightarrow\neg r$ | $\neg(p\rightarrow\neg r)$ | $\neg q$ | $p\lor\neg q$ | resultat |
|---|---|---|---|---|---|---|---|---|
| 0 | 0 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 0 | 0 | 1 | 0 | 1 | 0 | 1 | 1 | 0 |
| 0 | 1 | 0 | 1 | 1 | 0 | 0 | 0 | 1 |
| 0 | 1 | 1 | 0 | 1 | 0 | 0 | 0 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 | 1 | 1 | 0 |
| 1 | 0 | 1 | 0 | 0 | 1 | 1 | 1 | 1 |
| 1 | 1 | 0 | 1 | 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 0 | 0 | 1 | 0 | 1 | 1 |

Segons com surt la columna final, una fórmula es classifica en:
- **Tautologia** — sempre certa (columna de `1`)
- **Contradicció** — sempre falsa (columna de `0`); també se'n diu *insatisfactible*
- **Satisfactible** — certa per a alguna assignació (conté algun `1`)

---

### Equivalència de fórmules

Dues fórmules diferents poden "voler dir el mateix". Formalment, $\varphi \equiv \psi$ quan tenen exactament la mateixa taula de veritat (mateix valor per a cada combinació d'àtoms). Com a conseqüència, totes les tautologies són equivalents entre si (es representen per `1`), i totes les contradiccions també ho són (`0`).

Comprovar-ho amb una taula de veritat sempre funciona, però es fa molt llarg amb moltes variables. Per això interessa poder-ho demostrar **sintàcticament**, encadenant propietats conegudes.

**Taula d'equivalències importants** (la columna dreta és la dual: n'hi ha prou canviant $\land \leftrightarrow \lor$ i $0 \leftrightarrow 1$):

| Nom | $\varphi$ | Dual |
|---|---|---|
| Distributiva | $\varphi\land(\psi\lor\theta)\equiv(\varphi\land\psi)\lor(\varphi\land\theta)$ | $\varphi\lor(\psi\land\theta)\equiv(\varphi\lor\psi)\land(\varphi\lor\theta)$ |
| De Morgan | $\neg(\varphi\land\psi)\equiv\neg\varphi\lor\neg\psi$ | $\neg(\varphi\lor\psi)\equiv\neg\varphi\land\neg\psi$ |
| Absorció | $\varphi\land(\varphi\lor\psi)\equiv\varphi$ | $\varphi\lor(\varphi\land\psi)\equiv\varphi$ |
| Idempotència | $\varphi\land\varphi\equiv\varphi$ | $\varphi\lor\varphi\equiv\varphi$ |
| Commutativa/Associativa | estàndard | estàndard |
| Neutre | $\varphi\land 1\equiv\varphi$ | $\varphi\lor 0\equiv\varphi$ |
| Elem. absorbent | $\varphi\lor 1\equiv 1$ | $\varphi\land 0\equiv 0$ |
| Complementari | $\varphi\lor\neg\varphi\equiv 1$ | $\varphi\land\neg\varphi\equiv 0$ |
| Doble negació | $\neg\neg\varphi\equiv\varphi$ | — |

**Traducció** (per eliminar $\rightarrow$ i $\leftrightarrow$ abans d'operar):
$\varphi\rightarrow\psi \equiv \neg\varphi\lor\psi$  ·  $\varphi\leftrightarrow\psi \equiv (\varphi\rightarrow\psi)\land(\psi\rightarrow\varphi) \equiv (\varphi\land\psi)\lor(\neg\varphi\land\neg\psi)$

**Recepta per demostrar una equivalència sintàcticament** (sense taula de veritat):
1. Substitueix $\rightarrow$ i $\leftrightarrow$ per la seva traducció (taula anterior)
2. Aplica **De Morgan** per entrar les negacions al màxim — *idea:* fica el $\neg$ dins del parèntesi i, en fer-ho, inverteix $\land \leftrightarrow \lor$
3. Aplica distributiva i les altres propietats bàsiques fins arribar a l'altra fórmula
4. Si el camí no és mecànic (p.ex. absorció), introdueix un pas intermedi artificial com $\land 1$ o $\lor\neg\varphi$

**Exemple resolt — Absorció** (cas no mecànic, mostra el pas 4 en acció):
```
p∧(p∨q) ≡[Neut] (p∧(p∨q))∧1 ≡[Compl] (p∧(p∨q))∧(p∨¬p) ≡[Ass,Distr]
p∧(p∨(q∧¬p)) ≡[Distr,Idem] p∨(p∧(¬p∧q)) ≡[Ass,Compl] p∨(0∧q) ≡[Elem.Abs,Neut] p
```

---

## 1.2 Lògica de Predicats

La lògica proposicional no pot expressar enunciats amb variables com $x>3$ o $x=y+3$: mentre no s'assigni un valor a `x` i `y`, no són ni certs ni falsos. La **lògica de predicats** (o de primer ordre, LPO) resol això.

$P(x)$: `P` és el **predicat** (la propietat), `x` és la variable/subjecte. Un cop s'assigna un valor a `x`, $P(x)$ esdevé una proposició amb valor de veritat.

Cada predicat té una **aritat**: quants individus relaciona.

| Aritat | Exemples (domini $\mathbb{Z}$) | Exemples (domini: alumnes de l'aula) |
|---|---|---|
| 1 | "ser parell", "ser múltiple de 4" | "ser alt", "portar ulleres" |
| 2 (binària, la més habitual en matemàtiques) | "ser menor que", "ser igual que" | "seure al costat de" |
| 3 | "x està entre y i z" | — |

---

### Fórmules atòmiques

> **Definició:** sigui `R` un símbol de relació d'aritat `n`, i $x_1,\ldots,x_n$ les `n` variables. Llavors $R(x_1,\ldots,x_n)$ és una **fórmula atòmica** — el bloc més bàsic amb què es construeixen les fórmules de LPO.

**Exemples** (`P` aritat 1, `Q` i `<` aritat 2, `R` aritat 3):
```
Aritat 1 → P(x)          Aritat 2 → Q(x,y)  ,  x<y          Aritat 3 → R(x,y,z)
```

> **Observacions:**
> 1. A les relacions binàries habituals s'usa notació **infixa**: $R(x,y)$ s'escriu $xRy$  ·  $<(x,y)$ s'escriu $x<y$  ·  $=(x,y)$ s'escriu $x=y$
> 2. En lloc de variables soltes hi poden aparèixer expressions més complicades ("termes"): $y^2+2 < 4$ també és una fórmula atòmica vàlida.

---

### Fórmules de LPO i quantificadors

Les fórmules de LPO es formen combinant les atòmiques amb $\land \lor \rightarrow \leftrightarrow \neg$ (igual que abans) i, a més, amb dos **quantificadors** nous:

- **$\forall$** (universal): $\forall x\, P(x)$ — la proposició `P(x)` és certa per a **tots** els valors `x` del domini
- **$\exists$** (existencial): $\exists x\, P(x)$ — **existeix (almenys) un** element `x` del domini pel qual `P(x)` és cert

> Si $\varphi$ és una fórmula i `x` una variable, $\forall x\, \varphi$ i $\exists x\, \varphi$ també són fórmules.

**Negar un quantificador el converteix en l'altre** (i la negació passa cap a dins):

$$\neg\forall x\, \varphi \equiv \exists x\, \neg\varphi \qquad \neg\exists x\, \varphi \equiv \forall x\, \neg\varphi$$

*Intuïció:* dir "no és cert que tothom compleixi $\varphi$" equival a dir "algú no compleix $\varphi$".

---

### Quantificadors niats

Un quantificador està **niat** quan es troba dins de l'abast (rang d'aplicació) d'un altre quantificador — és a dir, quan una fórmula en té més d'un, un darrere l'altre.

**Exemple** (domini $\mathbb{R}$):
- $\forall x \forall y\,(x+y=y+x)$ afirma la **commutativa de la suma** a $\mathbb{R}$
- $\forall x \exists y\,(x+y=0)$ "per a tot $x \in \mathbb{R}$, existeix un $y \in \mathbb{R}$ tal que $x+y=0$" (l'existència de l'oposat)

Quan els dos quantificadors són **iguals**, es poden intercanviar lliurement:

$$\forall x \forall y\, \varphi \equiv \forall y \forall x\, \varphi \qquad \exists x \exists y\, \varphi \equiv \exists y \exists x\, \varphi$$

> **Observacions:**
> 1. Per negar una frase amb quantificadors niats, s'aplica la negació **d'un en un**, de fora cap a dins (cada $\forall$ es converteix en $\exists$ i viceversa).
> 2. És habitual trobar sentències amb diverses variables i diversos quantificadors combinats.
>
> ⚠️ **Quan els quantificadors són diferents, l'ordre importa:** $\forall x \exists y\, \varphi \not\equiv \exists y \forall x\, \varphi$ en general.
> *Contraexemple (domini $\mathbb{N}$):* $\forall x \exists y\,(x<y)$ és certa ("per a tot número n'hi ha un de més gran"), però $\exists y \forall x\,(x<y)$ és falsa ("hi ha un número més gran que tots" — no existeix).
>
> Per la mateixa raó, un quantificador **no distribueix** sobre qualsevol connectiva: $\forall x\,(\varphi\lor\psi) \not\equiv \forall x\,\varphi \lor \forall x\,\psi$  ·  $\exists x\,(\varphi\land\psi) \not\equiv \exists x\,\varphi \land \exists x\,\psi$. Sí que ho fa quan coincideixen ($\forall$ amb $\land$, $\exists$ amb $\lor$): $\forall x\,(\varphi\land\psi)\equiv \forall x\,\varphi \land \forall x\,\psi$  ·  $\exists x\,(\varphi\lor\psi)\equiv \exists x\,\varphi \lor \exists x\,\psi$.

---

## Formalització
problemes 30 y 31 (pdf, pagina: 22)
### Notes de color
Negre=Teoria · Blau=LAB · Verd=resolt a Exercicis Resolts · `(R)`=recomanat
