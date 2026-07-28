/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:54:40 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/28 13:51:21 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H

# include <stdlib.h>
# include <unistd.h>

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

#endif
