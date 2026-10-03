# Informe previo Práctica-0

Apellidos y nombre: Garcia Rodriguez Alex

Grupo: 51

---

## Pregunta 1

Indica el valor en decimal ($X_u$) de los siguientes vectores de bits:

### a) $10011101_2$

$$
\begin{array}{|c|c|c|c|}
\hline
\text{Posición } (2^n) & \text{Bit} & \text{Valor decimal} & \text{Contribución} \\
\hline
2^7 & 1 & 128 & 128 \\
2^6 & 0 & 64 & 0 \\
2^5 & 0 & 32 & 0 \\
2^4 & 1 & 16 & 16 \\
2^3 & 1 & 8 & 8 \\
2^2 & 1 & 4 & 4 \\
2^1 & 0 & 2 & 0 \\
2^0 & 1 & 1 & 1 \\
\hline
\end{array}
$$

$$\text{Cálculo: } 128 + 16 + 8 + 4 + 1 = 157$$

**$X_u = 157$**

---

### b) $1100000011100001_2$

$$
\begin{array}{|c|c|c|c|}
\hline
\text{Posición } (2^n) & \text{Bit} & \text{Valor decimal} & \text{Contribución} \\
\hline
2^{15} & 1 & 32768 & 32768 \\
2^{14} & 1 & 16384 & 16384 \\
2^{13} & 0 & 8192 & 0 \\
2^{12} & 0 & 4096 & 0 \\
2^{11} & 0 & 2048 & 0 \\
2^{10} & 0 & 1024 & 0 \\
2^9 & 0 & 512 & 0 \\
2^8 & 0 & 256 & 0 \\
2^7 & 1 & 128 & 128 \\
2^6 & 1 & 64 & 64 \\
2^5 & 1 & 32 & 32 \\
2^4 & 0 & 16 & 0 \\
2^3 & 0 & 8 & 0 \\
2^2 & 0 & 4 & 0 \\
2^1 & 0 & 2 & 0 \\
2^0 & 1 & 1 & 1 \\
\hline
\end{array}
$$

$$\text{Cálculo: } 32768 + 16384 + 128 + 64 + 32 + 1 = 49377$$

**$X_u = 49377$**

---

### c) $0000000000101010_2$

$$
\begin{array}{|c|c|c|c|}
\hline
\text{Posición } (2^n) & \text{Bit} & \text{Valor decimal} & \text{Contribución} \\
\hline
2^{15} & 0 & 32768 & 0 \\
2^{14} & 0 & 16384 & 0 \\
2^{13} & 0 & 8192 & 0 \\
2^{12} & 0 & 4096 & 0 \\
2^{11} & 0 & 2048 & 0 \\
2^{10} & 0 & 1024 & 0 \\
2^9 & 0 & 512 & 0 \\
2^8 & 0 & 256 & 0 \\
2^7 & 0 & 128 & 0 \\
2^6 & 0 & 64 & 0 \\
2^5 & 1 & 32 & 32 \\
2^4 & 0 & 16 & 0 \\
2^3 & 1 & 8 & 8 \\
2^2 & 0 & 4 & 0 \\
2^1 & 1 & 2 & 2 \\
2^0 & 0 & 1 & 0 \\
\hline
\end{array}
$$

$$\text{Cálculo: } 32 + 8 + 2 = 42$$

**$X_u = 42$**

---

## Pregunta 2

Completa la columna del vector de bits $(x_3 \, x_2 \, x_1 \, x_0)$ correspondiente a cada valor $X_u$.

$$
\begin{array}{|c|c|}
\hline
\text{Vector de bits } (x_3 \, x_2 \, x_1 \, x_0) & \text{Valor } X_u \\
\hline
0000 & 0 \\
0001 & 1 \\
0010 & 2 \\
0011 & 3 \\
0100 & 4 \\
0101 & 5 \\
0110 & 6 \\
0111 & 7 \\
1000 & 8 \\
1001 & 9 \\
1010 & 10 \\
1011 & 11 \\
1100 & 12 \\
1101 & 13 \\
1110 & 14 \\
1111 & 15 \\
\hline
\end{array}
$$

---

## Pregunta 3

Completa las tablas de verdad de las puertas básicas.

### Not

$$
\begin{array}{|c|c|}
\hline
x & w \\
\hline
0 & 1 \\
1 & 0 \\
\hline
\end{array}
$$

### And

$$
\begin{array}{|c|c|c|}
\hline
x & y & w \\
\hline
0 & 0 & 0 \\
0 & 1 & 0 \\
1 & 0 & 0 \\
1 & 1 & 1 \\
\hline
\end{array}
$$

