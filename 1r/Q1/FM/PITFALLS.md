# Errores recurrentes — FM

<!-- kiwi-gei:pitfalls:inici -->
## Contador de errores (Kiwi GEI)

Generado el 2026-10-27. Ordenado por número de veces: arriba, lo que más hay que reforzar.

| Patrón | Tema | Veces | Última vez | Cómo reforzar |
|---|---|---|---|---|
| errores aritméticos básicos | Inducció | 2 | 2026-10-27 | Revisa cada igualtat abans de passar a la línia següent. |
| H.I. y T.I. mal formuladas | Inducció | 2 | 2026-10-27 | Plantilla: H.I. = l'enunciat amb n−1 al lloc de n; T.I. = l'enunciat amb n; especifica sempre n > 1. |
| lectura errónea de la notación de sumatorio | Sumatoris | 2 | 2026-10-27 | Desplega a mà ∑_{k=1}^{3} 1/k² = 1 + 1/4 + 1/9 per fixar què fan l'índex i els límits. |
| no sabe abordar Conjunts i Relacions | Conjunts i Relacions | 2 | 2026-10-27 | Practica 5 igualtats de conjunts amb l'esquema 'sigui x ∈ X qualsevol' + definicions de ∪, ∩ i ⊆ (exàmens 2021-2022 de EXAMFM.pdf). |
| no indica el método de demostración | Demostracions | 2 | 2026-10-27 | Comença sempre amb: '⇒) Suposem … (H). Prova directa per doble inclusió.' i '⇐) …'. |
| no sabe abordar Lògica | Lògica | 1 | 2026-10-27 | Escriu sempre la cadena `¬∀x∃y φ ≡ ∃x∀y ¬φ` i el pas de De Morgan, encara que només sigui en una línia. |
| no justifica las reglas aplicadas | Lògica | 1 | 2026-10-25 | Escriu sempre la cadena `¬∀x∃y φ ≡ ∃x∀y ¬φ` i el pas de De Morgan, encara que només sigui en una línia. |
| comprueba casos concretos en vez de demostrar | Inducció | 1 | 2026-10-25 | El pas inductiu treballa amb n genèric: ∑_{k=1}^{n} = ∑_{k=1}^{n−1} + últim terme, i després aplica la H.I. |
| usa ejemplos como demostración | Demostracions | 1 | 2026-10-25 | Un exemple només serveix per refutar un enunciat universal, no per demostrar-lo. |
<!-- kiwi-gei:pitfalls:fi -->

| Fecha | Ejercicio | Error | Corrección |
|---|---|---|---|
| 2026-09-21 | Sumatoris (ex01, ex02, ex03 + `sumatoris.md`) y Lògica i Demostracions (`logica.md`, ejercicios 8-17) | Se dieron por resueltos y correctos, pero resultaron incorrectos; se eliminaron del repo (commit "deleting(exercices)") | Recomprobar el resultado de un ejercicio (contra el enunciado del PDF oficial y a mano) antes de darlo por resuelto en STATE.md, no solo confiar en que compile o en la primera pasada |
