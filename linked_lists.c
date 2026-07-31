/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarellan <aarellan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:22:01 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/30 18:00:00 by aarellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Creates a node of t_stack type.
/// @param content The content in the node.
/// @return The pointer to that t_stack
t_stack	*ps_lstnew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/// @brief Finds the last element in the list.
/// @param lst
/// @return A pointer to the last element.
t_stack	*ps_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/// @brief If the stack is NULL, it means that it's empty
/// @param stack
/// @return 1 if empty, 0 if not.
int	ft_is_empty(const t_stack *stack)
{
	return (stack == NULL);
}

/// @brief Counts the number of elements in the list.
/// @param lst
/// @return The size of the list.
int	ps_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
