#include "checker.h"

void	do_push(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("pa", buf))
		push_stack(b, a, A);
	else if (!ft_strcmp("pb", buf))
		push_stack(a, b, B);
}

void	do_swap(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("sa", buf))
		swap_stack(a, A);
	else if (!ft_strcmp("sb", buf))
		swap_stack(b, B);
	else
		swap_all_stack(a, b, ALL);
}

void	do_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("ra", buf))
		rotate_stack(a, A);
	else if (!ft_strcmp("rb", buf))
		rotate_stack(b, B);
	else
		rotate_all_stack(a, b, ALL);
}

void	do_reverse_rotate(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("rra", buf))
		reverse_rotate_stack(a, A);
	else if (!ft_strcmp("rrb", buf))
		reverse_rotate_stack(b, B);
	else
		reverse_rotate_all_stack(a, b, ALL);
}
