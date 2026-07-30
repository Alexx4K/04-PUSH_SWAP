/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarellan <aarellan@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:49:18 by aarellan          #+#    #+#             */
/*   Updated: 2026/07/28 14:49:18 by aarellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief Counts the number of tokens in the arguments.
/// @param argc The number of arguments.
/// @param argv The arguments.
/// @return The number of tokens.
static int	count_tokens(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**parts;

	count = 0;
	i = 1;
	while (i < argc)
	{
		parts = ft_split(argv[i], ' ');
		if (!parts)
			return (-1);
		j = 0;
		while (parts[j])
			j++;
		count += j;
		j = 0;
		while (parts[j])
			free(parts[j++]);
		free(parts);
		i++;
	}
	return (count);
}

/// @todo Menos variables y 25 lineas maximo
int	main(int argc, char **argv)
{
	int	total;
	char		**parts;
	char		**all_tokens;
	int		idx;
	int		i;
	int		j;
	int		*numbers;
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*indexed;

	if (argc < 2)
		return (0);
	total = count_tokens(argc, argv);
	if (total <= 0)
		return (0);
	all_tokens = malloc((total + 1) * sizeof(char *));
	if (!all_tokens)
		return (0);
	idx = 0;
	i = 1;
	while (i < argc)
	{
		parts = ft_split(argv[i], ' ');
		j = 0;
		while (parts[j])
			all_tokens[idx++] = parts[j++];
		free(parts);
		i++;
	}
	all_tokens[idx] = NULL;
	numbers = malloc(total * sizeof(int));
	if (!numbers)
	{
		free(all_tokens);
		return (0);
	}
	count = 0;
	int		flag_count[5] = {0};
	int		forced_strat;
	int		bench_mode;

	parse_tokens(all_tokens, flag_count, numbers, &count);
	if (has_duplicates(numbers, count))
	{
		free_all(all_tokens, numbers);
		error_exit();
	}
	if (flag_count[0] > 0)
		forced_strat = 0;
	else if (flag_count[1] > 0)
		forced_strat = 1;
	else if (flag_count[2] > 0)
		forced_strat = 2;
	else
		forced_strat = -1;
	indexed = psindex(numbers, count);
	free_all(all_tokens, NULL);
	stack_a = build_list(indexed, count);
	stack_b = NULL;
	bench_reset();
	if (count == 2)
		sort_two(&stack_a, &stack_b);
	else if (count == 3)
		sort_three(&stack_a, &stack_b);
	else if (count == 5)
		sort_five(&stack_a, &stack_b);
	else
		ft_exec_strategy_dispatch(&stack_a, &stack_b, forced_strat, ft_compute_disorder(stack_a));
	bench_mode = (flag_count[4] > 0);
	if (bench_mode)
	{
		float dis = ft_compute_disorder(stack_a);
		const char *strategy_name;
		if (forced_strat == 0)
			strategy_name = "Simple / O(n^2)";
		else if (forced_strat == 1)
			strategy_name = "Intermediate / O(n\u221A n)";
		else if (forced_strat == 2)
			strategy_name = "Complex / O(n log n)";
		else
		{
			if (dis >= 0.5f)
				strategy_name = "Adaptive -> Complex / O(n log n)";
			else if (dis >= 0.2f)
				strategy_name = "Adaptive -> Intermediate / O(n\u221A n)";
			else
				strategy_name = "Adaptive -> Simple / O(n)";
		}
		bench_print(ft_compute_disorder(stack_a), strategy_name);
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
