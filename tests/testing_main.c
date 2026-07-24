/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 00:00:00 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/24 19:52:13 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include <stdio.h>

static int	node_value(t_stack *node)
{
	return (node->content);
}

static void	print_stack(char *name, t_stack *stack)
{
	printf("%s: top -> ", name);
	if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	while (stack)
	{
		printf("%d", node_value(stack));
		if (stack->next)
			printf(" -> ");
		stack = stack->next;
	}
	printf(" -> NULL\n");
}

static int	check_prev_links(t_stack *stack)
{
	t_stack	*prev;

	prev = NULL;
	while (stack)
	{
		if (stack->prev != prev)
			return (0);
		prev = stack;
		stack = stack->next;
	}
	return (1);
}

static void	print_state(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	printf("\n[%s]\n", operation);
	print_stack("A", stack_a);
	print_stack("B", stack_b);
	printf("prev links A: %s\n", check_prev_links(stack_a) ? "OK" : "KO");
	printf("prev links B: %s\n", check_prev_links(stack_b) ? "OK" : "KO");
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

static int	init_stack_a(t_stack **stack_a, int *values, int size)
{
	t_stack	*new_node;
	int		i;

	i = 0;
	while (i < size)
	{
		new_node = ft_lstnew(values[i]);
		if (!new_node)
			return (0);
		append_node(stack_a, new_node);
		i++;
	}
	return (1);
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		values[5];

	stack_a = NULL;
	stack_b = NULL;
	values[0] = 3;
	values[1] = 1;
	values[2] = 4;
	values[3] = 2;
	values[4] = 5;
	if (!init_stack_a(&stack_a, values, 5))
	{
		free_stack(stack_a);
		return (1);
	}
	print_state("initial", stack_a, stack_b);
	ft_swap(&stack_a, &stack_b, 'a');
	print_state("sa", stack_a, stack_b);
	ft_push(&stack_a, &stack_b, 'b');
	print_state("pb", stack_a, stack_b);
	ft_push(&stack_a, &stack_b, 'b');
	print_state("pb", stack_a, stack_b);
	ft_swap(&stack_a, &stack_b, 'b');
	print_state("sb", stack_a, stack_b);
	ft_swap(&stack_a, &stack_b, 's');
	print_state("ss", stack_a, stack_b);
	ft_rotate(&stack_a, &stack_b, 'a');
	print_state("ra", stack_a, stack_b);
	ft_rotate(&stack_a, &stack_b, 'b');
	print_state("rb", stack_a, stack_b);
	ft_rotate(&stack_a, &stack_b, 'r');
	print_state("rr", stack_a, stack_b);
	ft_reverse_rotate(&stack_a, &stack_b, 'a');
	print_state("rra", stack_a, stack_b);
	ft_reverse_rotate(&stack_a, &stack_b, 'b');
	print_state("rrb", stack_a, stack_b);
	ft_reverse_rotate(&stack_a, &stack_b, 'r');
	print_state("rrr", stack_a, stack_b);
	ft_push(&stack_a, &stack_b, 'a');
	print_state("pa", stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
