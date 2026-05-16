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

void	ra(t_stack **a)
{
	stack_rot(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	stack_rot(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	stack_rot(b);
	stack_rot(a);
	write(1, "rr\n", 3);
}
