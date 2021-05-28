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

void	a_to_b(int r, t_stack *a, t_stack *b)
{
	int		r_temp;
	int		rrr;
	int		rem;
	t_value	*var;

	if (r <= 3)
		;	// sort
	var = init_value();
	if (!var)
		return ;
	select_pivot(r, a, var);
	r_temp = r;
	while (r_temp--)
	{
		if (a->top->value >= var->piv_big)
		{
			rotate_stack(a, A);
			var->ra++;
		}
		else
		{
			push_stack(a, b, B);
			var->pb++;
			if (b->top->value >= var->piv_small)
			{
				rotate_stack(b, B);
				var->rb++;
			}
		}
	}
	if (var->ra > var->rb)
	{
		rrr = var->rb;
		rem = var->ra - rrr;
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		rrr = var->ra;
		rem = var->rb - rrr;
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
	a_to_b(var->ra, a, b);
	b_to_a(var->rb, a, b);
	b_to_a(var->pb - var->rb, a, b);
}

void	b_to_a(int r, t_stack *a, t_stack *b)
{
	int		r_temp;
	int		rrr;
	int		rem;
	t_value	*var;

	if (r <= 3)
		;	// sort or pa
	var = init_value();
	if (!var)
		return ;
	select_pivot(r, b, var);
	r_temp = r;
	while (r_temp--)
	{
		if (b->top->value < var->piv_small)
		{
			rotate_stack(b, B);
			var->rb++;
		}
		else
		{
			push_stack(b, a, A);
			var->pa++;
			if (b->top->value < var->piv_big)
			{
				rotate_stack(a, A);
				var->ra++;
			}
		}
	}
	a_to_b(var->pa - var->ra, a, b);
	if (var->ra > var->rb)
	{
		rrr = var->rb;
		rem = var->ra - rrr;
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		rrr = var->ra;
		rem = var->rb - rrr;
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
	a_to_b(var->rb, a, b);
	b_to_a(var->ra, a, b);
}

void	push_swap(t_stack *a, t_stack *b)
{
	t_value *var;

	var = init_value();
}