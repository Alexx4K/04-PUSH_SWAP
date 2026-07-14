/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:54:40 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/14 13:44:46 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LISTS_H
# define LINKED_LISTS_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// Linked list basic functions
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_is_empty(const t_list *stack);
int		ft_lstsize(t_list *lst);

// Double stash functions
void	ft_swap(t_list **stack_a, t_list **stack_b, char operation);
void	ft_push(t_list **stack_a, t_list **stack_b, char operation);
void	ft_list_rotate(t_list **stack);
void	ft_rotate(t_list **stack_a, t_list **stack_b, char operation);
void	ft_list_reverse_rotate(t_list **stack);
void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b, char operation);

#endif
