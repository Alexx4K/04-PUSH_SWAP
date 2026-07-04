/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:31:57 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/04 11:59:41 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

/// @brief Swaps the first two elements of the given stack.
/// @param stack Pointer to the stack to operate on.
static void	ft_list_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	*stack = second;
}

static void ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_list_swap(stack_a);
	ft_list_swap(stack_b);
}

/// @brief Swaps the first two elements of the given stack(s) based on the 
/// operation character.
/// @param stack_a Stack A
/// @param stack_b Stack B
/// @param operation Character indicating which stack(s) to operate on.
void	ft_swap(t_list **stack_a, t_list **stack_b, char operation)
{
	if (operation == 'a')
		ft_list_swap(stack_a);
	else if (operation == 'b')
		ft_list_swap(stack_b);
	else if (operation == 's')
		ft_ss(stack_a, stack_b);
}
