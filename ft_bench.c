/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p, aarellan <crubio-p, aarellan@stu +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:10:00 by aarellan          #+#    #+#             */
/*   Updated: 2026/08/02 20:27:44 by crubio-p, aarell ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Gets the per-operation counters (static, shared array).
/// @return Pointer to the first slot of the OP_COUNT-sized array.
static int	*get_counts(void)
{
	static int	counts[OP_COUNT];

	return (counts);
}

/// @brief Resets every operation counter to zero.
void	bench_reset(void)
{
	int	*counts;
	int	i;

	counts = get_counts();
	i = 0;
	while (i < OP_COUNT)
		counts[i++] = 0;
}

/// @brief Increments the counter matching the given operation.
/// @param op The kind of operation that was just executed.
void	bench_count_op(t_bench_op op)
{
	get_counts()[op]++;
}

/// @brief Names the strategy actually used, together with its complexity
/// class. When forced_strat is -1 (adaptive), the class shown is the one
/// picked for the measured disorder.
static const char	*strategy_label(int forced_strat, float disorder)
{
	if (forced_strat == 0)
		return ("Simple / O(n^2)");
	if (forced_strat == 1)
		return ("Medium / O(n\xE2\x88\x9An)");
	if (forced_strat == 2)
		return ("Complex / O(n log n)");
	if (disorder < 0.2f)
		return ("Adaptive / O(n^2)");
	if (disorder < 0.5f)
		return ("Adaptive / O(n\xE2\x88\x9An)");
	return ("Adaptive / O(n log n)");
}

/// @brief Prints the benchmark summary to stderr: disorder ratio, strategy
/// used, total operations and the breakdown per operation type.
/// @param disorder The disorder ratio of the original stack (0.0 - 1.0).
/// @param forced_strat The strategy used (-1 = adaptive, 0-2 = forced).
void	bench_print(float disorder, int forced_strat)
{
	int	*c;
	int	total;
	int	i;

	c = get_counts();
	total = 0;
	i = 0;
	while (i < OP_COUNT)
		total += c[i++];
	fprintf(stderr, "[bench] disorder:   %.2f%%\n", disorder * 100);
	fprintf(stderr, "[bench] strategy:   %s\n",
		strategy_label(forced_strat, disorder));
	fprintf(stderr, "[bench] total_ops:  %d\n", total);
	fprintf(stderr, "[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		c[OP_SA], c[OP_SB], c[OP_SS], c[OP_PA], c[OP_PB]);
	fprintf(stderr, "[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		c[OP_RA], c[OP_RB], c[OP_RR], c[OP_RRA], c[OP_RRB], c[OP_RRR]);
}
