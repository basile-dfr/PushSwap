/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:41:10 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/15 21:41:13 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

void	stack_rrot(t_stack **stack)
{
	t_stack	*rot;
	t_stack	*nxt;

	if (!*stack || !(*stack)->next)
		return ;
	nxt = (*stack);
	*stack = nxt;
	while (nxt->next->next)
		nxt = nxt->next;
	rot = nxt->next;
	nxt->next = NULL;
	rot->next = *stack;
	*stack = rot;
}

void	rra(t_bench *bench)
{
	stack_rrot(&(bench->a));
	if (!bench->printbench)
		write(1, "rra\n", 4);
	bench->totals[9]++;
	bench->totals[0]++;
}

void	rrb(t_bench *bench)
{
	stack_rrot(&(bench->b));
	if (!bench->printbench)
		write(1, "rrb\n", 4);
	bench->totals[10]++;
	bench->totals[0]++;
}

void	rrr(t_bench *bench)
{
	stack_rrot(&(bench->a));
	stack_rrot(&(bench->b));
	if (!bench->printbench)
		write(1, "rrr\n", 4);
	bench->totals[11]++;
	bench->totals[0]++;
}
