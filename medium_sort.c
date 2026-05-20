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

static int	find_chunk_pos(t_stack *stack, int min, int max, int *from_top, int *from_bot)
{
	int	pos;

	pos = 0;
	*from_top = -1;
	*from_bot = -1;
	while (stack)
	{
		if (stack->value >= min && stack->value <= max)
		{
			if (*from_top == -1)
				*from_top = pos;
			*from_bot = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (*from_top != -1);
}

static void	push_chunktob(t_bench *bench, int min, int max)
{
	int	from_top;
	int	from_bot;
	int	size;

	size = size_stack(bench->a);
	while (find_chunk_pos(bench->a, min, max, &from_top, &from_bot))
	{
		if (from_top <= size - from_bot)
			while (from_top--)
				ra(bench);
		else
		{
			from_bot = size - from_bot;
			while (from_bot--)
				rra(bench);
		}
		pb(bench);
		size--;
	}
}

static void pull_chunktoa(t_bench *bench, int min, int max)
{
    int from_top;
    int from_bot;
    int size;
    int cur_max;

    while (find_chunk_pos(bench->b, min, max, &from_top, &from_bot))
    {
        size = size_stack(bench->b);
        cur_max = find_max_in_range(bench->b, min, max);
        find_pos_value(bench->b, cur_max, &from_top);
        if (from_top <= size - from_top)
            while (from_top--)
                rb(bench);
        else
        {
            from_top = size - from_top;
            while (from_top--)
                rrb(bench);
        }
        pa(bench);
    }
}

int	medium_sort(t_bench *bench)
{
	int	nb_chunks;
	int	range;
	int	min;
	int	max;
	int	i;

	i = 0;
	nb_chunks = ftsqrt(bench->a);
	min = find_min(bench->a);
	max = find_max(bench->a);
	range = (max - min + nb_chunks) / nb_chunks;
	while (i < nb_chunks)
	{
		push_chunktob(bench, min + i * range, min + (i + 1) * range - 1);
		i++;
	}
	i = nb_chunks - 1;
	while (i >= 0)
	{
		pull_chunktoa(bench, min + i * range, min + (i + 1) * range - 1);
		i--;
	}
	return (0);
}

