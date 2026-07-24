/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_algos.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:04:33 by cesar             #+#    #+#             */
/*   Updated: 2026/07/24 18:14:07 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_ALGOS_H
# define SORTING_ALGOS_H

# include "linked_lists.h"

int		find_position(t_stack *stack, int value);
int		ft_find_first_chunk_pos(t_stack *stack, int chunk_min, int chunk_max);
void	sort_selection(t_stack **stack_a, t_stack **stack_b);
void	ft_move_pos_to_top(t_stack **stack, int pos);

#endif
