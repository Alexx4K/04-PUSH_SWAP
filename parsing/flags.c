/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:59:09 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/30 13:24:36 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_simple(int *flag_count)
{
	return (flag_count[0] > 0);
}

int	is_medium(int *flag_count)
{
	return (flag_count[1] > 0);
}

int	is_complex(int *flag_count)
{
	return (flag_count[2] > 0);
}

int	is_adaptive(int *flag_count)
{
	return (flag_count[3] > 0);
}

int	is_bench(int *flag_count)
{
	return (flag_count[4] > 0);
}

int	get_flag_type(const char *str)
{
	if (str_equals(str, "--simple") == 0)
		return (0);
	if (str_equals(str, "--medium") == 0)
		return (1);
	if (str_equals(str, "--complex") == 0)
		return (2);
	if (str_equals(str, "--adaptive") == 0)
		return (3);
	if (str_equals(str, "--bench") == 0)
		return (4);
	return (-1);
}

int	has_conflict(int *counts)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < 4)
	{
		if (counts[i] > 0)
			total++;
		i++;
	}
	return (total > 1);
}

void	ft_init_flags(int *flag_count)
{
	int	i;

	i = 0;
	while (i < 5)
		flag_count[i++] = 0;
}
