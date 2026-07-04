/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:48:38 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/04 18:04:50 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

static void	move_pos_to_top(t_list **stack, int pos, char operation);

void sort_selection(t_list **stack_a, t_list **stack_b)
{
    int pos;

    while (stack_size(*stack_a) > 0)
    {
        pos = find_max_pos(stack_a);
        move_pos_to_top(stack_a, pos, 'a');
        pb(stack_a, stack_b);
    }
    while (ft_lstsize(*stack_b) > 0)
        pa(stack_a, stack_b);
}
