/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:04:33 by cesar             #+#    #+#             */
/*   Updated: 2026/07/24 19:57:19 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_ALGOS_H
# define SORTING_ALGOS_H

# include "linked_lists.h"

int		find_position(t_stack *stack, int value);
int		ft_find_first_chunk_pos(t_stack *stack, int chunk_min, int chunk_max);
void	sort_selection(t_stack **stack_a, t_stack **stack_b);
void	ft_move_pos_to_top(t_stack **stack, int pos);
void	ft_prechunksort(t_stack **stack_a, t_stack **stack_b);
void	ft_radix_sort(t_stack **stack_a, t_stack **stack_b);
float	ft_compute_disorder(t_stack *stack);
void	ft_exec_strategy_dispatch(t_stack **stack_a, t_stack **stack_b,
			int forced_strat, float disorder);

#endif
