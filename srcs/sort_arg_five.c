#include "push_swap.h"

void	handle_arg_five(t_stack *a, t_stack *b)
{
	int	pb;
	int	min;

	pb = 0;
	min = get_min_value(a->top, a->size);
	while (1)
	{
		if (a->top->value == min)
		{
			push_stack(a, b, B);
			pb++;
			min = get_min_value(a->top, a->size);
		}
		else
			rotate_stack(a, A);
		if (pb == 2)
			break ;
	}
	handle_arg_three_a(3, a);
	handle_arg_two(a, b, B);
}
