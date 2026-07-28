/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarellan <aarellan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:03:22 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/28 18:27:16 by aarellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief finds the minimum value in the given stack.
/// @param stack the stack to search for the minimum value.
/// @return the minimum value found in the stack.
static int	find_min_value(t_stack *stack)
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
/// @todo change so it goes index by index.
void	sort_selection(t_stack **stack_a, t_stack **stack_b)
{
	int	value;
	int	pos;

	while (!ft_is_empty(*stack_a))
	{
		value = find_min_value(*stack_a);
		pos = find_position(*stack_a, value);
		ft_move_pos_to_top(stack_a, stack_b, pos, 'a');
		ft_push(stack_a, stack_b, 'b');
	}
	while (!ft_is_empty(*stack_b))
		ft_push(stack_a, stack_b, 'a');
}
