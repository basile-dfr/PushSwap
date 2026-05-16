/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 16:16:31 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/16 16:16:33 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	out;

	out = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	neg = *nptr == '-';
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		out = out * 10 + *nptr - '0';
		nptr++;
	}
	if (neg)
		return (-out);
	return (out);
}

int	fill_a(t_stack **a, char **vs, int count)
{
	int	value;
	int	i;

	i = count - 1;
	while (i >= 0)
	{
		value = ft_atoi(vs[i]);
		if (!value && !(vs[i][0] == '0'
			|| ((vs[i][0] == '-' || vs[i][0] == '+') && vs[i][1] == '0')))
			return (1);
		stack_addtop(a, stack_new(value));
		i--;
	}
	return (0);
}
