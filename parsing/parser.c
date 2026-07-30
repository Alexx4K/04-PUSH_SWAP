/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:22:16 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/30 14:10:31 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/// @brief
/// @param str
/// @return
/// @todo Is it necessary?
static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

//@todo: is this function strcmp?
int	str_equals(const char *a, const char *b)
{
	int	i;

	i = 0;
	while (a[i] && b[i] && a[i] == b[i])
		i++;
	return (a[i] - b[i]);
}

long	str_to_long(const char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

/// @brief Stores n from arguments if its valid
/// @param str argument to convert in number
/// @param numbers
/// @param count
/// @param nbr_strs This is used to free the memory in case of error
/// @todo Why we cast the number to int. Are we working only with int??
void	store_number(char *str, int *numbers, int *count, char **nbr_strs)
{
	long	value;

	if (!is_valid_number(str))
	{
		free_all(nbr_strs, numbers);
		error_exit();
	}
	value = str_to_long(str);
	if (value > INT_MAX || value < INT_MIN)
	{
		free_all(nbr_strs, numbers);
		error_exit();
	}
	numbers[*count] = (int)value;
	(*count)++;
}

/// @brief Parses arguments and stores the numbers and flags in their arrays
/// @param nbr_strs Arguments passed by the user (everything except the program name).
/// @param flag_count list of flags (0 if not appeared, 1 if present, controls duplicate).
/// @param numbers array of numbers after atol.
/// @todo divide in two steps, first flags. When no more flags start processing
/// numbers.
/// 
void	token_parse(char **nbr_strs, int *flag_count, int *numbers)
{
	int	j;
	int	type;
	int	*count;

	j = 0;
	*count = 0;
	while (nbr_strs[j] != NULL)
	{
		type = get_flag_type(nbr_strs[j]);
		if (type != -1)
			flag_count[type]++;
		else
			store_number(nbr_strs[j], numbers, count, nbr_strs);
		j++;
	}
}
