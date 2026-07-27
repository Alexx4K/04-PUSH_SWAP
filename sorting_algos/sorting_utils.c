/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:02:49 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/27 17:55:38 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
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
void	ft_move_pos_to_top(t_stack **stack, int pos)
{
	int	moves_remaining;

	if (pos <= ft_lstsize(*stack) / 2)
	{
		moves_remaining = pos;
		while (moves_remaining > 0)
		{
			ft_list_rotate(stack);
			moves_remaining--;
		}
	}
	else
	{
		moves_remaining = ft_lstsize(*stack) - pos;
		while (moves_remaining > 0)
		{
			ft_list_reverse_rotate(stack);
			moves_remaining--;
		}
	}
}
