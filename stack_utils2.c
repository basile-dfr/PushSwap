#include "push_stack.h"

int	size_stack(t_stack *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return(0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

int	find_max(t_stack *stack)
{
	int	max;

	if (!stack)
		return(0);
	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_stack *stack)
{
	int	min;

	if(!stack)
		return(0);
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}