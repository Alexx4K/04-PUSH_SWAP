/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarellan <aarellan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:10:00 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/28 18:35:07 by aarellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @todo meter printf y recortar la libft

/// @brief Gets the operations count array.
/// @return The operations count array.
int	*ft_get_ops_count(void)
{
	static int	ops_count[12] = {0};

	return (ops_count);
}

/// @brief Gets the benchmark flag.
/// @return The benchmark flag.
int	*ft_get_bench_flag(void)
{
	static int	bench_flag = 0;

	return (&bench_flag);
}

/// @brief Prints the strategy used.
/// @param state The state of the strategy.
/// @param disorder The disorder of the stack.
static void	ft_print_strategy(int state, float disorder)
{
	fprintf(stderr, "[bench] strategy: ");
	if (state == 0)
		fprintf(stderr, "Simple / O(n2)\n");
	else if (state == 1)
		fprintf(stderr, "Medium / O(n√n)\n");
	else if (state == 2)
		fprintf(stderr, "Complex / O(n log n)\n");
	else
	{
		if (disorder < 0.2)
			fprintf(stderr, "Adaptive / O(n2)\n");
		else if (disorder < 0.5)
			fprintf(stderr, "Adaptive / O(n√n)\n");
		else
			fprintf(stderr, "Adaptive / O(n log n)\n");
	}
}
