/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:16:00 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/24 18:16:40 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include "sorting_algos.h"

float	ft_compute_disorder(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;
	int		total_pairs;
	int		mistakes;

	if (!stack || !stack->next)
		return (0.0);
	total_pairs = 0;
	mistakes = 0;
	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->content > j->content)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	return ((float)mistakes / total_pairs);
}

void	ft_exec_strategy_dispatch(t_stack **stack_a, t_stack **stack_b,
			int forced_strat, float disorder)
{
	if (forced_strat == 0)
		sort_selection(stack_a, stack_b);
	else if (forced_strat == 1)
		ft_prechunksort(stack_a, stack_b);
	else if (forced_strat == 2)
		ft_radix_sort(stack_a, stack_b);
	else
	{
		if (disorder >= 0.5)
			ft_radix_sort(stack_a, stack_b);
		else if (disorder >= 0.2)
			ft_prechunksort(stack_a, stack_b);
		else
			sort_selection(stack_a, stack_b);
	}
}
