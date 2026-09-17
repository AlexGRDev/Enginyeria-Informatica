# Informe previo Práctica-0

**Apellidos y nombre:** Garcia Rodriguez, Alex
**Grupo:** <span style="color:blue">51</span>

## Pregunta 1

Escribid el valor en decimal que representan, según el sistema binario, cada uno de los siguientes vectores de bits:

a) 10011101 → Xu = <span style="color:blue">157</span>
b) 1100000011100001 → Xu = <span style="color:blue">49377</span>
c) 0000000000101010 → Xu = <span style="color:blue">42</span>

## Pregunta 2

| Vector de bits X = x3 x2 x1 x0 | Valor Xu |
|---|---|
| <span style="color:blue">0000</span> | 0 |
| <span style="color:blue">0001</span> | 1 |
| <span style="color:blue">0010</span> | 2 |
| <span style="color:blue">0011</span> | 3 |
| <span style="color:blue">0100</span> | 4 |
| <span style="color:blue">0101</span> | 5 |
| <span style="color:blue">0110</span> | 6 |
| <span style="color:blue">0111</span> | 7 |
| <span style="color:blue">1000</span> | 8 |
| <span style="color:blue">1001</span> | 9 |
| <span style="color:blue">1010</span> | 10 |
| <span style="color:blue">1011</span> | 11 |
| <span style="color:blue">1100</span> | 12 |
| <span style="color:blue">1101</span> | 13 |
| <span style="color:blue">1110</span> | 14 |
| <span style="color:blue">1111</span> | 15 |

## Pregunta 3

**Not**

| x | w |
|---|---|
| 0 | <span style="color:blue">1</span> |
| 1 | <span style="color:blue">0</span> |

**And**

| x | y | w |
|---|---|---|
| 0 | 0 | <span style="color:blue">0</span> |
| 0 | 1 | <span style="color:blue">0</span> |
| 1 | 0 | <span style="color:blue">0</span> |
| 1 | 1 | <span style="color:blue">1</span> |

**Or**

| x | y | w |
|---|---|---|
| 0 | 0 | <span style="color:blue">0</span> |
| 0 | 1 | <span style="color:blue">1</span> |
| 1 | 0 | <span style="color:blue">1</span> |
| 1 | 1 | <span style="color:blue">1</span> |

## Pregunta 4

Circuito C-P0: a = !x, b = !y, c = a+b, d = x·b, e = y·c, w = d+e.

**a)**

| x | y | a | b | c | d | e | w |
|---|---|---|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 1 | 0 | 0 | 0 |
| 0 | 1 | <span style="color:blue">1</span> | <span style="color:blue">0</span> | <span style="color:blue">1</span> | <span style="color:blue">0</span> | <span style="color:blue">1</span> | <span style="color:blue">1</span> |
| 1 | 0 | <span style="color:blue">0</span> | <span style="color:blue">1</span> | <span style="color:blue">1</span> | <span style="color:blue">1</span> | <span style="color:blue">0</span> | <span style="color:blue">1</span> |
| 1 | 1 | <span style="color:blue">0</span> | <span style="color:blue">0</span> | <span style="color:blue">0</span> | <span style="color:blue">0</span> | <span style="color:blue">0</span> | <span style="color:blue">0</span> |

**b)** Tabla de verdad del circuito C-P0:

| x | y | w |
|---|---|---|
| 0 | 0 | <span style="color:blue">0</span> |
| 0 | 1 | <span style="color:blue">1</span> |
| 1 | 0 | <span style="color:blue">1</span> |
| 1 | 1 | <span style="color:blue">0</span> |

## Pregunta 5

| x | y | !x | !y | !x+!y | !yx | (!x+!y)y | w |
|---|---|---|---|---|---|---|---|
| 0 | 0 | 1 | 1 | 1 | <span style="color:blue">0</span> | <span style="color:blue">0</span> | <span style="color:blue">0</span> |
| 0 | 1 | 1 | 0 | 1 | <span style="color:blue">0</span> | <span style="color:blue">1</span> | <span style="color:blue">1</span> |
| 1 | 0 | 0 | 1 | 1 | <span style="color:blue">1</span> | <span style="color:blue">0</span> | <span style="color:blue">1</span> |
| 1 | 1 | 0 | 0 | 0 | <span style="color:blue">0</span> | <span style="color:blue">0</span> | <span style="color:blue">0</span> |

La tabla de verdad de 4a y 5 coinciden (columna w: 0,1,1,0 en ambas), como pide el enunciado.
