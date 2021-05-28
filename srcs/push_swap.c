#include "push_swap.h"

t_value	*init_value(void)
{
	t_value *var;

	var = (t_value *)malloc(sizeof(t_value));
	if (!var)
		return (NULL);
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
	return (var);
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
	t_value *var;

	var = init_value();
}
