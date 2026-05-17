/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:08:02 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/16 16:08:05 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

static int	stack_maxi(t_stack *stack)
{
	int	i;
	int	maxi;
	int	max;

	i = 0;
	maxi = 0;
	if (stack)
	{
		max = stack->value;
		stack = stack->next;
	}
	while (stack)
	{
		i++;
		if (stack->value > max)
		{
			maxi = i;
			max = stack->value;
		}
		stack = stack->next;
	}
	return (maxi);
}

void	selection_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	int	maxi;

	while (*a)
	{
		maxi = stack_maxi(*a);
		while (maxi)
		{
			ra(a, bench);
			maxi--;
		}
		pb(b, a, bench);
	}
}
