# Informe previo Práctica-1

Apellidos y nombre: Garcia Rodriguez Alex

Grupo: 51

---

## Pregunta 1

Tabla de valores para el circuito Xor-2 en suma de minterms, con $m_0(x,y)=\overline{x}\,\overline{y}$, $m_1(x,y)=\overline{x}y$, $m_2(x,y)=x\overline{y}$, $m_3(x,y)=xy$:

$$
\begin{array}{|c|c|c|c|c|c|c|c|c|}
\hline
x & y & \overline{x} & \overline{y} & m_0 & m_1 & m_2 & m_3 & m_1+m_2 \\
\hline
0 & 0 & 1 & 1 & 1 & 0 & 0 & 0 & 0 \\
0 & 1 & 1 & 0 & 0 & 1 & 0 & 0 & 1 \\
1 & 0 & 0 & 1 & 0 & 0 & 1 & 0 & 1 \\
1 & 1 & 0 & 0 & 0 & 0 & 0 & 1 & 0 \\
\hline
\end{array}
$$

*(Se comprueba que $m_1+m_2 = \overline{x}y+x\overline{y}$ coincide exactamente con la tabla de verdad de la función Xor-2.)*

---

## Pregunta 2

Cronogramas del circuito Xor-2 en suma de minterms ($N1=\text{Not-1}(x)\to\overline{x}$, $N2=\text{Not-1}(y)\to\overline{y}$, $A1=\text{And-2}(\overline{x},y)\to m_1$, $A2=\text{And-2}(x,\overline{y})\to m_2$, $O1=\text{Or-2}(m_1,m_2)\to w$), con retardos Not-1 = 10 u.t., And-2 = 20 u.t., Or-2 = 20 u.t. El instante $t=0$ es el momento en que cambian las entradas $x$ e $y$. Al no poder dibujarse un cronograma a mano en este formato, se representa como tabla de tiempos de transición por señal.

### Caso a: $(x,y)$ pasa de $(1,0)$ a $(0,1)$, ambas a $t=0$

$$
\begin{array}{|c|c|c|c|}
\hline
\text{Señal} & \text{Valor inicial} & \text{Instante(s) de cambio} & \text{Valor(es) tras cambio} \\
\hline
x & 1 & t=0 & 0 \\
y & 0 & t=0 & 1 \\
\overline{x} & 0 & t=10 & 1 \\
\overline{y} & 1 & t=10 & 0 \\
m_1 & 0 & t=30 & 1 \\
m_2 & 1 & t=20 & 0 \\
w & 1 & \text{(sin cambio)} & 1 \\
\hline
\end{array}
$$

Razonamiento (modelo de retardo de transporte: cada cambio de entrada en una puerta programa un cambio de salida esa puerta-delay después; si llegan varios cambios de entrada en momentos distintos, cada uno dispara su propio evento de salida):

- $x$: $1\to0$ en $t=0$; $y$: $0\to1$ en $t=0$.
- $\overline{x}$: $0\to1$ en $t=10$ (retardo Not-1 desde el cambio de $x$); $\overline{y}$: $1\to0$ en $t=10$ (retardo Not-1 desde el cambio de $y$).
- $m_1=\overline{x}\cdot y$: valor inicial 0 (antes del cambio, $x,y=(1,0)$, así que $\overline{x}=0,y=0$). El único cambio de entrada relevante es $\overline{x}$ ($0\to1$) en $t=10$, ya que $y$ ya valía 1 desde $t=0$ sin provocar cambio (mientras $\overline{x}$ seguía en 0, $m_1$ seguía en 0). $m_1$ cambia 20 u.t. después de $t=10$: $m_1$ pasa de $0\to1$ en $t=30$.
- $m_2=x\cdot\overline{y}$: valor inicial 1 ($x=1,\overline{y}=1$). $x$ cambia $1\to0$ en $t=0$, por lo que $m_2$ cambia 20 u.t. después: $m_2$ pasa de $1\to0$ en $t=20$. ($\overline{y}$ cambia después, en $t=10$, pero $x$ ya vale 0, así que no provoca cambio adicional: el AND ya está en 0.)
- $w=m_1+m_2$: valor inicial $= m_1(0)+m_2(1) = 1$. Valor final $= m_1(1)+m_2(0) = 1$. **No hay cambio neto en $w$, permanece en 1 durante todo el intervalo** (los dos minterms "se turnan" el valor 1 sin solaparse en 0, por eso no hay glitch visible en este caso; el evento de $m_2\to0$ en $t=20$ y el evento de $m_1\to1$ en $t=30$ llegan a la puerta Or-2, pero el resultado combinacional final tras ambos eventos coincide con el inicial, por lo que el cambio programado en la Or-2 queda anulado por el segundo evento antes de manifestarse).

