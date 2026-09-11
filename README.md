# 🎓 Enginyeria Informàtica

Anuari i repositori central amb tots els exercicis, pràctiques, apunts i projectes desenvolupats al llarg del Grau en Enginyeria Informàtica.

---

## 📂 Estructura del Repositori

El repositori està organitzat per cursos i quadrimestres per facilitar la navegació pels continguts de cada assignatura:

```text
.
├── 1r/
│   ├── Q1/                 # Primer Quadrimestre
│   │   ├── PRO1/           # Programació 1 (Exercicis Jutge.org, P_, X_)
│   │   ├── F/              # Física
│   │   ├── FM/             # Fonaments Matematics
│   │   └── IC/             # Introducion als Computadors
│
├── Admin/                  # Configuracions generals i scripts utilitaris
└── README.md
```

---
## 📊 Estat del Progrés

| Curs | Quadrimestre | Assignatura | Codi | Estat | Tecnologies |
| :---: | :---: | :--- | :---: | :---: | :---: |
| **1r** | Q1 | Programació 1 | `PRO1` | 🔄 En curs | `C++` `Clang++17` |
| **1r** | Q1 | Física | `F` | 🔄 En curs | `TeX` |
| **1r** | Q1 | fundaments Matematics | `FM` | 🔄 En curs | `MATLAB` |
| **1r** | Q1 | Introducio als Computadors | `IC` | 🔄 En curs | `Assembly` `C` |


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

Aquest repositori s'ha creat amb finalitats estrictament acadèmiques i de seguiment personal. S'agraeix respectar l'honestedat acadèmica de la universitat a l'hora de consultar les solucions dels exercicis.

