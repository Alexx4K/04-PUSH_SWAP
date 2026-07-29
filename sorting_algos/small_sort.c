/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:23:28 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/29 13:45:23 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2_elems(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap(stack_a, stack_b, 'a');

}

void	sort_3_elems(t_stack **stack_a, t_stack **stack_b)
{
	int	first;
	int	second;
	int third;

	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
	if (first > second && first < third && second < third)
		ft_swap(stack_a, stack_b, 'a');
	else if (first > second && first > third && second < third)
		ft_rotate(stack_a, stack_b, 'a');
	else if (first < second && first > third && second > third)
		ft_reverse_rotate(stack_a, stack_b, 'a');
	else if (first < second && first < third && second > third)
	{
		ft_swap(stack_a, stack_b, 'a');
		ft_rotate(stack_a, stack_b, 'a');
	}
	else if (first > second && first > third && second > third)
	{
		ft_swap(stack_a, stack_b, 'a');
		ft_reverse_rotate(stack_a, stack_b, 'a');
	}
}

void	sort_4_elems(t_stack **stack_a, t_stack **stack_b)
{
	int	min_value_pos;

	min_value_pos = find_min_value(*stack_a);
	ft_move_pos_to_top(stack_a, stack_b, min_value_pos, 'a');
	ft_push(stack_a, stack_b, 'b');
	sort_3_elems(stack_a, stack_b);
	ft_push(stack_a, stack_b, 'a');
}

void	sort_5_elems(t_stack **stack_a, t_stack **stack_b)
{
	int	min_value_pos;

	min_value_pos = find_min_value(*stack_a);
	ft_move_pos_to_top(stack_a, stack_b, min_value_pos, 'a');
	ft_push(stack_a, stack_b, 'b');
	sort_4_elems(stack_a, stack_b);
	ft_push(stack_a, stack_b, 'a');
}
