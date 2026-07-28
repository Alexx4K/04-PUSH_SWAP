#include "linked_lists.h"
#include "push_swap.h"
#include <stdio.h>

static void	print_stack(char *name, t_stack *stack)
{
	printf("%s: ", name);
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
	printf("\n");
}

static void	append_node(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = new_node;
	new_node->prev = last;
}

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

static int	init_stack(t_stack **stack, int *values, int size)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	while (i < size)
	{
		new_node = ft_lstnew(values[i]);
		if (!new_node)
			return (0);
		append_node(stack, new_node);
		i++;
	}
	return (1);
}

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	test_sort_selection(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values[] = {5, 2, 8, 1, 9};
	int		size = 5;

	printf("\n=== Test 1: Basic Sort (5, 2, 8, 1, 9) ===\n");
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, values, size);
	printf("Before: ");
	print_stack("A", stack_a);
	sort_selection(&stack_a, &stack_b);
	printf("After:  ");
	print_stack("A", stack_a);
	printf("Sorted: %s\n", is_sorted(stack_a) ? "YES" : "NO");
	free_stack(stack_a);
	free_stack(stack_b);

	printf("\n=== Test 2: Already Sorted (1, 2, 3, 4, 5) ===\n");
	int values2[] = {1, 2, 3, 4, 5};
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, values2, 5);
	printf("Before: ");
	print_stack("A", stack_a);
	sort_selection(&stack_a, &stack_b);
	printf("After:  ");
	print_stack("A", stack_a);
	printf("Sorted: %s\n", is_sorted(stack_a) ? "YES" : "NO");
	free_stack(stack_a);
	free_stack(stack_b);

	printf("\n=== Test 3: Reverse Sorted (5, 4, 3, 2, 1) ===\n");
	int values3[] = {5, 4, 3, 2, 1};
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, values3, 5);
	printf("Before: ");
	print_stack("A", stack_a);
	sort_selection(&stack_a, &stack_b);
	printf("After:  ");
	print_stack("A", stack_a);
	printf("Sorted: %s\n", is_sorted(stack_a) ? "YES" : "NO");
	free_stack(stack_a);
	free_stack(stack_b);

	printf("\n=== Test 4: Single Element (42) ===\n");
	int values4[] = {42};
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, values4, 1);
	printf("Before: ");
	print_stack("A", stack_a);
	sort_selection(&stack_a, &stack_b);
	printf("After:  ");
	print_stack("A", stack_a);
	printf("Sorted: %s\n", is_sorted(stack_a) ? "YES" : "NO");
	free_stack(stack_a);
	free_stack(stack_b);

	printf("\n=== Test 5: Duplicates (3, 1, 3, 2, 1) ===\n");
	int values5[] = {3, 1, 3, 2, 1};
	stack_a = NULL;
	stack_b = NULL;
	init_stack(&stack_a, values5, 5);
	printf("Before: ");
	print_stack("A", stack_a);
	sort_selection(&stack_a, &stack_b);
	printf("After:  ");
	print_stack("A", stack_a);
	printf("Sorted: %s\n", is_sorted(stack_a) ? "YES" : "NO");
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(void)
{
	printf("***** SORT SELECTION TESTS *****\n");
	test_sort_selection();
	printf("\n***** END OF TESTS *****\n");
	return (0);
}
