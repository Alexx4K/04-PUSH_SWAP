/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:27:45 by plopez-l          #+#    #+#             */
/*   Updated: 2026/07/24 19:38:15 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
// @todo comprobar que librerías son necesarias.

//parser.c

int		is_valid_number(const char *str);
int		str_equals(const char *a, const char *b);
long	str_to_long(const char *str);
void	store_number(char *str, int *numbers, int *count, char **nbr_strs);
void	parse_tokens(char **nbr_strs, int *flag_count, int *numbers, int *count);

//utils.c

void	error_exit(void);
void	free_split(char **arr);
void	free_all(char **nbr_strs, int *numbers);
int		has_duplicates(int *numbers, int count);
int		compute_max_size(int argc, char **argv);

//flags.c

int		get_flag_type(const char *str);
int		has_conflict(int *counts);
void	ft_init_flags(int *flag_count);

//list_utils.c

t_stack	*new_node(int value);
t_stack	*build_list(int *numbers, int count);


// PHASE 2: Stacks and Sorting

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// Linked list basic functions
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_is_empty(const t_stack *stack);
int		ft_lstsize(t_stack *lst);

// Double stash functions
void	ft_swap(t_stack **stack_a, t_stack **stack_b, char operation);
void	ft_push(t_stack **stack_a, t_stack **stack_b, char operation);
void	ft_list_rotate(t_stack **stack);
void	ft_rotate(t_stack **stack_a, t_stack **stack_b, char operation);
void	ft_list_reverse_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack_a, t_stack **stack_b, char operation);


//Sorting algos + utils
int		find_position(t_stack *stack, int value);
int		ft_find_first_chunk_pos(t_stack *stack, int chunk_min, int chunk_max);
void	sort_selection(t_stack **stack_a, t_stack **stack_b);
void	ft_move_pos_to_top(t_stack **stack, int pos);


#endif
