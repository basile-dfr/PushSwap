/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdefer <bdefer@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:04:45 by bdefer            #+#    #+#             */
/*   Updated: 2026/05/19 17:04:51 by bdefer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_stack.h"

static int	ftsqrt(t_stack *stack)
{
	int	i;
	int	nb;

	i = 0;
	nb = size_stack(stack);
	while (i * i <= nb)
		i++;
	return (i - 1);
}

static int	find_chunk_pos(t_stack *stack, int min, int max, int *first_pos, int *last_pos)
{
	int	pos;

	pos = 0;
	*first_pos = -1;
	*last_pos = -1;
	while (stack)
	{
		if (stack->value >= min && stack->value <= max) // si compris dans la range
		{
			if (*first_pos == -1) // donne la pos du permier passage a first_pos
				*first_pos = pos;
			*last_pos = pos; // sinon enregirste le dernier passage
		}
		pos++;
		stack = stack->next;
	}
	return (*first_pos != -1); // return 1 si trouvé dans la range sinn 0
}

static void	push_chunktob(t_bench *bench, int min, int max)
{
	int	first_pos;
	int	last_pos;
	int	size;


	while (find_chunk_pos(bench->a, min, max, &first_pos, &last_pos)) // tant que ya dans a une valeur de la range
	{
		size = size_stack(bench->a);
		if (first_pos <= size - last_pos) // ra si c'est plus court par le haut 
			while (first_pos--)
				ra(bench);
		else
		{
			last_pos = size - last_pos; // rra si c'est plus court par le bas 
			while (last_pos--)
				rra(bench);
		}
		pb(bench); // push dans b
	}
}

static void pull_chunktoa(t_bench *bench, int min, int max)
{
    int size;
    int value_max;
	int max_pos;
	int	last_pos; //sert a rien juste requis dans find chunk pos
	(void)last_pos; //sert a rien juste requis dans find chunk pos

    while (find_chunk_pos(bench->b, min, max, &max_pos, &last_pos))  //tant que ya dans b une valeur de la range
    {
        size = size_stack(bench->b);
        value_max = find_max_in_range(bench->b, min, max);  //trouve la plus grande valeur
        find_pos_value(bench->b, value_max, &max_pos); // trouve sa position
	//	printf("%d\n", max_pos);
        if (max_pos <= size - max_pos) // si c'est plus opti par le haut rb
            while (max_pos--)
                rb(bench);
        else
        {
            max_pos = size - max_pos; // si c'est plus opti par le bas rrb
            while (max_pos--)
                rrb(bench);
        }
        pa(bench); // push le haut dans a
    }
}

void	medium_sort(t_bench *bench)
{
	int	nb_chunks;
	int	range;
	int	min;
	int	max;
	int	i;

	i = 0;
	nb_chunks = ftsqrt(bench->a); // racine carre de nb element
	min = find_min(bench->a);
	max = find_max(bench->a);
	range = (max - min + nb_chunks) / nb_chunks;
	while (i < nb_chunks)
	{
		push_chunktob(bench, min + i * range, min + (i + 1) * range - 1);
		i++;
	}
	i = nb_chunks - 1;
	while (i >= 0)
	{
		pull_chunktoa(bench, min + i * range, min + (i + 1) * range - 1);
		i--;
	}
}