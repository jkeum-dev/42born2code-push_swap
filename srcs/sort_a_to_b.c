#include "push_swap.h"

void	a_to_b(int r, t_stack *a, t_stack *b)
{
	int		r_temp;
	int		rrr;
	int		rem;
	t_value	var;

	// print_stack_a(a);
	// print_stack_b(b);
	if (r <= 3)
	{
		handle_under_three(r, a, b, A);
		return ;
	}
	init_value(&var);
	select_pivot(r, a, &var);
	// ft_putstr_fd("pivot big: ", 1);
	// ft_putnbr_fd(var.piv_big, 1);
	// ft_putchar_fd('\n', 1);
	// ft_putstr_fd("pivot small: ", 1);
	// ft_putnbr_fd(var.piv_small, 1);
	// ft_putchar_fd('\n', 1);
	r_temp = r;
	while (r_temp--)
	{
		if (a->top->value >= var.piv_big)
		{
			rotate_stack(a, A);
			var.ra++;
		}
		else
		{
			push_stack(a, b, B);
			var.pb++;
			if (b->top->value >= var.piv_small)
			{
				rotate_stack(b, B);
				var.rb++;
			}
		}
	}
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
	a_to_b(var.ra, a, b);
	b_to_a(var.rb, a, b);
	b_to_a(var.pb - var.rb, a, b);
}