### Caso b: $(x,y)$ pasa de $(0,0)$ a $(1,1)$, ambas a $t=0$

$$
\begin{array}{|c|c|c|c|}
\hline
\text{Señal} & \text{Valor inicial} & \text{Instante(s) de cambio} & \text{Valor(es) tras cambio} \\
\hline
x & 0 & t=0 & 1 \\
y & 0 & t=0 & 1 \\
\overline{x} & 1 & t=10 & 0 \\
\overline{y} & 1 & t=10 & 0 \\
m_1 & 0 & t=20\ (\to1),\ t=30\ (\to0) & 1\ \text{(glitch)},\ \text{luego } 0 \\
m_2 & 0 & t=20\ (\to1),\ t=30\ (\to0) & 1\ \text{(glitch)},\ \text{luego } 0 \\
w & 0 & t=40\ (\to1),\ t=50\ (\to0) & 1\ \text{(glitch)},\ \text{luego } 0 \\
\hline
\end{array}
$$

Razonamiento:

- $x$: $0\to1$ en $t=0$; $y$: $0\to1$ en $t=0$.
- $\overline{x}$: $1\to0$ en $t=10$; $\overline{y}$: $1\to0$ en $t=10$.
- $m_1=\overline{x}\cdot y$: en $t=0$, $y$ pasa a 1 mientras $\overline{x}$ aún vale 1 (valor viejo) $\to$ entrada combinacional $(\overline{x},y)$ pasa de $(1,0)$ a $(1,1)$, evento And-2 programado: $m_1$ pasa de $0\to1$ en $t=0+20=20$. En $t=10$, $\overline{x}$ pasa a 0 $\to$ entrada pasa a $(0,1)$, evento And-2 programado: $m_1$ pasa de $1\to0$ en $t=10+20=30$. Resultado: $m_1=0$ hasta $t=20$, $1$ entre $t=20$ y $t=30$ (glitch/pulso), $0$ desde $t=30$.
- $m_2=x\cdot\overline{y}$: simétrico. En $t=0$, $x$ pasa a 1 con $\overline{y}$ aún en 1 $\to$ evento And-2: $m_2$ pasa de $0\to1$ en $t=20$. En $t=10$, $\overline{y}$ pasa a 0 $\to$ evento And-2: $m_2$ pasa de $1\to0$ en $t=30$. Resultado: $m_2=0$ hasta $t=20$, $1$ entre $t=20$ y $t=30$ (glitch/pulso), $0$ desde $t=30$ (idéntico a $m_1$).
- $w=m_1+m_2$: como $m_1$ y $m_2$ son señales idénticas, los eventos que llegan a la Or-2 son: en $t=20$, entradas $(m_1,m_2)$ pasan de $(0,0)$ a $(1,1)$ $\to$ evento Or-2: $w$ pasa de $0\to1$ en $t=20+20=40$. En $t=30$, entradas pasan a $(0,0)$ $\to$ evento Or-2: $w$ pasa de $1\to0$ en $t=30+20=50$. Resultado: $w=0$ hasta $t=40$, $1$ entre $t=40$ y $t=50$ (glitch/pulso), $0$ desde $t=50$.

Valor inicial y final de $w$ coinciden ($0\to0$, $\text{XOR}(0,0)=\text{XOR}(1,1)=0$): **no hay cambio neto, pero sí un glitch transitorio**, que es justamente el fenómeno que el enunciado anticipa en la sección 1.2.3 del PDF ("para algunos casos en los que la salida no debería cambiar se produce un glitch").

---

## Pregunta 3

### a) Caminos posibles de la entrada $x$ a la salida $w$

