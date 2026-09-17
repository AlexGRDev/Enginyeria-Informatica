# 🎓 Enginyeria Informàtica

Anuari i repositori central amb tots els exercicis, pràctiques, apunts i projectes desenvolupats al llarg del Grau en Enginyeria Informàtica (GEI, FIB-UPC).

---

## 📂 Estructura del Repositori

El repositori està organitzat per cursos i quadrimestres per facilitar la navegació pels continguts de cada assignatura:

```text
.
├── 1r/
│   └── Q1/                     # Primer Quadrimestre
│       ├── PRO1/                # Programació 1 (Exercicis Jutge.org: P_, X_)
│       ├── F/                   # Física
│       ├── FM/                  # Fonaments Matemàtics
│       └── IC/                  # Introducció als Computadors
│
├── Admin/                       # Horari i configuracions generals
├── CLAUDE.md                    # Guia de treball per a Claude Code en aquest repo
├── LICENSE.md
└── README.md
```

Cada carpeta d'assignatura (`PRO1/`, `F/`, `FM/`, `IC/`) segueix el patró `{ejercicios,material,teoria}` i conté 3 arxius canario a la seva arrel:

| Arxiu | Contingut | Freqüència d'actualització |
| :--- | :--- | :--- |
| `CONTEXT.md` | Temari, convencions d'estil/codi, regles del jutge (Jutge.org, SISA), dates clau | Només si canvia el temari o les regles oficials |
| `STATE.md` | Què s'ha donat a classe, exercicis resolts vs pendents, proper examen | Cada sessió de treball |
| `PITFALLS.md` | Taula d'errors recurrents (data, exercici, error, correcció) | Cada sessió de treball |

---
## 📊 Estat del Progrés

| Curs | Quadrimestre | Assignatura | Codi | Estat | Tecnologies |
| :---: | :---: | :--- | :---: | :---: | :---: |
| **1r** | Q1 | Programació 1 | `PRO1` | 🔄 En curs — 16 exercicis resolts (P_/X_) | `C++` `Clang++17` |
| **1r** | Q1 | Física | `F` | 🔄 En curs — teoria (Corrent Continu) | `TeX` |
| **1r** | Q1 | Fonaments Matemàtics | `FM` | 🔄 En curs — Lògica i Demostracions, Sumatoris (3/9) | `MATLAB` |
| **1r** | Q1 | Introducció als Computadors | `IC` | 🔄 En curs — teoria (Representació de Naturals, Combinacionals) | `Assembly` `C` |

Detall actualitzat per assignatura a cada `STATE.md` (veure taula d'estructura).

### Exàmens (curs 2026-2027, horari oficial racó FIB)

| Assignatura | Parcial | Final | Recuperació |
| :--- | :--- | :--- | :--- |
| PRO1 | 29/10/2026 | 08/01/2027 | 06/02/2027 |
| IC | 30/10/2026 i 21/12/2026 | 12/01/2027 | 06/02/2027 |
| FM | 04/11/2026 i 22/12/2026 | 14/01/2027 | 06/02/2027 |
| F | 03/11/2026 i 23/12/2026 | 18/01/2027 | — |

---

## 🚀 Metodologia de Treball & Commits

Per mantenir un historial net i professional, en aquest repositori se segueix l'estàndard de la indústria **Conventional Commits**:

- `feat(scope)`: Per a noves pràctiques o exercicis completats (ex: `feat(P98960): add solution`).
- `fix(scope)`: Correccions de codi o bugs detectats pel Jutge.
- `docs(scope)`: Canvis en la documentació, enunciats o comentaris.
- `del(scope)`: Eliminació de fitxers obsolets, duplicats o binaris.
- `refactor(scope)`: Reestructuració de carpetes o neteja de codi sense alterar la seva lògica.

---

## 🧪 My Own Tests

Per assegurar que les solucions funcionen correctament davant de qualsevol cas extrem (*edge case*) abans de pujar-les al Jutge, faig servir un sistema de validació local mitjançant la redirecció de fitxers de text:

```bash
# 1. Compilar el programa
clang++ -Wall -Wextra -fsanitize=address,undefined -O0 P98960.cpp -o solution

# 2. Executar passant un fitxer de test d'entrada propi
./solution < my_input.txt > my_output.txt

# 3. Comprovar de forma automàtica si la sortida és la correcta
diff my_output.txt my_expected.txt
```

---

## 🔧 Eines Utilitzades

- **Compilador:** `Clang++17`
- **Control de Versions:** `Git` / `GitHub`
- **Plataformes de Testing:** [Jutge.org](https://jutge.org)

---

## 📜 Llicència

Aquest repositori es publica sota una llicència d'ús personal i acadèmic — veure [LICENSE.md](LICENSE.md). En resum: contingut de seguiment personal, sense cap garantia, i es demana respectar l'honestedat acadèmica de la universitat a l'hora de consultar les solucions dels exercicis.
