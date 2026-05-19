/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdefer <bdefer@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 18:42:32 by bdefer            #+#    #+#             */
/*   Updated: 2026/05/17 18:42:34 by bdefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_stack.h"

float	compute_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	float	mistakes;
	float	total_pairs;

	i = a;
	mistakes = 0;
	total_pairs = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value > j->value)
				mistakes++;
			total_pairs++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}
