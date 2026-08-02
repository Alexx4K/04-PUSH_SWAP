/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p, aarellan <crubio-p, aarellan@stu +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 15:31:30 by crubio-p          #+#    #+#             */
/*   Updated: 2026/08/02 20:27:21 by crubio-p, aarell ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Rotates the stack to the top.
/// @param stack The stack to rotate.
void	ft_list_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ps_lstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

/// @brief Rotates the stack to the bottom.
/// @param stack The stack to rotate.
void	ft_list_reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ps_lstlast(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/// @brief Puts the first element of the stack at the bottom, effectively
/// rotating the stack upwards.
/// @param stack_a Stack A
/// @param stack_b Stack B
/// @param operation Character indicating which stack(s) to operate on.
void	ft_rotate(t_stack **stack_a, t_stack **stack_b, char operation)
{
	if (operation == 'a')
	{
		ft_list_rotate(stack_a);
		bench_count_op(OP_RA);
		write(1, "ra\n", 3);
	}
	else if (operation == 'b')
	{
		ft_list_rotate(stack_b);
		bench_count_op(OP_RB);
		write(1, "rb\n", 3);
	}
	else if (operation == 'r')
	{
		ft_list_rotate(stack_a);
		ft_list_rotate(stack_b);
		bench_count_op(OP_RR);
		write(1, "rr\n", 3);
	}
}

/// @brief Puts the last element of the stack at the top, effectively rotating
/// the stack downwards.
/// @param stack_a Stack A
/// @param stack_b Stack B
/// @param operation Character indicating which stack(s) to operate on.
void	ft_reverse_rotate(t_stack **stack_a, t_stack **stack_b, char operation)
{
	if (operation == 'a')
	{
		ft_list_reverse_rotate(stack_a);
		bench_count_op(OP_RRA);
		write(1, "rra\n", 4);
	}
	else if (operation == 'b')
	{
		ft_list_reverse_rotate(stack_b);
		bench_count_op(OP_RRB);
		write(1, "rrb\n", 4);
	}
	else if (operation == 'r')
	{
		ft_list_reverse_rotate(stack_a);
		ft_list_reverse_rotate(stack_b);
		bench_count_op(OP_RRR);
		write(1, "rrr\n", 4);
	}
}
