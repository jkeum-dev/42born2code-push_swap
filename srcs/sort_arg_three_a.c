#include "push_swap.h"

static void	arg_three_top_min_a(t_stack *a, int max)
{
	if (a->top->next->value == max)
	{
		reverse_rotate_stack(a, A);
		swap_stack(a, A);
	}
}

static void	arg_three_bottom_min_a(t_stack *a, int max)
{
	if (a->top->value == max)
		swap_stack(a, A);
	reverse_rotate_stack(a, A);
}

static void	arg_three_middle_min_a(t_stack *a, int max)
{
	if (a->bottom->value == max)
		swap_stack(a, A);
	else
		rotate_stack(a, A);
}

void	handle_arg_three_a(int r, t_stack *a)
{
	int	min;
	int	max;

	min = get_min_value(a->top, r);
	max = get_max_value(a->top, r);
	if (a->top->value == min)
		arg_three_top_min_a(a, max);
	else if (a->bottom->value == min)
		arg_three_bottom_min_a(a, max);
	else if (a->top->next->value == min)
		arg_three_middle_min_a(a, max);
}
