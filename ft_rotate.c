/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:31:30 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/02 15:52:51 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

static void ft_list_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

static void ft_list_reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*prev_to_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_lstlast(*stack);
	prev_to_last = *stack;
	while (prev_to_last->next != last)
		prev_to_last = prev_to_last->next;
	prev_to_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

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
