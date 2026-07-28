/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarellan <aarellan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:59:09 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/28 18:33:54 by aarellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_flag_type(const char *str)
{
	if (str_equals(str, "--simple") == 0)
		return (1);
	if (str_equals(str, "--medium") == 0)
		return (2);
	if (str_equals(str, "--complex") == 0)
		return (3);
	if (str_equals(str, "--adaptive") == 0)
		return (4);
	if (str_equals(str, "--bench") == 0)
		return (5);
	return (0);
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
