/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:31:30 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/14 13:43:35 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

void	ft_list_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

void	ft_list_reverse_rotate(t_list **stack)
{
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/// @brief Puts the first element of the stack at the bottom, effectively
/// rotating the stack upwards.
/// @param stack_a Stack A
/// @param stack_b Stack B
/// @param operation Character indicating which stack(s) to operate on.
void	ft_rotate(t_list **stack_a, t_list **stack_b, char operation)
{
	if (operation == 'a')
		ft_list_rotate(stack_a);
	else if (operation == 'b')
		ft_list_rotate(stack_b);
	else if (operation == 'r')
	{
		ft_list_rotate(stack_a);
		ft_list_rotate(stack_b);
	}
}

/// @brief Puts the last element of the stack at the top, effectively rotating
/// the stack downwards.
/// @param stack_a Stack A
/// @param stack_b Stack B
/// @param operation Character indicating which stack(s) to operate on.
void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b, char operation)
{
	if (operation == 'a')
		ft_list_reverse_rotate(stack_a);
	else if (operation == 'b')
		ft_list_reverse_rotate(stack_b);
	else if (operation == 'r')
	{
		ft_list_reverse_rotate(stack_a);
		ft_list_reverse_rotate(stack_b);
	}
}
