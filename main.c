/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:44:13 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/16 13:44:16 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

void	print_stack(t_stack *stack)
{
	if (!stack)
		printf("empty.");
	while (stack)
	{
		printf("%i ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("---\na -> ");
	print_stack(a);
	printf("b -> ");
	print_stack(b);
	printf("---\n");
}

static void	init_bench(t_bench *bench)
{
	int	i;

	i = -1;
	while (i++ < 12)
		bench->totals[i] = 0;
	bench->printbench = 0;
	bench->strategy = 0;
	bench->a = 0;
	bench->b = 0;
}

int	handle_flag(char **argv, int *count, t_bench *bench)
{
	while (argv[*count] && argv[*count][0] == '-')
	{
		if (argv[*count][1] != '-')
			return (write(1, "FlagError\n", 10) != 0);
		if (!strcmp(argv[*count], "--bench") && !bench->printbench)
			bench->printbench++;
		else if ((!strcmp(argv[*count], "--simple")
				|| !strcmp(argv[*count], "--medium")
				|| !strcmp(argv[*count], "--complex")
				|| !strcmp(argv[*count], "--adaptative")) && !bench->strategy)
			bench->strategy = argv[*count][2];
		else
			return (write(1, "NonValidFlag\n", 13) != 0);
		(*count)++;
	}
	if (*count > 3)
		return (write(1, "TooManyFlag\n", 12) != 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_bench	bench;
	float	disorder;
	int		i;

	i = 1;
	init_bench(&bench);
	if (handle_flag(argv, &i, &bench))
		return (write(1, "Error\n", 6) == 0);
	if (fill_a(&(bench.a), argv + i, argc - i))
	{
		stack_free(bench.a);
		stack_free(bench.b);
		return (write(1, "Error\n", 6) == 0);
	}
	disorder = compute_disorder(bench.a);
	if (bench.strategy == 's')
		selection_sort(&bench);
	else if (bench.strategy == 'm')
		medium_sort(&bench);
	else if (bench.strategy == 'c')
		quicksort(&bench);
	else
		i = 0;
	if (bench.printbench)
		print_bench(&bench, disorder);
	print_stacks(bench.a, bench.b);
	stack_free(bench.a);
	stack_free(bench.b);
}
