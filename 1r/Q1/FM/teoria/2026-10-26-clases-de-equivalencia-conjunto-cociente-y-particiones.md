# Clases de equivalencia, conjunto cociente y particiones

> Clase de FM · 2026-10-26 14:03 · 00:23:18 · es-ES
> Apunte generado a partir de la transcripción automática (`teoria/2026-10-26-clases-de-equivalencia-conjunto-cociente-y-particiones-transcripcion.md`); puede tener errores: revisa lo marcado con [?].

## En una frase

Las clases de equivalencia de una relación de equivalencia en `A` forman una partición de `A` (no vacías, disjuntas, con unión `A`), y la clase termina con el inicio de Funciones.

## Temas de la clase

- Clase de equivalencia `[a]` y conjunto cociente `A/R`
- Propiedades de las clases: `a ∈ [a]`, `a R b ⇒ [a] = [b]`, disjuntas si no relacionados
- Definición de partición
- Demostración de que `A/R` es partición (doble inclusión para la unión)
- Inicio de Funciones

## Clase de equivalencia

La clase de un elemento agrupa a todos los elementos del conjunto que están relacionados con él mediante una relación de equivalencia.

- Sea `R` una relación de equivalencia en `A` y `a ∈ A`.
- Clase de `a`: `[a] = {x ∈ A : x R a}`.
- **Conjunto cociente** `A/R`: el conjunto de todas las clases de equivalencia.

**Ojo:** dos elementos relacionados no dan dos clases distintas, sino la misma clase con dos representantes.

## Propiedades de las clases

1. **Reflexividad:** cada `a` pertenece a su propia clase, `a ∈ [a]`.
2. **Si `a R b`:** `[a] = [b]`.
3. **Si `a` y `b` no están relacionados:** las clases son distintas y no comparten elementos, `[a] ∩ [b] = ∅` [?].

Estas propiedades se prueban aplicando las definiciones de reflexiva, simétrica y transitiva, y el profesor insistió en que no son difíciles.

**Ojo:** dos clases o coinciden del todo o son disjuntas. No hay solapamientos parciales.

## Partición

Una partición de `A` es un conjunto de subconjuntos de `A` que cumple tres condiciones:

- Cada subconjunto es **no vacío**.
- Dos subconjuntos distintos son **disjuntos**.
- La **unión** de todos los subconjuntos es `A`.

Las clases de equivalencia de una relación de equivalencia forman una partición de `A`, es decir, el conjunto cociente `A/R` es una partición.

## Las clases forman una partición (demostración)

1. **No vacías:** cada `x ∈ [x]`, por reflexividad.
2. **Distintas implica disjuntas:** es la propiedad 3.
3. **La unión es `A`:** se prueba por **doble inclusión**.
   - `⊆`) Cada clase es un subconjunto de `A`, así que su unión también lo es.
   - `⊇`) Sea `x ∈ A` cualquiera. Como `x ∈ [x]`, `x` está en la unión de las clases.

**Ojo:** para probar que dos conjuntos son iguales hay que dar las dos inclusiones y trabajar con un `x` genérico, no con ejemplos.

## Inicio de Funciones

Al final de la clase el profesor cambió de tema y empezó con funciones. El resto de esa parte no está en este fragmento de la transcripción.

## Avisos

- El profesor dijo que lo de relaciones de equivalencia y particiones consiste sobre todo en aplicar definiciones y que no es difícil.
- Gran parte del audio de la primera mitad es ininteligible. Lo no recogido aquí hay que contrastarlo con los apuntes del curso (FMPart1.pdf).

## Para repasar

1. ¿Cómo se define la clase de equivalencia `[a]`?
2. ¿Qué propiedad garantiza que `a ∈ [a]`?
3. Si `a R b`, ¿qué relación hay entre `[a]` y `[b]`? ¿Y si no están relacionados?
4. ¿Qué tres condiciones debe cumplir una partición de `A`?
5. ¿Qué dos inclusiones se prueban para ver que la unión de las clases es `A`?
6. ¿Qué es el conjunto cociente `A/R`?
