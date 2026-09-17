# Errores recurrentes — PRO1

| Fecha | Ejercicio | Error | Corrección |
|---|---|---|---|
| 2026-09-11 | P42042 | `ft_strchr` con doble puntero: avanzaba el puntero (`ptrs++`) sin desreferenciarlo y devolvía `s` (el puntero original) en vez de la posición encontrada. | Avanzar con `(*ptrs)++` y devolver `(char *)*ptrs`. |
| 2026-09-11 | P42042 | Cadena de vocales `"aeiou"` no incluía mayúsculas → clasificaba mal las vocales en mayúscula. | Cambiar a `"aeiouAEIOU"`. |
| 2026-09-13 | P42042, P98960 | `malloc(sizeof(char))` para leer un único carácter con `std::cin >> *a` fallaba/no era suficiente en la práctica. | Cambiado a `malloc(sizeof(std::string) + 1)` — revisar si es la corrección idónea o sobreingeniería (reservar `sizeof(std::string)` para un solo `char` es más memoria de la necesaria; posible mejor fix: `malloc(2 * sizeof(char))` o revisar la causa real del fallo). |
