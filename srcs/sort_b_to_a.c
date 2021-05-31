#include "push_swap.h"

void	b_to_a(int r, t_stack *a, t_stack *b, int *cnt)
{
	int		r_temp;
	int		rrr;
	int		rem;
	t_value	var;

	(*cnt)++;
	if (r <= 3)
	{
		handle_under_three(r, a, b, B);
		return ;
	}
	if (r == 5)
	{
		hanlde_sort_five(5, a, b, B);
		return ;
	}
	init_value(&var);
	select_pivot(r, b, &var);
	r_temp = r;
	while (r_temp--)
	{
		if (b->top->value <= var.piv_small)
		{
			rotate_stack(b, B);
			var.rb++;
		}
		else
		{
			push_stack(b, a, A);
			var.pa++;
			if (a->top->value <= var.piv_big)
			{
				rotate_stack(a, A);
				var.ra++;
			}
		}
	}
	a_to_b(var.pa - var.ra, a, b, cnt);
	if (var.ra > var.rb)
	{
		rrr = var.rb;
		rem = var.ra - rrr;
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		rrr = var.ra;
		rem = var.rb - rrr;
		while (rrr--)
			reverse_rotate_all_stack(a, b, ALL);
		while (rem--)
			reverse_rotate_stack(b, B);
	}
	a_to_b(var.ra, a, b, cnt);
	b_to_a(var.rb, a, b, cnt);
}
