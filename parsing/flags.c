/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:59:09 by aarellan          #+#    #+#             */
/*   Updated: 2026/08/04 12:53:48 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Gets the type of the flag.
/// @param str The flag to get the type of.
/// @return The type of the flag.
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

/// @brief Checks if there is a conflict between flags.
/// @param counts Array of flag counts.
/// @return 1 if there is a conflict, 0 otherwise.
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

/// @brief Checks if there are duplicated flags.
/// @param counts Array of flag counts.
/// @return 1 if there is a conflict, 0 otherwise.
int	has_duplicated_flags(int *counts)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (counts[i] > 1)
			return (1);		
		i++;
	}
	return (0);
}

/// @brief Initializes the flag counts.
/// @param flag_count Array of flag counts.
void	ft_init_flags(int *flag_count)
{
	int	i;

	i = 0;
	while (i < 5)
		flag_count[i++] = 0;
}
