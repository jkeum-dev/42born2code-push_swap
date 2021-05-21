#include "push_swap.h"
#include <stdio.h>

void	print_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	a = init_stack(argc, argv);
	while (a)
	{
		printf("%d\n", a->value);
		if (a->next)
			a = a->next;
		else
			break ;
	}
	return (0);
}
