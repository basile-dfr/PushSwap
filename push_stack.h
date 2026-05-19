/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlusson <tlusson@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:41:55 by tlusson           #+#    #+#             */
/*   Updated: 2026/05/15 21:42:03 by tlusson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> // pour les tests

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bench
{
	int		totals[12]; // [0] = total, [1] = sa, ..., [11] = rrr
	int		printbench; // boolean
	int		strategy; // 'a' = adaptative, 's' = simple, etc.
	t_stack	*a;
	t_stack	*b;
}	t_bench;

//stack functions
t_stack		*stack_new(int value);
void		stack_addtop(t_stack **stack, t_stack *add);
void		swap(t_stack *stack);
t_stack		*stack_removetop(t_stack **stack);

// stack operations
void		sa(t_bench *bench);
void		sb(t_bench *bench);
void		ss(t_bench *bench);
void		pa(t_bench *bench);
void		pb(t_bench *bench);
void		ra(t_bench *bench);
void		rb(t_bench *bench);
void		rr(t_bench *bench);
void		rra(t_bench *bench);
void		rrb(t_bench *bench);
void		rrr(t_bench *bench);

//parsing functions
int			ft_atoi(const char *nptr);
int			fill_a(t_stack **a, char **vs, int count);
int			strcmp(const char *str1, const char *str2);
int			handle_flag(char **argv, int *count, t_bench *bench);
size_t		strlen(const char *str);

//sorting algorithms
void		selection_sort(t_bench *bench); //simple
//medium
void		quicksort(t_bench *bench); //complex

//bench functions
float		compute_disorder(t_stack *a);
void		print_bench(t_bench *bench, float disorder);
