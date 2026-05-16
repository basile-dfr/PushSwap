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

//stack functions
t_stack	*stack_new(int value);
void	stack_addtop(t_stack **stack, t_stack *add);
void	swap(t_stack *stack);
t_stack	*stack_removetop(t_stack **stack);

// stack operations
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

//parsing functions
int		ft_atoi(const char *nptr);
int		fill_a(t_stack **a, char **vs, int count);

//sorting algorithms
void	selection_sort(t_stack **a, t_stack **b);
