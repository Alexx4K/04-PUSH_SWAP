/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 23:43:25 by cesar             #+#    #+#             */
/*   Updated: 2026/06/05 15:31:46 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	**ft_free(char **tab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_split_str(char **array, char *str, char c, size_t n)
{
	size_t	i;
	char	*start;

	i = 0;
	while (i < n)
	{
		while (*str && *str == c)
			str++;
		start = str;
		while (*str && *str != c)
			str++;
		array[i] = ft_substr(start, 0, str - start);
		if (array[i] == NULL)
		{
			return (ft_free(array, i));
		}
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		n_words;

	if (!s)
		return (NULL);
	n_words = ft_count_words(s, c);
	array = (char **)ft_calloc((n_words + 1), sizeof(char *));
	if (!array)
		return (NULL);
	array = ft_split_str(array, (char *)s, c, n_words);
	return (array);
}
