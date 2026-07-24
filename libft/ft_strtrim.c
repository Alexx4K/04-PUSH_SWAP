/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 20:35:27 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/04 10:03:04 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Parameters:
		- memchr cogiendo el set y haciendo un memchr con los caracteres
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	set_len;
	size_t	s1_len;

	start = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	while (start < s1_len && ft_memchr(set, s1[start], set_len) != NULL)
	{
		start++;
	}
	end = s1_len - 1;
	while (end >= start && ft_memchr(set, s1[end], set_len) != NULL)
	{
		end--;
	}
	return (ft_substr(s1, start, end - start + 1));
}
