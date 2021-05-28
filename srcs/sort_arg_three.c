#include "push_swap.h"

static void	arg_three_top_min(t_stack *stack, int max)
{
	if (stack->top->next->value == max)
	{
		reverse_rotate_stack(stack, A);
		swap_stack(stack, A);
	}
}

static void	arg_three_bottom_min(t_stack *stack, int max)
{
	if (stack->top->value == max)
		swap_stack(stack, A);
	reverse_rotate_stack(stack, A);
}

static void	arg_three_middle_min(t_stack *stack, int max)
{
	if (stack->bottom->value == max)
		swap_stack(stack, A);
	else
		rotate_stack(stack, A);
}

void	handle_arg_three_a(int r, t_stack *stack)
{
	int	min;
	int	max;

	min = get_min_value(stack->top, r);
	max = get_max_value(stack->top, r);
	if (stack->top->value == min)
		arg_three_top_min(stack, max);
	else if (stack->bottom->value == min)
		arg_three_bottom_min(stack, max);
	else if (stack->top->next->value == min)
		arg_three_middle_min(stack, max);
}

void	handle_arg_three_b(int r, t_stack *a, t_stack *b)
{
	handle_arg_three_a(r, b);
	push_stack(b, a, A);
	push_stack(b, a, A);
	push_stack(b, a, A);
}
