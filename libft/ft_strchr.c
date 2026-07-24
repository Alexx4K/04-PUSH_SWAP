/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 13:42:23 by crubio-p          #+#    #+#             */
/*   Updated: 2026/05/28 14:40:10 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_to_char;

	i = 0;
	c_to_char = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == c_to_char)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && c_to_char == '\0')
		return ((char *)&s[i]);
	return (0);
}
