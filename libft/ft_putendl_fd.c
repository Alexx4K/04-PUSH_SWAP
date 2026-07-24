/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 00:12:42 by cesar             #+#    #+#             */
/*   Updated: 2026/06/16 11:54:33 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count;
	int	write_result;

	if (!s)
		return (-1);
	count = 0;
	write_result = ft_putstr_fd(s, fd);
	if (write_result == -1)
		return (-1);
	count += write_result;
	write_result = ft_putchar_fd('\n', fd);
	if (write_result == -1)
		return (-1);
	return (count + write_result);
}
