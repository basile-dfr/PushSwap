/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdefer <bdefer@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:04:45 by bdefer            #+#    #+#             */
/*   Updated: 2026/05/19 17:04:51 by bdefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

static int	size_stack(t_stack *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return(0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

static int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return(0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

static int	find_min(t_stack *stack)
{
	int	min;

	if(!stack)
		return(0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static int	ftsqrt(t_stack *stack)
{
	int	i;
	int	nb;

	i = 0;
	nb = size_stack(stack);
	while (i * i <= nb)
		i++;
	return (i - 1);
}

