#ifndef SORTING_ALGOS_H
# define SORTING_ALGOS_H

# include "linked_lists.h"

int		find_position(t_list *stack, int value);
int		ft_find_first_chunk_pos(t_list *stack, int chunk_min, int chunk_max);
void	sort_selection(t_list **stack_a, t_list **stack_b);
void	ft_move_pos_to_top(t_list **stack, int pos);

#endif
