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

void	sa(t_bench *bench)
{
	swap(bench->a);
	if (!bench->printbench)
		write(1, "sa\n", 3);
	bench->totals[1]++;
	bench->totals[0]++;
}

void	sb(t_bench *bench)
{
	swap(bench->b);
	if (!bench->printbench)
		write(1, "sb\n", 3);
	bench->totals[2]++;
	bench->totals[0]++;
}

void	ss(t_bench *bench)
{
	swap(bench->a);
	swap(bench->b);
	if (!bench->printbench)
		write(1, "ss\n", 3);
	bench->totals[3]++;
	bench->totals[0]++;
}

void	pa(t_bench *bench)
{
	stack_addtop(&(bench->a), stack_removetop(&(bench->b)));
	if (!bench->printbench)
		write(1, "pa\n", 3);
	bench->totals[4]++;
	bench->totals[0]++;
}

void	pb(t_bench *bench)
{
	stack_addtop(&(bench->b), stack_removetop(&(bench->a)));
	if (!bench->printbench)
		write(1, "pb\n", 3);
	bench->totals[5]++;
	bench->totals[0]++;
}
