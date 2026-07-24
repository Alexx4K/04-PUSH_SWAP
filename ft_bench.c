/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarellan <aarellan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 19:10:00 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/24 13:28:53 by aarellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_lists.h"
#include <unistd.h>
#include <stdio.h>

int	*ft_get_ops_count(void)
{
	static int	ops_count[12] = {0};

	return (ops_count);
}

int	*ft_get_bench_flag(void)
{
	static int	bench_flag = 0;

	return (&bench_flag);
}

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
