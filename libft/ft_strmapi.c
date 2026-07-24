/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 00:08:54 by cesar             #+#    #+#             */
/*   Updated: 2026/06/01 13:56:18 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Applies the function 'f' to each character of the string 's' and saves the
	result in a new array 'new_s'.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*new_s;

	i = 0;
	len = ft_strlen(s);
	new_s = ft_calloc((len + 1), sizeof(char));
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[i] = (f)(i, s[i]);
		i++;
	}
	return (new_s);
}
