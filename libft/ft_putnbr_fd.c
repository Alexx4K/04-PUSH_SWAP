/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/31 00:13:12 by cesar             #+#    #+#             */
/*   Updated: 2026/06/16 11:54:45 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;
	int			count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		count++;
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		count += ft_putnbr_fd(nbr / 10, fd);
		count += ft_putnbr_fd(nbr % 10, fd);
	}
	else
	{
		count += ft_putchar_fd(nbr + '0', fd);
	}
	return (count);
}
