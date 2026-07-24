/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/02 12:22:01 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/24 18:14:07 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

/// @brief Creates a node of t_stack type.
/// @param content The content in the node.
/// @return The pointer to that t_stack
t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

/// @brief Finds the last element in the list.
/// @param lst
/// @return A pointer tu the last element.
t_stack	*ft_lstlast(t_stack *lst)
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
int	ft_lstsize(t_stack *lst)
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
