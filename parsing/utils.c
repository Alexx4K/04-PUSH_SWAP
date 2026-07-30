/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarellan <aarellan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 18:33:30 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/28 18:33:37 by aarellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Exits the program with an error message.
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

/// @brief Frees the split array.
/// @param arr The array to free.
void	free_split(char **arr)
{
	int	j;

	j = 0;
	while (arr[j])
		free(arr[j++]);
	free(arr);
}

/// @brief Frees all the memory allocated for the program.
/// @param nbr_strs The array of number strings.
/// @param numbers The array of numbers.
void	free_all(char **nbr_strs, int *numbers)
{
	if (nbr_strs)
		free_split(nbr_strs);
	if (numbers)
		free(numbers);
}

/// @brief Checks if there are duplicates in the array.
/// @param numbers The array to check.
/// @param count The number of elements in the array.
/// @return 1 if there are duplicates, 0 otherwise.
int	has_duplicates(int *numbers, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/// @brief Computes the maximum size of the array.
/// @param argc The number of arguments.
/// @param argv The array of arguments.
/// @return The maximum size of the array.
int	compute_max_size(int argc, char **argv)
{
	int	i;
	int	max_size;

	max_size = 0;
	i = 1;
	while (i < argc)
		max_size += ft_strlen(argv[i++]);
	return (max_size);
}
