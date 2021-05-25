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
	t_node	*a_node;
	t_stack	*b;
	t_node	*b_node;

	a = init_stack();
	a_node = make_stack(argc, argv, &a);
	b = init_stack();

	check_duplicate(a_node);
	while (a_node->prev)
		a_node = a_node->prev;

	get_big_three_values(a);

	printf("stack a\n");
	while (a_node)
	{
		printf("%d\t", a_node->value);
		if (a_node->next)
			a_node = a_node->next;
		else
			break ;
	}
	printf("\ntop:\t%d\n", a->top->value);
	printf("bottom:\t%d\n", a->bottom->value);
	printf("size:\t%d\n", a->size);

	// push_stack(a, b, B);
	// push_stack(a, b, B);
	// b_node = b->top;
	// // swap_stack(b, B);
	// // rotate_all_stack(a, b, ALL);
	// reverse_rotate_all_stack(a, b, ALL);

	// while (a_node->prev)
	// 	a_node = a_node->prev;
	// while (b_node->prev)
	// 	b_node = b_node->prev;
	// printf("\n\nstack a\n");
	// while (a_node)
	// {
	// 	printf("%d\t", a_node->value);
	// 	if (a_node->next)
	// 		a_node = a_node->next;
	// 	else
	// 		break ;
	// }
	// if (a->top && a->bottom)
	// {
	// 	printf("\ntop:\t%d\n", a->top->value);
	// 	printf("bottom:\t%d\n", a->bottom->value);
	// 	printf("size:\t%d\n", a->size);
	// }

	// printf("\n\nstack b\n");
	// while (b_node)
	// {
	// 	printf("%d\t", b_node->value);
	// 	if (b_node->next)
	// 		b_node = b_node->next;
	// 	else
	// 		break ;
	// }
	// printf("\ntop:\t%d\n", b->top->value);
	// printf("bottom:\t%d\n", b->bottom->value);
	// printf("size:\t%d\n", b->size);
	return (0);
}
