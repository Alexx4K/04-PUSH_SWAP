/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:46:51 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/04 12:18:21 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*to_delete;

	to_delete = *lst;
	while (to_delete != NULL)
	{
		tmp = to_delete->next;
		ft_lstdelone(to_delete, (del));
		to_delete = tmp;
	}
	*lst = NULL;
}
