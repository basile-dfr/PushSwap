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

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	selection_sort(t_bench *bench)
{
	int	maxi;
	int	len;

	while (bench->a)
	{
		maxi = stack_maxi(bench->a);
		len = stack_len(bench->a);
		if (maxi - 1 < len / 2)
			len = 0;
		else
			maxi = len - maxi;
		while (maxi)
		{
			if (!len)
				ra(bench);
			else
				rra(bench);
			maxi--;
		}
		pb(bench);
	}
}
