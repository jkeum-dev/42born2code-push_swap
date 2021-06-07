#include "checker.h"

void	check_operations(char *buf, t_stack *a, t_stack *b)
{
	if (!ft_strcmp("pa", buf) || !ft_strcmp("pb", buf))
		do_push(buf, a, b);
	else if (!ft_strcmp("sa", buf) || !ft_strcmp("sb", buf) || !ft_strcmp("ss", buf))
		do_swap(buf, a, b);
	else if (!ft_strcmp("ra", buf) || !ft_strcmp("rb", buf) || !ft_strcmp("rr", buf))
		do_rotate(buf, a, b);
	else if (!ft_strcmp("rra", buf) || !ft_strcmp("rrb", buf) || !ft_strcmp("rrr", buf))
		do_reverse_rotate(buf, a, b);
	else
		print_error();
}

void	checker(t_stack *a, t_stack *b)
{
	char	*buf;

	while (get_next_line(0, &buf) > 0)
	{
		check_operations(buf, a, b);
		free(buf);
	}
}
