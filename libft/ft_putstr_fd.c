/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 00:11:24 by cesar             #+#    #+#             */
/*   Updated: 2026/06/16 11:53:48 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
	int	write_result;

	count = 0;
	if (!s)
		return (-1);
	while (*s)
	{
		write_result = ft_putchar_fd(*s++, fd);
		if (write_result == -1)
			return (-1);
		count += write_result;
	}
	return (count);
}
