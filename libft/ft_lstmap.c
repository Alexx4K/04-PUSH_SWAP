/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 15:53:46 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/05 14:17:04 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_front;
	t_list	*actual;
	void	*content;

	lst_front = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		actual = ft_lstnew(content);
		if (actual == NULL)
		{
			del(content);
			ft_lstclear(&lst_front, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_front, actual);
		lst = lst->next;
	}
	return (lst_front);
}
