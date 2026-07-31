*Este proyecto ha sido creado como parte del currículo de 42 por crubio-p y aarellan.*

## REGLAS

- Tenéis 2 `stacks`, llamados `a` y `b`.

- Para empezar:
  - El stack `a` contiene una cantidad aleatoria de números positivos y/o negativos.
  - El stack `b` está vacío.

- El objetivo es ordenar los números del stack `a` en orden ascendente. Para hacerlo están disponibles las siguientes operaciones:

### Operaciones

- `sa` (`swap a`): Intercambia los dos primeros elementos del stack `a`.
  No hace nada si hay solo uno o ningún elemento.

- `sb` (`swap b`): Intercambia los dos primeros elementos del stack `b`.
  No hace nada si hay solo uno o ningún elemento.

- `ss`: `sa` y `sb` a la vez.

- `pa` (`push a`): Toma el primer elemento del stack `b` y lo coloca el primero en el stack `a`.
  No hace nada si `b` está vacío.

- `pb` (`push b`): Toma el primer elemento del stack `a` y lo coloca el primero en el stack `b`.
  No hace nada si `a` está vacío.

- `ra` (`rotate a`): Desplaza hacia arriba todos los elementos del stack `a` una posición, convirtiendo el primer elemento en el último.

- `rb` (`rotate b`): Desplaza hacia arriba todos los elementos del stack `b` una posición, convirtiendo el primer elemento en el último.

- `rr`: `ra` y `rb` a la vez.

- `rra` (`reverse rotate a`): Desplaza hacia abajo todos los elementos del stack `a` una posición, convirtiendo el último elemento en el primero.

- `rrb` (`reverse rotate b`): Desplaza hacia abajo todos los elementos del stack `b` una posición, convirtiendo el último elemento en el primero.

- `rrr`: `rra` y `rrb` a la vez.


## VI.3. Requisitos del algoritmo

Para asegurar un buen entendimiento de la complejidad algorítmica (*tiempo y espacio*), se deben implementar cuatro estrategias de ordenación distintas e integrarlas todas en el programa `push_swap`.

Además, el programa debe ser capaz de seleccionar una estrategia u otra durante la ejecución, en función de la configuración de entrada.

## VI.3.1. Modelo de complejidad y restricciones

Todas las estrategias deben ser implementadas en C y deben generar secuencias de operaciones de Push_swap para ordenar los elementos. Esto significa que:

- Los algoritmos en C analizan la entrada y generan la secuencia adecuada de operaciones para ordenarla: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.

- La salida por consola de esta estrategia deberá ser la secuencia de operaciones necesarias para ordenar el stack.

- Al expresar la complejidad, debe medirse en función del **número de operaciones de Push_swap que el programa produce**, y no en base a la complejidad teórica de un algoritmo tradicional sobre arrays.

## VI.3.2. Índice de desorden (obligatorio)

En este proyecto, el **desorden** corresponde a un número entre `0` y `1` que refleja lo lejos que el stack `a` se encuentra de estar ordenado al comienzo del programa.

Si todos los números están en orden, el índice de desorden será `0`. Si los números están lo más desordenados posibles, el índice de desorden será `1`. Todo lo que haya entre medias significará que el stack se encuentra parcialmente ordenado, pero sigue teniendo desorden.

Para calcular el índice de desorden, imagina que observas todos los pares posibles de números en el stack. Cada vez que un número mayor aparece antes que uno menor, consideramos que hay un *error* en el orden. Cuantos más errores haya, mayor será el índice de desorden, acercándose al valor `1`, que refleja el desorden absoluto.

```c
function compute_disorder(stack a):
	mistakes = 0
	total_pairs = 0
	for i from 0 to size(a)-1:
		for j from i+1 to size(a)-1:
			total_pairs += 1
			if a[i] > a[j]:
				mistakes += 1
	return mistakes / total_pairs
```

## VI.3.3. Estrategias requeridas

1. **Algoritmo simple (O(n²)):**

   Implementa al menos **un algoritmo** base perteneciente a la clase de complejidad **O(n²)**. Por ejemplo:

   - Adaptación del orden por inserción
   - Adaptación del orden por selección <- Buscamos cuál va a ser el valor del mínimo actual en  el stack (recorriendo la lista)
   - Adaptación del orden burbuja
   - Métodos simples de extracción del mínimo/máximo

### (Selection  Sort) - Adaptación del orden por selección

1. Buscamos cuál va a ser el valor del mínimo actual en  el stack (recorriendo la lista) y nos guardamos cuál es ese valor.
2. Empiezo a rotar hasta que arriba esté el focking valor.
3. Pusheas a stack_b
4. Después de hacer todo eso -> Pushear todo b en a hasta vaciar el stack.

---

2. **Algoritmo intermedio (O(n√n)):**

   Implementa al menos **un algoritmo** perteneciente a la clase de complejidad **O(n√n)**. Por ejemplo:

   - Orden basado en chunks (dividiendo en √n chunks)
   - Métodos de partición basados en bloques
   - Adaptaciones del orden por buckets con √n buckets
   - Estrategias de orden basadas en rangos

### (Chunk Sort) - Orden basado en chunks (dividiendo en √n chunks)
1. Calculamos el tamaño de cada chunk -> Va a ser de tamaño √n, siendo n la cantidad de elementos.
2. Vamos metiendo los valores de chunk en chunk.
	- Para optimizar la colocación, podemos decidir añadirlos de forma que queden en la cima o abajo según pertenece a una de las mitades del chunk.

		```c
			if (indice < mitad_del_chunk)
				pb();
				rb();
			else
				pb();
		```
