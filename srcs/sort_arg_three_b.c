#include "push_swap.h"

void	arg_three_top_min_b(t_stack *b, int max)
{
	rotate_stack(b, B);
	if (b->top->next->value == max)
		swap_stack(b, B);
}

void	arg_three_bottom_min_b(t_stack *b, int max)
{
	if (b->top->next->value == max)
		swap_stack(b, B);
}

void	arg_three_middle_min_b(t_stack *b, int max)
{
	reverse_rotate_stack(b, B);
	if (b->top->value == max)
		swap_stack(b, B);
}

void	handle_arg_three_b(int r, t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = get_min_value(b->top, r);
	max = get_max_value(b->top, r);
	if (b->top->value == min)
		arg_three_top_min_b(b, max);
	else if (b->bottom->value == min)
		arg_three_bottom_min_b(b, max);
	else if (b->top->next->value == min)
		arg_three_middle_min_b(b, max);
	push_stack(b, a, A);
	push_stack(b, a, A);
	push_stack(b, a, A);
}
