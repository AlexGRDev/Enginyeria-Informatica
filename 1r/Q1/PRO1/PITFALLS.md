# Errores recurrentes — PRO1

<!-- kiwi-gei:pitfalls:inici -->
## Contador de errores (Kiwi GEI)

Generado el 2026-11-19. Ordenado por número de veces: arriba, lo que más hay que reforzar.

| Patrón | Tema | Veces | Última vez | Cómo reforzar |
|---|---|---|---|---|
| No sabe abordar Funciones auxiliares | Funciones auxiliares | 18 | 2026-11-19 | Recorrido de dígitos con %10 y /10, aquí en base 256, separando en funciones. |
| No sabe abordar Tipos básicos | Tipos básicos | 17 | 2026-10-29 | Practicar esquemas de recorrido de secuencias con comparación de elementos consecutivos. |
| No sabe abordar E/S con std::cin/std::cout | E/S con std::cin/std::cout | 16 | 2026-11-19 | Practicar el esquema de lectura de secuencia sin sentinela y mantener el mínimo en curso. |
| No documentar las funciones con especificación pre/post | Funciones auxiliares | 10 | 2026-11-19 | Escribir @pre y @post sobre cada función antes de implementarla. |
| No sabe abordar Recursividad | Recursividad | 5 | 2026-11-19 | Practicar recursión sobre dígitos con caso base x==0 and y==0 y paso x/10, y/10. |
| Uso incorrecto de punteros sobre variables escalares | Punteros y aritmética de punteros | 3 | 2026-10-28 | Usar variables enteras/char o vector con índices; reservar memoria dinámica solo cuando el enunciado lo pida. |
| Código redundante o innecesariamente complicado | Funciones auxiliares | 2 | 2026-10-29 | Devolver directamente con return en cada rama y usar variable separada para el resultado. |
| Código redundante o innecesariamente complicado | Tipos básicos | 2 | 2026-10-29 | Encadenar con else if cuando las condiciones son excluyentes y no evaluar condiciones de más. |
| Esquemas de lectura no recomendados | E/S con std::cin/std::cout | 2 | 2026-10-29 | Leer una sola vez cin >> h >> m >> s y resolver el caso sin bucle. |
| Variables declaradas en un ámbito más amplio del necesario | Tipos básicos | 1 | 2026-11-19 | Declarar la variable de lectura dentro del cuerpo del bucle. |
| for en lugar de while cuando la iteración depende de una condición | Tipos básicos | 1 | 2026-11-19 | Usar for (int i = 1; i < n; ++i) para recorrer n elementos conocidos. |
| Código redundante o innecesariamente complicado | E/S con std::cin/std::cout | 1 | 2026-10-28 | Ordenar una sola vez antes del bucle de escritura, o separar ordenar y escribir en funciones distintas. |
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
