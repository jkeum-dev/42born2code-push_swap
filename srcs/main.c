#include "push_swap.h"
#include <stdio.h>

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void	set_stack_a(int argc, char **argv, t_stack **a)
{
	(*a)->top = make_stack(argc, argv, a);
	check_duplicate((*a)->top);
}

int		is_sorted(t_stack *a)
{
	t_node	*node;

	node = a->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->value == a->bottom->value)
		return (1);
	else
		return (0);
}

void	print_stack_a(t_stack *a)
{
	printf("\n\nstack a\n");
	while (a->top)
	{
		printf("%d\t", a->top->value);
		if (a->top->next)
			a->top = a->top->next;
		else
			break ;
	}
	while (a->top->prev)
		a->top = a->top->prev;
	if (a->top && a->bottom)
	{
		printf("\ntop:\t%d\n", a->top->value);
		printf("bottom:\t%d\n", a->bottom->value);
		printf("size:\t%d\n", a->size);
	}
}

void	print_stack_b(t_stack *b)
{
	printf("\n\nstack b\n");
	if (!b->top)
		return ;
	while (b->top)
	{
		printf("%d\t", b->top->value);
		if (b->top->next)
			b->top = b->top->next;
		else
			break ;
	}
	while (b->top->prev)
		b->top = b->top->prev;
	if (b->top && b->bottom)
	{
		printf("\ntop:\t%d\n", b->top->value);
		printf("bottom:\t%d\n", b->bottom->value);
		printf("size:\t%d\n", b->size);
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack();
	set_stack_a(argc, argv, &a);
	b = init_stack();

	print_stack_a(a);
	if (is_sorted(a))
		return (0);
	push_swap(a, b);

	// push_stack(a, b, B);
	// push_stack(a, b, B);
	// push_stack(a, b, B);
	// swap_all_stack(a, b, ALL);
	// rotate_all_stack(a, b, ALL);
	// reverse_rotate_all_stack(a, b, ALL);

	print_stack_a(a);
	// printf("top next: %d\n", a->top->next->value);
	// printf("bottom prev: %d\n", a->bottom->prev->value);
	// if (a->top->prev == NULL)
	// 	printf("top prev : NULL\n");
	// if (a->bottom->next == NULL)
	// 	printf("bottom next : NULL\n");
	// print_stack_b(b);
	// printf("top next: %d\n", b->top->next->value);
	// printf("bottom prev: %d\n", b->bottom->prev->value);
	// if (b->top->prev == NULL)
	// 	printf("top prev : NULL\n");
	// if (b->bottom->next == NULL)
	// 	printf("bottom next : NULL\n");
	free_all(a, b);
	return (0);
}
