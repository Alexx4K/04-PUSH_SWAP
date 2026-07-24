/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 23:30:00 by cesar             #+#    #+#             */
/*   Updated: 2026/05/29 19:04:34 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*to_char1;
	unsigned char	*to_char2;

	to_char1 = (unsigned char *)s1;
	to_char2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (to_char1[i] != to_char2[i])
			return (to_char1[i] - to_char2[i]);
		i++;
	}
	return (0);
}