### Or

$$
\begin{array}{|c|c|c|}
\hline
x & y & w \\
\hline
0 & 0 & 0 \\
0 & 1 & 1 \\
1 & 0 & 1 \\
1 & 1 & 1 \\
\hline
\end{array}
$$

---

## Pregunta 4

### Análisis del circuito por señales intermedias

Ecuaciones de las señales del circuito $C\text{-}P0$:
* $a = \overline{x}$
* $b = \overline{y}$
* $c = a + b = \overline{x} + \overline{y}$
* $d = b \cdot x = \overline{y} \cdot x$
* $e = c \cdot y = (\overline{x} + \overline{y}) \cdot y = \overline{x}\cdot y + \overline{y}\cdot y = \overline{x}y + 0 = \overline{x}y$
* $w = d + e = \overline{y}x + \overline{x}y$

#### a) Tabla de valores intermedios del circuito

$$
\begin{array}{|c|c|c|c|c|c|c|c|}
\hline
x & y & a & b & c & d & e & w \\
\hline
0 & 0 & 1 & 1 & 1 & 0 & 0 & 0 \\
0 & 1 & 1 & 0 & 1 & 0 & 1 & 1 \\
1 & 0 & 0 & 1 & 1 & 1 & 0 & 1 \\
1 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
\hline
\end{array}
$$

#### Justificación paso a paso por filas:
* **Fila 1 ($x=0, y=0$):**
  * $a = \overline{0} = 1$, $b = \overline{0} = 1$
  * $c = a + b = 1 + 1 = 1$
  * $d = b \cdot x = 1 \cdot 0 = 0$
  * $e = c \cdot y = 1 \cdot 0 = 0$
  * $w = d + e = 0 + 0 = 0$

* **Fila 2 ($x=0, y=1$):**
  * $a = \overline{0} = 1$, $b = \overline{1} = 0$
  * $c = a + b = 1 + 0 = 1$
  * $d = b \cdot x = 0 \cdot 0 = 0$
  * $e = c \cdot y = 1 \cdot 1 = 1$
  * $w = d + e = 0 + 1 = 1$

* **Fila 3 ($x=1, y=0$):**
  * $a = \overline{1} = 0$, $b = \overline{0} = 1$
  * $c = a + b = 0 + 1 = 1$
  * $d = b \cdot x = 1 \cdot 1 = 1$
  * $e = c \cdot y = 0 \cdot 0 = 0$
  * $w = d + e = 1 + 0 = 1$

* **Fila 4 ($x=1, y=1$):**
  * $a = \overline{1} = 0$, $b = \overline{1} = 0$
  * $c = a + b = 0 + 0 = 0$
  * $d = b \cdot x = 0 \cdot 1 = 0$
  * $e = c \cdot y = 0 \cdot 1 = 0$
  * $w = d + e = 0 + 0 = 0$

---

#### b) Tabla resumen del circuito $C\text{-}P0$

$$
\begin{array}{|c|c|c|}
\hline
x & y & w \\
\hline
0 & 0 & 0 \\
0 & 1 & 1 \\
1 & 0 & 1 \\
1 & 1 & 0 \\
\hline
\end{array}
$$

*(Nota: Como se observa, el circuito $C\text{-}P0$ equivale operacionalmente a una puerta lógica **OR**).*

---

## Pregunta 5

Análisis mediante evaluación por columnas de la expresión lógica:

$$w = \overline{y}x + (\overline{x} + \overline{y})y$$

$$
\begin{array}{|c|c|c|c|c|c|c|c|}
\hline
x & y & !x & !y & !x+!y & !yx & (!x+!y)y & w \\
\hline
0 & 0 & 1 & 1 & 1 & 0 & 0 & 0 \\
0 & 1 & 1 & 0 & 1 & 0 & 1 & 1 \\
1 & 0 & 0 & 1 & 1 & 1 & 0 & 1 \\
1 & 1 & 0 & 0 & 0 & 0 & 0 & 0 \\
\hline
\end{array}
$$

#### Verificación algebraicamente simplificada:

$$w = \overline{y}x + (\overline{x} + \overline{y})y$$
$$w = \overline{y}x + \overline{x}y + \overline{y}y$$
$$w = \overline{y}x + \overline{x}y + 0$$
$$w = \overline{y}x + \overline{x}y = x \oplus y \quad \text{(Suma XOR)}$$

*A la vista de la tabla de la Pregunta 5, comprobamos que los resultados de $w$ son exactos a los obtenidos en las preguntas 4a y 4b: $\{0, 1, 1, 0\}$.*

