/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdefer <bdefer@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 20:01:56 by bdefer            #+#    #+#             */
/*   Updated: 2026/05/17 20:02:04 by bdefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

static void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
	}
	c = n % 10 + '0';
	write(fd, &c, 1);
}

static void	ft_putfloat_fd(float n, int fd)
{
	int	integer;
	int	decimal;

	integer = (int)n;
	decimal = (int)((n - integer) * 100);
	ft_putnbr_fd(integer, fd);
	write(fd, ".", 1);
	if (decimal < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(decimal, fd);
}

static void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

static void	print_bench2(t_bench *bench)
{
	write(2, "[bench] ra: ", 12);
	ft_putnbr_fd(bench->ra, 2);
	write(2, " rb: ", 5);
	ft_putnbr_fd(bench->rb, 2);
	write(2, " rr: ", 5);
	ft_putnbr_fd(bench->rr, 2);
	write(2, " rra: ", 6);
	ft_putnbr_fd(bench->rra, 2);
	write(2, " rrb: ", 6);
	ft_putnbr_fd(bench->rrb, 2);
	write(2, " rrr: ", 6);
	ft_putnbr_fd(bench->rrr, 2);
	write(2, "\n", 1);
}

void	print_bench(t_bench *bench, float disorder, char *strategy)
{
	//disorder
	write(2, "[bench] disorder: ", 18);
	ft_putfloat_fd(disorder * 100, 2);
	write(2, "%\n", 2);
	//strategy
	write(2, "[bench] strategy: ", 18);
	ft_putstr_fd(strategy, 2);
	write(2, "\n", 1);
	//total ops
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(bench->total, 2);
	write(2, "\n", 1);
	//nb de chaque op
	write(2, "[bench] sa: ", 12);
	ft_putnbr_fd(bench->sa, 2);
	write(2, " sb: ", 5);
	ft_putnbr_fd(bench->sb, 2);
	write(2, " ss: ", 5);
	ft_putnbr_fd(bench->ss, 2);
	write(2, " pa: ", 5);
	ft_putnbr_fd(bench->pa, 2);
	write(2, " pb: ", 5);
	ft_putnbr_fd(bench->pb, 2);
	write(2, "\n", 1);
	print_bench2(bench);
}
