# Errores recurrentes — PRO1

<!-- kiwi-gei:pitfalls:inici -->
## Contador de errores (Kiwi GEI)

Generado el 2026-10-28. Ordenado por número de veces: arriba, lo que más hay que reforzar.

| Patrón | Tema | Veces | Última vez | Cómo reforzar |
|---|---|---|---|---|
| No sabe abordar Funciones auxiliares | Funciones auxiliares | 16 | 2026-10-28 | Recorrido de dígitos con %10 y /10 contando cambios entre dígitos consecutivos. |
| No sabe abordar Tipos básicos | Tipos básicos | 14 | 2026-10-28 | Practicar la inversión de dígitos con %10 y /10 y la comparación con el original. |
| No sabe abordar E/S con std::cin/std::cout | E/S con std::cin/std::cout | 13 | 2026-10-28 | Esquema cin >> c; while (c != '.') { ...; cin >> c; } con contador de racha. |
| No documentar las funciones con especificación pre/post | Funciones auxiliares | 8 | 2026-10-28 | Escribir @pre y @post sobre cada función antes de implementarla. |
| No sabe abordar Recursividad | Recursividad | 4 | 2026-10-27 | Practicar recursión sobre dígitos con caso base x==0 and y==0 y paso x/10, y/10. |
| Uso incorrecto de punteros sobre variables escalares | Punteros y aritmética de punteros | 3 | 2026-10-28 | Usar variables enteras/char o vector con índices; reservar memoria dinámica solo cuando el enunciado lo pida. |
| Código redundante o innecesariamente complicado | E/S con std::cin/std::cout | 1 | 2026-10-28 | Ordenar una sola vez antes del bucle de escritura, o separar ordenar y escribir en funciones distintas. |
| Código redundante o innecesariamente complicado | Funciones auxiliares | 1 | 2026-10-28 | Leer los 5 caracteres de cada caso y resolver según la posición de la x. |
| Esquemas de lectura no recomendados | E/S con std::cin/std::cout | 1 | 2026-10-28 | Leer el primer carácter y luego el esquema del curso, procesando un caso completo por iteración. |
| Código redundante o innecesariamente complicado | Tipos básicos | 1 | 2026-10-28 | Devolver directamente la expresión booleana. |
| Código redundante o innecesariamente complicado | Cadenas estilo C (char*) | 1 | 2026-10-27 | Comparar caracteres sueltos directamente con == y no crear helpers para condiciones triviales. |
| Incumplir restricción explícita del enunciado | Tipos básicos | 1 | 2026-10-26 | Releer la sección Observació antes de elegir la representación; extraer dígitos con %10 y /10. |
| No aplicar diseño descendente | Funciones auxiliares | 1 | 2026-10-26 | Extraer una acción escriu(n, c) que escriba n veces un carácter. |
| Guardar una secuencia en un vector cuando no hace falta | Tipos básicos | 1 | 2026-10-26 | Calcular el dígito con 9 - (cont % 10) y llevar un solo contador. |
| No sabe abordar std::string | std::string | 1 | 2026-10-26 | Comparar c1, c2, c3 entre sí y devolver el string según los casos. |
| Código que no compila por descuido de sintaxis | Tipos básicos | 1 | 2026-10-25 | Compilar antes de entregar y escribir comillas rectas. |
<!-- kiwi-gei:pitfalls:fi -->

| Fecha | Ejercicio | Error | Corrección |
|---|---|---|---|
| 2026-09-11 | P42042 | `ft_strchr` con doble puntero: avanzaba el puntero (`ptrs++`) sin desreferenciarlo y devolvía `s` (el puntero original) en vez de la posición encontrada. | Avanzar con `(*ptrs)++` y devolver `(char *)*ptrs`. |
| 2026-09-11 | P42042 | Cadena de vocales `"aeiou"` no incluía mayúsculas → clasificaba mal las vocales en mayúscula. | Cambiar a `"aeiouAEIOU"`. |
| 2026-09-13 | P42042, P98960 | `malloc(sizeof(char))` para leer un único carácter con `std::cin >> *a` fallaba/no era suficiente en la práctica. | Cambiado a `malloc(sizeof(std::string) + 1)` — revisar si es la corrección idónea o sobreingeniería (reservar `sizeof(std::string)` para un solo `char` es más memoria de la necesaria; posible mejor fix: `malloc(2 * sizeof(char))` o revisar la causa real del fallo). |