- **Camino 1:** $x \to N1\,(\text{Not-1}) \to A1\,(\text{And-2}) \to O1\,(\text{Or-2}) \to w$. $T_p = 10+20+20 = 50$ u.t.
- **Camino 2:** $x \to A2\,(\text{And-2}) \to O1\,(\text{Or-2}) \to w$ ($x$ entra directo al And-2 de $m_2$, sin pasar por ninguna Not). $T_p = 20+20 = 40$ u.t.
- **Camino crítico:** Camino 1 (vía $N1, A1, O1$), porque tiene mayor retardo ($50 > 40$ u.t.); el camino crítico entre dos puntos es siempre el de mayor tiempo de propagación entre todos los caminos posibles.

### b) Tiempos de propagación $T_{px-w}$ y $T_{py-w}$

$$T_{px-w} = 50 \text{ u.t.}$$

$$T_{py-w} = 50 \text{ u.t.}$$

El camino crítico de $y$ a $w$, vía $N2 \to A2 \to O1$, ya está resuelto como ejemplo en el propio PDF (sección 1.2.3): $T_{p1} = T_p(N2) + T_p(A2) + T_p(O1) = 10+20+20 = 50$ u.t., frente al otro camino $y \to A1 \to O1$ con $T_{p2} = 20+20 = 40$ u.t.

### c) Tiempo de propagación del circuito completo

$$T_p(\text{circuito}) = \max(T_{px-w}, T_{py-w}) = 50 \text{ u.t.}$$

El tiempo de propagación del circuito es el máximo de los tiempos de propagación de todas las parejas entrada-salida.

---

## Pregunta 4

### a) Expresiones en suma de minterms del Half-adder

A partir de su tabla de verdad ($(x,y)=(0,0)\to c=0,s=0$; $(0,1)\to c=0,s=1$; $(1,0)\to c=0,s=1$; $(1,1)\to c=1,s=0$):

$$c = x \cdot y \quad (\text{minterm } m_3)$$

$$s = \overline{x} \cdot y + x \cdot \overline{y} \quad (\text{minterms } m_1 + m_2)$$

*Nota: $s$ es exactamente la función Xor-2 ya diseñada en la sección 1.2 (coincide con $w$ del apartado anterior), y $c$ es una única puerta And-2 directa sobre $x,y$.*

### b) Descripción del esquema del circuito Half-adder en suma de minterms

Al no poder dibujarse a mano en este formato, se describe con precisión suficiente para pasarlo al PDF a mano:

- Reutiliza exactamente el subcircuito Xor-2 ya diseñado ($N1=\text{Not-1}(x)\to\overline{x}$, $N2=\text{Not-1}(y)\to\overline{y}$, $A1=\text{And-2}(\overline{x},y)\to m_1$, $A2=\text{And-2}(x,\overline{y})\to m_2$, $O1=\text{Or-2}(m_1,m_2)$) para obtener la salida $s = w$.
- Añade una puerta adicional $A3=\text{And-2}(x,y)$ con las entradas $x$ e $y$ conectadas directamente (sin pasar por ninguna Not), cuya salida es directamente $c$.
- En total: 2 puertas Not-1 ($N1$, $N2$), 3 puertas And-2 ($A1$, $A2$, $A3$), 1 puerta Or-2 ($O1$).

---

## Pregunta 5

Retardos para este apartado (distintos a los de la Pregunta 2): Not-1 = 1 u.t., And-2 = 3 u.t., Or-2 = 3 u.t.

### a) Caminos críticos (usando los nombres de puerta de la Pregunta 4b)

- **Camino crítico $x$-$c$:** $x \to A3 \to c$ (único camino posible, $A3$ conecta $x$ directamente).
- **Camino crítico $x$-$s$:** $x \to N1 \to A1 \to O1 \to s$ (más largo que la alternativa $x \to A2 \to O1 \to s$, que vale $3+3=6$ u.t. frente a $1+3+3=7$ u.t. de este camino).
- **Camino crítico $y$-$c$:** $y \to A3 \to c$ (único camino posible).
- **Camino crítico $y$-$s$:** $y \to N2 \to A2 \to O1 \to s$ (más largo que la alternativa $y \to A1 \to O1 \to s$, que vale $3+3=6$ u.t. frente a $1+3+3=7$ u.t.).

### b) Tiempos de propagación

$$T_{x-c} = 3 \text{ u.t.} \qquad T_{x-s} = 7 \text{ u.t.}$$

$$T_{y-c} = 3 \text{ u.t.} \qquad T_{y-s} = 7 \text{ u.t.}$$
