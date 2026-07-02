/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:22:13 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/02 15:28:38 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

static void	ft_list_push(t_list **src, t_list **dest)
{
	t_list	*temp_top;
	
	if (!src || !*src)
		return ;
	temp_top = *src;
	*src = (*src)->next;
	temp_top->next = *dest;
	*dest = temp_top;
}

void	ft_push(t_list **stack_a, t_list **stack_b, char operation)
{
	if (operation == 'a')
		ft_list_push(stack_b, stack_a);
	if (operation == 'b')
		ft_list_push(stack_a, stack_b);
}
