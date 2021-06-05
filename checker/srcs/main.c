#include "checker.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack	*b;

	a = init_stack();
	a->top = make_stack(argc, argv, &a);
	check_duplicate(a->top);
	b = init_stack();

	checker(a, b);
}
