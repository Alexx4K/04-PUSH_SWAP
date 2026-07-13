/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_selection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 17:48:38 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/13 17:46:28 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

/// @brief rotates the stack until pos is in the top
/// @param stack
/// @param value
/// @param operation
static void	move_pos_to_top(t_list **stack, int value, char operation)
{}

/// @brief Finds the lowest number in the stack and returns it
/// @param stack THE stack
/// @return the value of the lowest number in the stack
static int  find_min_value(t_list *stack)
{
    int min;

    min = stack->content;
    while(stack->next != NULL)
    {
        if (min > stack->next->content)
            min = stack->next->content;
        stack = stack->next;
    }
    return (min);
}

void sort_selection(t_list **stack_a, t_list **stack_b)
{
    int value;

    while (!ft_is_empty(*stack_a))
    {
        value = find_min_value(stack_a);
        move_pos_to_top(stack_a, value, 'a');
        ft_push(stack_a, stack_b, 'b');
    }
    while (!ft_is_empty(*stack_b))
        ft_push(stack_a, stack_b, 'a');
}
