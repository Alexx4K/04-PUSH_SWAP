/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 11:54:40 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/02 15:22:46 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

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

// Double stash functions
void	ft_swap(t_list **stack_a, t_list **stack_b, char operation);
void	ft_push(t_list **stack_a, t_list **stack_b, char operation);
void	ft_rotate(t_list **stack_a, t_list **stack_b, char operation);	
void	ft_reverse_rotate(t_list **stack_a, t_list **stack_b, char operation);

#endif
