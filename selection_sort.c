/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:03:22 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/17 13:07:06 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include "sorting_algos.h"

/// @brief Moves the specified value to the top of the stack using rotations or 
/// reverse rotations based on its position.
/// @param stack the stack in which the value is to be moved.
/// @param value the value to be moved to the top of the stack.
static void	move_value_to_top(t_list **stack, int value)
{
	int	pos;

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

/// @brief finds the minimum value in the given stack.
/// @param stack the stack to search for the minimum value.
/// @return the minimum value found in the stack. 
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

/// @brief Sorts the elements in stack_a using the selection sort algorithm and 
/// moves them to stack_b, then moves them back to stack_a in sorted order.
/// @param stack_a 
/// @param stack_b 
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
