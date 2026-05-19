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

static void	ft_putstr_fd(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

static void	print_bench_total(t_bench *bench, int ti)
{
	char	*names;

	names = "sa sb ss pa pb ra rb rr rrarrbrrr";
	write(2, " ", 1);
	if (ti)
		write(2, names + (ti - 1) * 3, 2 + (ti / 9));
	else
		write(2, "total_ops", 9);
	write(2, ": ", 2);
	ft_putnbr_fd(bench->totals[ti], 2);
}

void	print_bench(t_bench *bench, float disorder)
{
	int	ti;

	ti = 0;
	write(2, "[bench] disorder: ", 18);
	ft_putfloat_fd(disorder * 100, 2);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	if (bench->strategy == 's')
		ft_putstr_fd("Simple / O(n²)");
	else if (bench->strategy == 'm')
		ft_putstr_fd("Medium / O(n√n)");
	else if (bench->strategy == 'c')
		ft_putstr_fd("Complex / O(nlogn)");
	write(2, "\n[bench]", 8);
	print_bench_total(bench, ti);
	write(2, "\n[bench]", 8);
	while (ti++ < 5)
		print_bench_total(bench, ti);
	ti--;
	write(2, "\n[bench]", 8);
	while (ti++ < 11)
		print_bench_total(bench, ti);
	write(2, "\n", 1);
}
