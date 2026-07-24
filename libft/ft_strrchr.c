/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 14:31:50 by crubio-p          #+#    #+#             */
/*   Updated: 2026/05/28 15:06:41 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c_to_char;

	i = ft_strlen(s);
	c_to_char = (char)c;
	while (i >= 0)
	{
		if (s[i] == c_to_char)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
