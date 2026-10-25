# Errores recurrentes — PRO1

<!-- kiwi-gei:pitfalls:inici -->
## Contador de errores (Kiwi GEI)

Generado el 2026-10-25. Ordenado por número de veces: arriba, lo que más hay que reforzar.

| Patrón | Tema | Veces | Última vez | Cómo reforzar |
|---|---|---|---|---|
| No sabe abordar E/S con std::cin/std::cout | E/S con std::cin/std::cout | 4 | 2026-10-25 | Esquema cin >> c; while (c != '.') { ...; cin >> c; } con contador de racha. |
| No sabe abordar Tipos básicos | Tipos básicos | 3 | 2026-10-25 | Comparar a/b y c/d con a*d y c*b, y simplificar con gcd al imprimir. |
| No sabe abordar Funciones auxiliares | Funciones auxiliares | 2 | 2026-10-25 | Recorrido de dígitos con %10 y /10 contando cambios entre dígitos consecutivos. |
| Código que no compila por descuido de sintaxis | Tipos básicos | 1 | 2026-10-25 | Compilar antes de entregar y escribir comillas rectas. |
<!-- kiwi-gei:pitfalls:fi -->

| Fecha | Ejercicio | Error | Corrección |
|---|---|---|---|
| 2026-09-11 | P42042 | `ft_strchr` con doble puntero: avanzaba el puntero (`ptrs++`) sin desreferenciarlo y devolvía `s` (el puntero original) en vez de la posición encontrada. | Avanzar con `(*ptrs)++` y devolver `(char *)*ptrs`. |
| 2026-09-11 | P42042 | Cadena de vocales `"aeiou"` no incluía mayúsculas → clasificaba mal las vocales en mayúscula. | Cambiar a `"aeiouAEIOU"`. |
| 2026-09-13 | P42042, P98960 | `malloc(sizeof(char))` para leer un único carácter con `std::cin >> *a` fallaba/no era suficiente en la práctica. | Cambiado a `malloc(sizeof(std::string) + 1)` — revisar si es la corrección idónea o sobreingeniería (reservar `sizeof(std::string)` para un solo `char` es más memoria de la necesaria; posible mejor fix: `malloc(2 * sizeof(char))` o revisar la causa real del fallo). |
