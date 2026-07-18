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

   


## Idea Estructura de archivos

```shell
includes/
  push_swap.h

src/
  main.c

  parse/
    parse_args.c
    check_args.c

  stack/
    stack_new.c
    stack_utils.c
    stack_free.c
    stack_index.c

  ops/
    swap.c
    push.c
    rotate.c
    reverse_rotate.c

  sort/
    sort.c
    sort_selection.c
    sort_chunks.c
    sort_radix.c
    sort_small.c
```
