/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:24:30 by cesar             #+#    #+#             */
/*   Updated: 2026/05/29 19:03:17 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*to_char;
	size_t			i;

	to_char = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (to_char[i] == (unsigned char)c)
			return ((void *)&to_char[i]);
		i++;
	}
	return (NULL);
}
