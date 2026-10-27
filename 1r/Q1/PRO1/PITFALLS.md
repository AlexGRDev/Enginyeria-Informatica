# Errores recurrentes — PRO1

<!-- kiwi-gei:pitfalls:inici -->
## Contador de errores (Kiwi GEI)

Generado el 2026-10-27. Ordenado por número de veces: arriba, lo que más hay que reforzar.

| Patrón | Tema | Veces | Última vez | Cómo reforzar |
|---|---|---|---|---|
| No sabe abordar Funciones auxiliares | Funciones auxiliares | 10 | 2026-10-27 | Recorrido de dígitos con %10 y /10 contando cambios entre dígitos consecutivos. |
| No sabe abordar E/S con std::cin/std::cout | E/S con std::cin/std::cout | 9 | 2026-10-27 | Esquema cin >> c; while (c != '.') { ...; cin >> c; } con contador de racha. |
| No sabe abordar Tipos básicos | Tipos básicos | 8 | 2026-10-27 | Acumular valor += bit * peso; peso *= 2 y escribir char(valor) al leer '*'. |
| No documentar las funciones con especificación pre/post | Funciones auxiliares | 4 | 2026-10-27 | Escribir @pre y @post sobre cada función antes de implementarla. |
| Incumplir restricción explícita del enunciado | Tipos básicos | 1 | 2026-10-26 | Releer la sección Observació antes de elegir la representación; extraer dígitos con %10 y /10. |
| No sabe abordar Recursividad | Recursividad | 1 | 2026-10-26 | Practicar recursión sobre dígitos con caso base x==0 and y==0 y paso x/10, y/10. |
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
