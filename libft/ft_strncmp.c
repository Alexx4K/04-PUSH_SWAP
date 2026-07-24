/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 16:44:29 by crubio-p          #+#    #+#             */
/*   Updated: 2026/06/01 13:38:39 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
/* 
#include <unistd.h>

int	n_len(int n)
{
	int		len;
	long	num;

	num = n;
	len = (n <= 0);
	while (num)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

void	ft_print_result(int n)
{
	write(1, ft_itoa(n), n_len(n));
	write(1, "\n", 1);
	if (n > 0)
		write(1, "1", 1);
	else if (n < 0)
		write(1, "-1", 2);
	else
		write(1, "0", 1);
}
int	main(void)
{
	ft_print_result(ft_strncmp("test\200", "test\0", 6));
	return (0);
}
 */
