#include "push_swap.h"

void	init_value(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

void	select_pivot(int r, t_stack *stack, t_value *var)
{
	int	min;
	int	max;

	min = get_min_value(stack->top, r);
	max = get_max_value(stack->top, r);
	var->piv_big = (min + max) / 2;
	var->piv_small = (min + var->piv_big) / 2;
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (a->size == 5)
		handle_arg_five(a, b);
	else
		a_to_b(a->size, a, b);
}
