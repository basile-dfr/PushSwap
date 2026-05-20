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

int	has_duplicates(t_stack *stack);

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

int	strcmp(const char *str1, const char *str2)
{
	size_t			i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

size_t	strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
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
	if (has_duplicates(*a))
		return (1);
	return (0);
}
