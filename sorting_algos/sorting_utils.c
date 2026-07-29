/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:02:49 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/29 12:15:40 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Finds the position of a given value in the stack.
/// @param stack the stack to search for the value.
/// @param value the value to find in the stack.
/// @return the position of the value in the stack, or -1 if not found.
int	find_position(t_stack *stack, int value)
{
	int	pos;

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

/// @brief finds the minimum value in the given stack.
/// @param stack the stack to search for the minimum value.
/// @return the minimum value found in the stack.
int	find_min_value(t_stack *stack)
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

/// @brief Finds the position of an element from the interval.
/// @param stack the stack to search for the value.
/// @param chunk_min minimun value.
/// @param chunk_max maximun value.
/// @return the position of the value in the stack, or -1 if not found.
int	ft_find_first_chunk_pos(t_stack *stack, int chunk_min, int chunk_max)
{
	int	pos;

	pos = 0;
	while (stack != NULL)
	{
		if (stack->content >= chunk_min && stack->content <= chunk_max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

// Suponte que quiero hacer una funcion que, dada la posicion en la que está
// un elemento, lo suba hasta la cima del stack.
// @todo MODIFICAR TODOS LOS LIST ROTATE
void	ft_move_pos_to_top(t_stack **st_a, t_stack **st_b, int pos, char op)
{
	int	moves_remaining;
	t_stack	**selected;

	if (op == 'a')
		selected = st_a;
	else
		selected = st_b;
	if (pos <= ft_lstsize(*selected) / 2)
	{
		moves_remaining = pos;
		while (moves_remaining > 0)
		{
			ft_list_rotate(selected);
			moves_remaining--;
		}
	}
	else
	{
		moves_remaining = ft_lstsize(*selected) - pos;
		while (moves_remaining > 0)
		{
			ft_list_reverse_rotate(selected);
			moves_remaining--;
		}
	}
}
