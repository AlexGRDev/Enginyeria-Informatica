# Simulador de parciales de PRO1 (Q1)

Herramienta personal (NO oficial de la FIB/UPC) para practicar los parciales
de PRO1 en condiciones parecidas a un examen real: selección aleatoria de un
parcial completo, cronómetro visible y autocorrección por comparación con una
solución de referencia. Inspirada en la experiencia de uso de Maestro42 (el
emulador de exámenes de 42), pero sin replicar su arquitectura: PRO1 no tiene
un juez automático ni casos de test oficiales disponibles, así que aquí no
hay un pass/fail automático, solo ayuda a la autocorrección manual.

## De dónde salen los datos

Los enunciados y soluciones de referencia vienen del repo público
[`smyha/smyha-FIB-UPC_PRO1`](https://github.com/smyha/smyha-FIB-UPC_PRO1),
carpeta `Examens/`. Se usan las 7 subcarpetas correspondientes a parciales de
Q1 (controles de 1r quadrimestre, cursos 19-20 a 21-22).

**Ese repo no tiene licencia declarada** (sin fichero `LICENSE`, copyright por
defecto del autor). Por eso los ficheros `.cc` originales **no se vendorizan
aquí**: `make` los descarga en tiempo de ejecución a `.cache/`, que está
excluido de git (ver `.gitignore` de esta carpeta). Si el repo fuente
desaparece o cambia, este simulador deja de funcionar hasta actualizar la URL.
Crédito íntegro a smyha por el trabajo de recopilación original.

### Limitación real del parseo enunciado/solución

Cada `.cc` se separa en `enunciado.txt` (bloque de comentarios `//` inicial) y
`solucion_referencia.cc` (el resto). **Esto no es uniforme en los datos de
origen**: algunos ficheros traen el enunciado completo como comentario inicial
(p. ej. `X19266-ElapsedTime.cc`), pero varios solo tienen un comentario de
título de una línea (p. ej. `X50401 - NullTriplets.cc`) o ni siquiera eso
(empiezan directo con `#include`, p. ej. `X16146`, `X38881`, `X64717`). En
esos casos `enunciado.txt` queda vacío o casi vacío — no es un bug del script,
es así en el repo fuente. El simulador lo avisa en pantalla cuando pasa; si
necesitas el enunciado completo de un problema así, consúltalo directamente
en el repo original.

## Uso

```bash
make            # = make start: arranca una sesión de examen en MODO REAL
make grade      # atajo FUERA de sesión: corrige el último intento (ver abajo)
make clean      # borra cache y binarios compilados (NO toca intentos/)
make help       # lista de comandos
```

Variables:
- `EXAM_MINUTES` — duración del cronómetro, por defecto **90 minutos**. Este
  valor es orientativo, NO está confirmado contra la duración oficial real
  del examen parcial de la FIB — ajústalo si tienes el dato real
  (`make EXAM_MINUTES=120`).
- `ATTEMPT` — ruta del intento a corregir con `make grade` (por defecto, el
  más reciente en `intentos/`).

### `make` / `make start`: sesión en modo REAL

Inspirado en el modo "real" de Maestro42 (examshell de 42): no es un script
de un solo disparo, es una **sesión interactiva persistente** con cronómetro
real, igual de fiel al examen oficial como sea posible:

1. Si no hay cache local de los 7 parciales, la descarga.
2. Disclaimer: qué es esto, qué no es, qué comandos hay disponibles durante
   la sesión. Pide confirmación (`y/n`) antes de arrancar nada.
3. Animación de "conexión" (puramente estética).
4. Elige un parcial al azar entre los disponibles en cache, crea
   `intentos/<timestamp>-<parcial>/` con un `.cpp` vacío por problema
   (cabecera ASCII estándar de 42 ya puesta, nombrado `<CODIGO>.cpp`), y
   pide pulsar una tecla para comenzar. **El cronómetro arranca de verdad en
   ese momento**, no antes.
5. Muestra de golpe los enunciados de todos los problemas (como el examen
   real, no de uno en uno) y entra en el prompt interactivo `examshell>`,
   que se queda esperando comandos hasta que termines o se acabe el tiempo:

   | Comando | Qué hace |
   |---|---|
   | `help` | Lista de comandos. |
   | `status` | Tiempo restante real, parcial actual y estado de compilación de cada problema. |
   | `enunciado` (alias `subject`) | Vuelve a imprimir los enunciados completos. |
   | `grademe` | Compila, ejecuta (interactivo) y compara cada `.cpp` con la solución de referencia — ver detalle abajo. |
   | `finish` | Pide confirmación (`yes`) y muestra el resumen final (tiempo usado, estado de cada problema) antes de salir. |

   Si el tiempo ya se acabó cuando ejecutas cualquier comando, la sesión lo
   avisa ("SE ACABÓ EL TIEMPO") y fuerza el cierre con resumen, no deja
   seguir trabajando como si nada. Ctrl+C / Ctrl+D también cierran la
   sesión de forma limpia (resumen incluido), sin pedir confirmación.

### `grademe` (dentro de sesión) / `make grade` (fuera de sesión)

Misma lógica de corrección en los dos casos — `grademe` es simplemente el
comando interno para invocarla sin salir de la sesión; `make grade` sigue
disponible como atajo standalone para repasar después de que la sesión ya
haya terminado:

- Compila cada `.cpp` del intento con los mismos flags que el resto del repo
  (`clang++ -Wall -Wextra -fsanitize=address,undefined -O0`).
- Ejecuta tu binario de forma **interactiva**: tú introduces tu propia
  entrada de prueba (no hay casos de test oficiales para estos exámenes).
- Justo después muestra la solución de referencia para que compares a ojo.
- **Esto no es un corrector automático pass/fail.** Es ayuda a la
  autocorrección manual.

## Estructura

```
simulador-parcials/
├── README.md
├── Makefile
├── .gitignore          # excluye .cache/ y los binarios de intentos/
├── scripts/
│   ├── common.sh            # config compartida (lista de parciales, slug())
│   ├── fetch_examenes.sh    # descarga y separa enunciado/solución por problema
│   ├── iniciar_examen.sh    # disclaimer, confirmación, elige parcial, crea intento, arranca cronómetro
│   ├── sesion_examen.sh     # bucle interactivo examshell> (status/enunciado/grademe/finish)
│   ├── grade.sh             # compila, ejecuta y muestra solución de referencia (grademe / make grade)
│   └── header_template.cpp  # plantilla de la cabecera 42 (placeholders de nombre/fecha)
├── .cache/              # (generado, gitignored) enunciados y soluciones descargados
└── intentos/            # (generado, SÍ trackeado) tus .cpp de cada intento
```
