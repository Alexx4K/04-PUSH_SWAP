/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:15:00 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/27 12:20:20 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include "sorting_algos.h"

void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = ft_lstsize(*stack_a);
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->content >> i) & 1) == 1)
				ft_rotate(stack_a, stack_b, 'a');
			else
				ft_push(stack_a, stack_b, 'b');
			j++;
		}
		while (*stack_b)
			ft_push(stack_a, stack_b, 'a');
		i++;
	}
}
