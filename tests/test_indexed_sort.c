#include "linked_lists.h"
#include "sorting_algos/sorting_algos.h"
#include <stdio.h>

/*

cc -Wall -Wextra -Werror -I. -Isorting_algos \
tests/test_indexed_sort.c linked_lists.c \
stack/ft_push.c stack/ft_rotate.c stack/ft_swap.c \
sorting_algos/selection_sort.c sorting_algos/ft_chunksort.c \
sorting_algos/ft_radix.c sorting_algos/sorting_utils.c \
-o test_indexed_sort && ./test_indexed_sort

 */

static void	free_stack(t_stack *stack)
{
	t_stack	*next;

	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

static int	append_node(t_stack **stack, int content)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = ft_lstnew(content);
	if (!new_node)
		return (0);
	if (!*stack)
	{
		*stack = new_node;
		return (1);
	}
	last = ft_lstlast(*stack);
	last->next = new_node;
	new_node->prev = last;
	return (1);
}

static int	get_index(const int *values, int size, int position)
{
	int	index;
	int	i;

	index = 1;
	i = 0;
	while (i < size)
	{
		if (values[i] < values[position])
			index++;
		i++;
	}
	return (index);
}

static int	has_duplicates(const int *values, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] == values[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	init_indexed_stack(t_stack **stack, const int *values, int size)
{
	int	i;
	int	index;

	if (has_duplicates(values, size))
		return (0);
	i = 0;
	while (i < size)
	{
		index = get_index(values, size, i);
		printf("  value %d -> index %d\n", values[i], index);
		if (!append_node(stack, index))
		{
			free_stack(*stack);
			*stack = NULL;
			return (0);
		}
		i++;
	}
	return (1);
}

static void	print_values(const int *values, int size)
{
	int	i;

	i = 0;
	printf("[");
	while (i < size)
	{
		printf("%d", values[i]);
		if (i + 1 < size)
			printf(", ");
		i++;
	}
	printf("]\n");
}

static void	print_stack(const char *name, t_stack *stack)
{
	printf("%s: top -> ", name);
	if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack)
	{
		printf("%d", stack->content);
		if (stack->next)
			printf(" -> ");
		stack = stack->next;
	}
	printf(" -> NULL\n");
}

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content >= stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	has_valid_prev_links(t_stack *stack)
{
	t_stack	*previous;

	previous = NULL;
	while (stack)
	{
		if (stack->prev != previous)
			return (0);
		previous = stack;
		stack = stack->next;
	}
	return (1);
}

static int	test_algorithm(const char *name,
		void (*sort)(t_stack **, t_stack **), const int *values, int size)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		ok;

	stack_a = NULL;
	stack_b = NULL;
	printf("\n=== %s ===\n", name);
	printf("Index correspondence (smallest value has index 1):\n");
	if (!init_indexed_stack(&stack_a, values, size))
	{
		fprintf(stderr, "Error: duplicate value or allocation failure\n");
		return (0);
	}
	printf("\nInitial indexed state:\n");
	print_stack("A", stack_a);
	print_stack("B", stack_b);
	sort(&stack_a, &stack_b);
	printf("\nFinal state:\n");
	print_stack("A", stack_a);
	print_stack("B", stack_b);
	ok = is_sorted(stack_a) && stack_b == NULL
		&& ft_lstsize(stack_a) == size && has_valid_prev_links(stack_a);
	printf("Result: %s\n", ok ? "OK" : "KO");
	free_stack(stack_a);
	free_stack(stack_b);
	return (ok);
}

int	main(void)
{
	int		values[] = {42, -7, 1000, 3, -25, 81, 0};
	int		size;
	int		ok;

	size = sizeof(values) / sizeof(values[0]);
	printf("Original values: ");
	print_values(values, size);
	ok = test_algorithm("Selection sort", sort_selection, values, size);
	ok &= test_algorithm("Chunk sort", ft_prechunksort, values, size);
	ok &= test_algorithm("Radix sort", ft_radix_sort, values, size);
	printf("\nOverall result: %s\n", ok ? "OK" : "KO");
	return (!ok);
}
