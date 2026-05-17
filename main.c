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
}

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("a -> ");
	print_stack(a);
	printf("\n");
	printf("b -> ");
	print_stack(b);
	printf("\n");
}

static void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	float	disorder;
	char	*strategy;
	
	a = 0;
	b = 0;
	strategy = "teststrategy";
	init_bench(&bench);
	if (fill_a(&a, argv + 1, argc - 1))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	disorder = compute_disorder(a);
	print_stacks(a, b);
	print_bench(&bench, disorder, strategy);
	selection_sort(&a, &b, &bench);
	print_bench(&bench, disorder, strategy);
	print_stacks(a, b);
}
