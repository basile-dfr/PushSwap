/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:40:35 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/15 21:40:40 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

void	sa(t_stack **a)
{
	swap(*a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(*b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	write(1, "ss\n", 3);
}

void	pa(t_stack **a, t_stack **b)
{
	stack_addtop(a, stack_removetop(b));
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	stack_addtop(b, stack_removetop(a));
	write(1, "pb\n", 3);
}
