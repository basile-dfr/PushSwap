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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (fill_a(&a, argv + 1, argc - 1))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_stacks(a, b);
	selection_sort(&a, &b);
	print_stacks(a, b);
}
