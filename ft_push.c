/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:22:13 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/04 16:53:07 by crubio-p         ###   ########.fr       */
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
	if (*src)
		(*src)->prev = NULL;
	temp_top->next = *dest;
	if (*dest)
		(*dest)->prev = temp_top;
	*dest = temp_top;
}

/// @brief Pushes the top element from one stack to another based on the 
/// operation character.
/// @param stack_a Stack A
/// @param stack_b Stack B
/// @param operation Character indicating which stack(s) to operate on.
void	ft_push(t_list **stack_a, t_list **stack_b, char operation)
{
	if (operation == 'a')
		ft_list_push(stack_b, stack_a);
	if (operation == 'b')
		ft_list_push(stack_a, stack_b);
}