3. Y luego vamos pusheándolos de vuelta igual.

La gracia está en que la cantidad de rotaciones va a ser bastante menor, en promedio, que de la otra manera.


---

3. **Algoritmo complejo (O(n log n)):**

   Implementa al menos **un algoritmo** perteneciente a la clase de complejidad **O(n log n)**. Por ejemplo:

   - Adaptación del orden radix (LSD o MSD)
   - Adaptación del orden por fusión utilizando dos stacks
   - Adaptación del orden rápido con partición por stacks
   - Adaptación del orden por montículos
   - Algoritmos de árbol binario indexado<>




## Estrategia adaptativa: umbrales, técnicas y complejidad

El modo `--adaptive` (comportamiento por defecto si no se indica ningún
selector) elige la estrategia interna en función del **índice de desorden**
calculado sobre el stack `a` original, antes de mover nada
(`ft_compute_disorder`, en [`sort/ft_adaptive.c`](sort/ft_adaptive.c)).
La decisión (`ft_exec_strategy_dispatch`) es:

| Desorden           | Técnica interna                          | Clase (modelo Push_swap) |
|--------------------|-------------------------------------------|---------------------------|
| `< 0.2` (bajo)      | Selection sort adaptado (`sort_selection`) | `O(n²)` peor caso |
| `[0.2, 0.5)` (medio)| Chunk sort (`ft_prechunksort`, chunks de tamaño `√n`) | `O(n·√n)` |
| `>= 0.5` (alto)     | Radix sort LSD sobre los índices de rango (`ft_radix_sort`) | `O(n·log n)` |

**Justificación de los umbrales:**

- `0.2` marca el punto en el que el coste de un algoritmo cuadrático
  (proporcional al nº de inversiones) deja de ser competitivo frente al
  chunk sort: con pocas inversiones, `sort_selection` mueve pocos elementos
  fuera de sitio y el nº de rotaciones se mantiene bajo en la práctica,
  aunque su cota teórica siga siendo `O(n²)`.
- `0.5` es el desorden esperado de una entrada **totalmente aleatoria**
  (en promedio, la mitad de los pares están invertidos). Por eso, a partir
  de ese punto se usa el algoritmo más robusto en el peor caso (radix
  sort), que no depende del nº de inversiones sino del nº de bits de los
  índices (`log₂ n` pasadas), garantizando un buen rendimiento incluso en
  el caso más desordenado posible.

**Cotas de espacio:** todas las estrategias trabajan directamente sobre las
dos listas doblemente enlazadas (`t_stack`) que ya existen; ninguna reserva
memoria adicional proporcional a `n` durante la ordenación (el único
`malloc` proporcional a `n` es la construcción inicial del stack a partir
de los argumentos). Por tanto el espacio extra usado por cada estrategia es
`O(1)`.

**Cotas de tiempo (en nº de operaciones Push_swap):**

- *Selection sort* (`sort/selection_sort.c`): por cada uno de los `n`
  elementos se busca el mínimo restante (`find_min_value`/`find_position`,
  `O(n)`) y se rota hasta la cima (como mucho `n/2` rotaciones) antes de
  empujarlo a `b`; al final se vuelca `b` en `a`. Cota: `O(n²)` operaciones.
- *Chunk sort* (`sort/ft_chunksort.c`): se reparten los `n` elementos en
  `√n` chunks de tamaño `√n`; cada elemento se localiza y se rota dentro de
  su stack (como mucho `O(√n)` posiciones de media si el stack se mantiene
  balanceado) y luego se reinserta en orden. Cota: `O(n·√n)` operaciones.
- *Radix sort LSD* (`sort/ft_radix.c`): se opera sobre los índices de rango
  `1..n` (nunca sobre los valores originales, que pueden ser negativos o
  muy grandes), por lo que bastan `⌈log₂ n⌉` pasadas; cada pasada visita
  los `n` elementos una vez (`ra`/`pb` por elemento). Cota:
  `O(n·log n)` operaciones.
- *Adaptativo*: por construcción, el coste total es el de la técnica
  elegida para el régimen de desorden medido, según la tabla anterior.

## Idea Estructura de archivos

```shell

  parsing/
    flags.c
    flags_comparing.c
    parser.c
    tokenizer.c
    utils.c

  sort/
    ft_adaptive.c
    ft_chunksort.c
    ft_radix.c
    selection_sort.c
    small_sort.c
    sorting_utils.c

  stack/
    ft_push.c
    ft_rotate.c
    ft_swap.c

  tests/                 (no se entrega ni se evalúa, ver VII del subject)
    test_indexed_sort.c
    test_indexed_checks.c
    test_indexed_print.c
    testing_main.c
    testing_print.c
    testing_utils.c
    testSortSel.c

  ft_bench.c
  libft/                 (con su propio Makefile)
  linked_lists.c
  list_utils.c
  main.c
  Makefile
  push_swap.c
  push_swap.h
  README.md

```


## NOTAS

- El formato de entrada son: flags -> números
  - No puede haber flags entre medias o después de los números.
- Selectores de estrategia: `--simple`, `--medium`, `--complex`,
  `--adaptive` (por defecto). `--bench` (opcional, combinable con
  cualquier selector) imprime en `stderr` el desorden, la estrategia usada
  y el desglose de operaciones por tipo.

## Contribuciones

_Pendiente de completar por crubio-p y aarellan: detallar aquí qué partes
del código ha implementado cada estudiante, tal y como exige el apartado
VI.1 del subject._

