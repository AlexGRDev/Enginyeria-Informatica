# Errores recurrentes — F

<!-- kiwi-gei:pitfalls:inici -->
## Contador de errores (Kiwi GEI)

Generado el 2026-10-25. Ordenado por número de veces: arriba, lo que más hay que reforzar.

| Patrón | Tema | Veces | Última vez | Cómo reforzar |
|---|---|---|---|---|
| no sabe abordar Corrent Altern | Corrent Altern | 1 | 2026-10-25 | Haz los problemas previos de la Pràctica 3 y 4 o 5 problemas de ProblemesTema2 con RC y RL serie. Para cada uno: `X_C = 1/(ωC)`, `Z = √(R²+X²)`, `I0 = V0/Z`, `φ = arctan(X/R)` con signo, e interpreta quién avanza (capacitivo: avanza la intensidad). |
| no sabe abordar Circuits de CC: Kirchhoff, divisor de tensió, Req, pont de Wheatstone | Circuits de CC: Kirchhoff, divisor de tensió, Req, pont de Wheatstone | 1 | 2026-10-25 | Toma el borne negativo como referencia y escribe `V_A = ε·R_inf/(R_sup+R_inf)` en cada rama. Equilibrio: `V_A = V_B`, que es equivalente a `R/400 = Rx/10`. Repasa los apartados 1.3 a 1.5 de tu Pràctica 2 (ya los hiciste) y ProblemesTema1 problema 28. |
| no sabe abordar Corrent elèctric (I = dQ/dt, I = n·q·v_d·A, J) | Corrent elèctric (I = dQ/dt, I = n·q·v_d·A, J) | 1 | 2026-10-25 | Despeja `v_d = J/(n·e)` y vigila las potencias de 10. El resultado esperado es del orden de 10⁻⁴ a 10⁻⁵ m/s; si te sale mucho mayor, revisa. |
| no sabe abordar Llei d'Ohm (V = IR, J = σE) i resistència | Llei d'Ohm (V = IR, J = σE) i resistència | 1 | 2026-10-25 | Practica la cadena completa con un hilo conductor: `R = ρL/A` (sección en m²: 1 mm² = 10⁻⁶ m²), `I = V/R`, `J = I/A`, `E = V/L`, comprobar `σE = J` con `σ = 1/ρ`. Haz al menos 3 problemas de ProblemesTema1 de este tipo. |
| no sabe abordar Camp elèctric i potencial (E = -∇V) | Camp elèctric i potencial (E = -∇V) | 1 | 2026-10-25 | Rehaz ProblemesTema1 problema 1 y otros dos problemas similares: `E = ΔV/d`, sentido de E hacia V decreciente por `E = −∇V`, `W = Q·ΔV`, `I = ΔQ/Δt`. Escribe siempre unidades. |
<!-- kiwi-gei:pitfalls:fi -->

| Fecha | Ejercicio | Error | Corrección |
|---|---|---|---|
| 2026-09-18 | Pràctica 1, 1.2 (oscil·loscopi, Figura 4) | Asumir a ojo que la reticula del osciloscopio es la estándar 10x8 divisiones sin contar las líneas reales del dibujo | Siempre contar las divisiones reales de la figura dada (aquí eran 10x10, no 10x8) antes de leer H y L; en este caso se verificó renderizando el PDF a alta resolución y localizando las gridlines por píxel para no adivinar |
