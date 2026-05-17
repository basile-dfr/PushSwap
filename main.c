/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 13:44:13 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/16 13:44:16 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

void	print_stack(t_stack *stack)
{
	if (!stack)
		printf("empty.");
	while (stack)
	{
		printf("%i ", stack->value);
		stack = stack->next;
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	printf("a -> ");
	print_stack(a);
	printf("\n");
	printf("b -> ");
	print_stack(b);
	printf("\n");
}

static void	init_bench(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total = 0;
	bench->printbench = 0;
	bench->simple = 0;
	bench->medium = 0;
	bench->complex = 0;
	bench->adaptative = 0;
}
// a optimiser code long 
// cas de --flag existant + --flag_garbage non gere
// cas de --simple + --complex || --medium --simple ... non geres
int	handle_flag(char **argv, int count, t_bench *bench)
{
	while(argv[count] && argv[count][0] == '-')   
	{
		if (argv[count][1] != '-')
		{
			write(1, "FlagError\n", 10);
			return (0);
		}
		if (strncmp(argv[count], "--bench", strlen(argv[count])) == 0)
			bench->printbench++;
		if (strncmp(argv[count], "--simple", strlen(argv[count])) == 0)
			bench->simple++;
		if (strncmp(argv[count], "--medium", strlen(argv[count])) == 0)
			bench->medium++;
		if (strncmp(argv[count], "--complex", strlen(argv[count])) == 0)
			bench->complex++;
		if (strncmp(argv[count], "--adaptative", strlen(argv[count])) == 0)
			bench->adaptative++;
		if ((bench->printbench + bench->simple + bench->medium
				+ bench->complex + bench->adaptative) == 0)
		{
			write(1, "UnknownFlag\n", 12);
			return (0);
		}
		if (bench->printbench > 1 || bench->simple > 1 || bench->medium > 1
				|| bench->complex > 1 || bench->adaptative > 1)
		{
			write(1, "DupFlag\n", 8);
			return (0);
		}		
		count++;
	}
	if (count > 3)
	{
		write(1, "TooManyFlag\n", 12);
		return (0);
	}
	return(count);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	float	disorder;
	char	*strategy;
	int		i;
	
	i = 1;
	a = 0;
	b = 0;
	strategy = "Adaptative";
	init_bench(&bench);
	i = handle_flag(argv, i, &bench);
	if (i == 0)
		return (0);
	if (bench.simple)
		strategy = "Simple / O(n²)";
	if (bench.medium)
		strategy = "Medium / O(n√n)";
	if (bench.complex)
		strategy = "Complex / O(nlogn)";
	if (fill_a(&a, argv + i, argc - i))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	disorder = compute_disorder(a);
	print_stacks(a, b);
	if(bench.simple)  //applique l algo simple que si le --simple flag est present
		selection_sort(&a, &b, &bench);
	if (bench.printbench) //affiche le bench que si le --bench flag est present
		print_bench(&bench, disorder, strategy);
	print_stacks(a, b);
}
