/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 17:47:18 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/15 21:38:32 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(struct s_stack));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	stack_addtop(t_stack **stack, t_stack *add)
{
	if (!*stack && !add)
		return ;
	if (!*stack)
	{
		*stack = add;
		return ;
	}
	add->next = *stack;
	*stack = add;
}

void	swap(t_stack *stack)
{
	int	sw;

	if (!stack || !(stack->next))
		return ;
	sw = stack->value;
	stack->value = stack->next->value;
	stack->next->value = sw;
}

t_stack	*stack_removetop(t_stack **stack)
{
	t_stack	*rm;

	if (!*stack)
		return (NULL);
	rm = *stack;
	*stack = (*stack)->next;
	rm->next = NULL;
	return (rm);
}
