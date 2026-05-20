/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:41:02 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/15 21:41:04 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

void	stack_rot(t_stack **stack)
{
	t_stack	*rot;
	t_stack	*nxt;

	if (!*stack || !(*stack)->next)
		return ;
	rot = *stack;
	nxt = (*stack)->next;
	*stack = nxt;
	while (nxt->next)
		nxt = nxt->next;
	rot->next = NULL;
	nxt->next = rot;
}

void	ra(t_bench *bench)
{
	stack_rot(&(bench->a));
	if (!bench->printbench)
		write(1, "ra\n", 3);
	bench->totals[6]++;
	bench->totals[0]++;
}

void	rb(t_bench *bench)
{
	stack_rot(&(bench->b));
	if (!bench->printbench)
		write(1, "rb\n", 3);
	bench->totals[7]++;
	bench->totals[0]++;
}

void	rr(t_bench *bench)
{
	stack_rot(&(bench->a));
	stack_rot(&(bench->b));
	if (!bench->printbench)
		write(1, "rr\n", 3);
	bench->totals[8]++;
	bench->totals[0]++;
}
