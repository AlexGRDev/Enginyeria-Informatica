# Errores recurrentes — F

<!-- kiwi-gei:pitfalls:inici -->
## Contador de errores (Kiwi GEI)

Generado el 2026-10-28. Ordenado por número de veces: arriba, lo que más hay que reforzar.

| Patrón | Tema | Veces | Última vez | Cómo reforzar |
|---|---|---|---|---|
| no sabe abordar Corrent Altern | Corrent Altern | 2 | 2026-10-28 | Rehaz este problema (nov 2022) paso a paso: `I = V_R/R` con su fase, `Z = V/I`, `Z_AB = Z − R`, `V_AB = Z_AB·I`, `I_L = V_AB/(jX_L)`, `I_p = I − I_L`. Haz 5 problemas de ProblemesTema2. |
| no sabe abordar Circuits de CC: Kirchhoff, divisor de tensió, Req, pont de Wheatstone | Circuits de CC: Kirchhoff, divisor de tensió, Req, pont de Wheatstone | 2 | 2026-10-28 | Repite este problema (nov 2021) desde cero: nudos y mallas, Thévenin con fuentes anuladas, condensador = circuito abierto en estacionario. Añade ProblemesTema1 problema 28. |
| error en función de transferencia de filtro RL | Corrent Altern | 1 | 2026-10-28 | Escribe `H = R/(R + jωL)`, calcula el módulo, iguala y despeja. Practica filtros RC/RL de ProblemesTema2. |
| confunde condiciones inicial y final en circuito RL | Corrent Altern | 1 | 2026-10-28 | RL: `I(t) = (ε/R)(1 − e^{−t/τ})`, `τ = L/R`. Haz los problemas de transitorios RC/RL de ProblemesTema2. |
| no plantea el sistema de dos ecuaciones para Thévenin | Circuits de CC: Kirchhoff, divisor de tensió, Req, pont de Wheatstone | 1 | 2026-10-28 | Con dos medidas (R, V), divide las ecuaciones para obtener `R_Th` y luego `ε_Th`. Verifica siempre la opción elegida con ambos datos. |
| no aplica Z = R en resonancia (P = Vef²/R) | Corrent Altern | 1 | 2026-10-28 | Memoriza: resonancia `ω = 1/√(LC)`, `Z = R`, `I = V/R`, `P = V_ef²/R`. Haz 3 problemas RLC serie de ProblemesTema2. |
| no sabe abordar Camp elèctric i potencial (E = -∇V) | Camp elèctric i potencial (E = -∇V) | 1 | 2026-10-25 | Rehaz ProblemesTema1 problema 1 y otros dos problemas similares: `E = ΔV/d`, sentido de E hacia V decreciente por `E = −∇V`, `W = Q·ΔV`, `I = ΔQ/Δt`. Escribe siempre unidades. |
| no sabe abordar Llei d'Ohm (V = IR, J = σE) i resistència | Llei d'Ohm (V = IR, J = σE) i resistència | 1 | 2026-10-25 | Practica la cadena completa con un hilo conductor: `R = ρL/A` (sección en m²: 1 mm² = 10⁻⁶ m²), `I = V/R`, `J = I/A`, `E = V/L`, comprobar `σE = J` con `σ = 1/ρ`. Haz al menos 3 problemas de ProblemesTema1 de este tipo. |
| no sabe abordar Corrent elèctric (I = dQ/dt, I = n·q·v_d·A, J) | Corrent elèctric (I = dQ/dt, I = n·q·v_d·A, J) | 1 | 2026-10-25 | Despeja `v_d = J/(n·e)` y vigila las potencias de 10. El resultado esperado es del orden de 10⁻⁴ a 10⁻⁵ m/s; si te sale mucho mayor, revisa. |
<!-- kiwi-gei:pitfalls:fi -->

| Fecha | Ejercicio | Error | Corrección |
|---|---|---|---|
| 2026-09-18 | Pràctica 1, 1.2 (oscil·loscopi, Figura 4) | Asumir a ojo que la reticula del osciloscopio es la estándar 10x8 divisiones sin contar las líneas reales del dibujo | Siempre contar las divisiones reales de la figura dada (aquí eran 10x10, no 10x8) antes de leer H y L; en este caso se verificó renderizando el PDF a alta resolución y localizando las gridlines por píxel para no adivinar |
