/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:22:01 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/18 13:18:19 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

/// @brief Creates a node of t_list type.
/// @param content The content in the node.
/// @return The pointer to that t_list
t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->index = -1;
	return (new_node);
}

/// @brief Finds the last element in the list.
/// @param lst
/// @return A pointer tu the last element.
t_list	*ft_lstlast(t_list *lst)
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
int	ft_is_empty(const t_list *stack)
{
	return (stack == NULL);
}

/// @brief Counts the number of elements in the list.
/// @param lst
/// @return The size of the list.
int	ft_lstsize(t_list *lst)
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
