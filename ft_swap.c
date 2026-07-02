/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:31:57 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/02 15:23:20 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

static void	ft_list_swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}
static void ft_ss(t_list **stack_a, t_list **stack_b)
{
	ft_list_swap(stack_a);
	ft_list_swap(stack_b);
}

void	ft_swap(t_list **stack_a, t_list **stack_b, char operation)
{
	if (operation == 'a')
		ft_list_swap(stack_a);
	else if (operation == 'b')
		ft_list_swap(stack_b);
	else if (operation == 's')
		ft_ss(stack_a, stack_b);
}
