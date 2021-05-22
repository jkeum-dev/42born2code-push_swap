#include "push_swap.h"
#include <stdio.h>

void	print_error(void)
{
	ft_putendl_fd("Error", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_listp	*listp;
	t_stack	*a;

	listp = make_listp();
	a = make_stack(argc, argv, &listp);
	while (a)
	{
		printf("%d\t", a->value);
		if (a->next)
			a = a->next;
		else
			break ;
	}
	printf("\ntop:\t%d\n", listp->top->value);
	printf("bottom:\t%d\n", listp->bottom->value);
	printf("size:\t%d\n", listp->size);
	return (0);
}
