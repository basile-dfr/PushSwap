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



int	stack_len(t_stack *stack);

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

static int	median(t_stack *stack, t_stack *depth)
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

static void	push_over(t_bench *bench, int med, t_stack **depth)
{
	int	pushed;
	int	kept;

	pushed = 0;
	kept = 0;
	while ((*depth)->value)
	{
		if (bench->a->value > med)
		{
			pushed++;
			pb(bench);
		}
		else if (bench->a->value < med)
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
	stack_removetop(depth);
	stack_addtop(depth, (stack_new(kept)));
	stack_addtop(depth, (stack_new(1)));
	stack_addtop(depth, (stack_new(pushed)));
	while (kept)
	{
		rra(bench);
		kept--;
	}
	rrb(bench);
	pa(bench);
}

static void	push_back(t_bench *bench, t_stack **depth)
{
	int i;

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
			pb(bench);
		else if ((*depth)->value == 2)
		{
			if (bench->a->value < bench->a->next->value)
				sa(bench);
			pb(bench);
			pb(bench);
		}
		stack_removetop(depth);
	}
}

void	print_stack(t_stack *stack);
//void	print_stacks(t_stack *a, t_stack *b);
void	quicksort(t_bench *bench)
{
	t_stack	*depth;

	depth = 0;
	stack_addtop(&depth, (stack_new(stack_len(bench->a))));
	while (bench->a)
	{
		//printf("median = %d\n", med);
		push_over(bench, median(bench->a, depth), &depth);
		push_back(bench, &depth);
		print_stack(depth);
		final_push(bench, &depth);
	}
}