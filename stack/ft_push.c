/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:22:13 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/28 13:52:18 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

/// @brief Pushes the element in the top of the non-empty src list to
/// the dest list.
/// @param src Top element's source.
/// @param dest Destination.
static void	ft_list_push(t_stack **src, t_stack **dest)
{
	t_stack	*temp_top;

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
void	ft_push(t_stack **stack_a, t_stack **stack_b, char operation, int fd)
{
	if (operation == 'a')
	{
		ft_list_push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
	if (operation == 'b')
	{
		ft_list_push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
}
