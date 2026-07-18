/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesar <cesar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 10:42:01 by cesar             #+#    #+#             */
/*   Updated: 2026/07/18 11:09:18 by cesar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "link.h"
#include "sorting_algos.h"

/// @brief Calculates the nearest perfect square root.
/// @param n
/// @return The nearest perfect square.
static	int	ft_nearest_perfect_sqrt(int	n)
{
	int	i;

	if (n < 1)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

/// @brief
/// @param stack_a
/// @param stack_b
/// @param n_elems
void	ft_chunksort(t_list **stack_a, t_list **stack_b, int n_elems)
{
	int	chunk_size;

	chunk_size = ft_nearest_perfect_sqrt(n_elems);
	

}

/// @brief
/// @param stack_a
/// @param stack_b
void	ft_prechunksort(t_list **stack_a, t_list **stack_b)
{
	int	n_elems;

	n_elems = ft_lstsize(*stack_a);
	ft_chunksort(stack_a, stack_b, n_elems);
}
