/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio-p <crubio-p@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 12:05:19 by crubio-p          #+#    #+#             */
/*   Updated: 2026/07/30 13:05:34 by crubio-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/// @brief
/// @param num_arg
/// @param argv
// Leer flags.
// Leer números.
// 
void	push_swap(int num_arg, char **argv)
{

}

int	main(int argc, char **argv)
{
	if (argc <= 1)
	{
		return(0);
	}
	else
		push_swap(argc - 1 , ++argv);
	return (0);
}
