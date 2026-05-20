/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:12:22 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/18 17:12:25 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

int	median(t_stack *stack, t_stack *depth);

static void	push_over2(t_bench *bench, t_stack **depth, int k, int p)
{
	int	rollback;

	rollback = (k + p + 1) != (stack_len(bench->a) + stack_len(bench->b));
	free(stack_removetop(depth));
	stack_addtop(depth, (stack_new(k)));
	stack_addtop(depth, (stack_new(1)));
	stack_addtop(depth, (stack_new(p)));
	while (k && rollback)
	{
		rra(bench);
		k--;
	}
	rrb(bench);
	pa(bench);
}

static void	push_over(t_bench *bench, int med, t_stack **depth)
{
	int	pushed;
	int	kept;

	pushed = 0;
	kept = 0;
	while ((*depth)->value)
	{
		if (bench->a->value < med)
		{
			pushed++;
			pb(bench);
		}
		else if (bench->a->value > med)
		{
			kept++;
			ra(bench);
		}
		else
		{
			pb(bench);
			rb(bench);
		}
		(*depth)->value--;
	}
	push_over2(bench, depth, kept, pushed);
}

static void	push_back(t_bench *bench, t_stack **depth)
{
	int	i;

	i = 0;
	while (i < (*depth)->value)
	{
		pa(bench);
		i++;
	}
}

static void	final_push(t_bench *bench, t_stack **depth)
{
	while (*depth && (*depth)->value <= 2)
	{
		if ((*depth)->value == 1)
			ra(bench);
		else if ((*depth)->value == 2)
		{
			if (bench->a->value > bench->a->next->value)
				sa(bench);
			ra(bench);
			ra(bench);
		}
		free(stack_removetop(depth));
	}
}

void	quicksort(t_bench *bench)
{
	t_stack	*depth;

	depth = 0;
	stack_addtop(&depth, (stack_new(stack_len(bench->a))));
	while (depth)
	{
		push_over(bench, median(bench->a, depth), &depth);
		push_back(bench, &depth);
		final_push(bench, &depth);
	}
}
