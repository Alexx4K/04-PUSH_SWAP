/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarellan <aarellan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:15:55 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/28 15:55:23 by aarellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"

/// @brief Creates a new node for the stack with the given value
/// @param value The value to be stored in the new node
t_stack	*new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = value;
	node->next = NULL;
	return (node);
}

/// @brief Builds a doubly linked list (stack) from an array of integers
t_stack	*build_list(int *numbers, int count)
{
	t_stack	*list;
	t_stack	*node;
	int		i;

	list = NULL;
	i = 0;
	while (i < count)
	{
		node = new_node(numbers[i]);
		if (!node)
			return (NULL);
		node->next = list;
		list = node;
		i++;
	}
	return (list);
}

