/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:48:42 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/19 16:48:44 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

static int	nth_value(t_stack *stack, int n)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack->next && i < n)
	{
		stack = stack->next;
		i++;
	}
	return (stack->value);
}

int	median(t_stack *stack, t_stack *depth)
{
	int	i;
	int	j;
	int	h;

	i = 0;
	while (i < depth->value)
	{
		j = 0;
		h = 0;
		while (j < depth->value)
		{
			if (nth_value(stack, i) > nth_value(stack, j))
				h++;
			j++;
		}
		if (h == depth->value / 2)
			return (nth_value(stack, i));
		i++;
	}
	return (stack->value);
}

int	has_duplicates(t_stack *stack)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = size_stack(stack);
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (i != j && nth_value(stack, i) == nth_value(stack, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int find_max_in_range(t_stack *stack, int min, int max)
{
    int max_range;

    max_range = min;
    while (stack)
    {
        if (stack->value >= min && stack->value <= max)
            if (stack->value > max_range)
                max_range = stack->value;
        stack = stack->next;
    }
    return (max_range);
}

void find_pos_value(t_stack *stack, int value, int *pos)
{
    int i;

    i = 0;
    while (stack)
    {
        if (stack->value == value)
        {
            *pos = i;
            return ;
        }
        i++;
        stack = stack->next;
    }
}
