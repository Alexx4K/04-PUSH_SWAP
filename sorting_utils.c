/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 13:02:49 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/17 16:35:35 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include "sorting_algos.h"

/// @brief Finds the position of a given value in the stack.
/// @param stack the stack to search for the value.
/// @param value the value to find in the stack. 
/// @return the position of the value in the stack, or -1 if not found.
int	find_position(t_list *stack, int value)
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
int	ft_find_first_chunk_pos(t_list *stack, int chunk_min, int chunk_max)
{
	int	pos;

	pos = 0;
	while (stack != NULL)
	{
		if (stack->content >= chunk_min || stack->content <= chunk_max)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);	
}
