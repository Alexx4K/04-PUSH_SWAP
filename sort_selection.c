#include "linked_lists.h"

#include "sorting_algos.h"

int	find_position(t_list *stack, int value)
{
	int pos;

	pos = 0;
	while (stack != NULL)
	{
		if (stack->content == value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

static void	move_value_to_top(t_list **stack, int value)
{
	int pos;

	pos = find_position(*stack, value);
	if (pos <= ft_lstsize(*stack) / 2)
	{
		while ((*stack)->content != value)
			ft_list_rotate(stack);
	}
	else
	{
		while ((*stack)->content != value)
			ft_list_reverse_rotate(stack);
	}
}

static int	find_min_value(t_list *stack)
{
    int	min;

	min = stack->content;
	while (stack->next != NULL)
	{
		if (min > stack->next->content)
			min = stack->next->content;
		stack = stack->next;
	}
	return (min);
}

void	sort_selection(t_list **stack_a, t_list **stack_b)
{
    int	value;

	while (!ft_is_empty(*stack_a))
	{
		value = find_min_value(*stack_a);
		move_value_to_top(stack_a, value);
		ft_push(stack_a, stack_b, 'b');
	}
	while (!ft_is_empty(*stack_b))
		ft_push(stack_a, stack_b, 'a');
}
