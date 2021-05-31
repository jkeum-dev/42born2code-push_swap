#include "push_swap.h"

int		get_mid_value_five(t_node *node)
{
	int	i;
	int	j;
	int	tmp;
	int	value[5];

	i = -1;
	while (++i < 5)
	{
		value[i] = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	i = 5;
	while (--i > 0)
	{
		j = -1;
		while (++j < i)
		{
			if (value[j] > value[j + 1])
			{
				tmp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = tmp;
			}
		}
	}
	return (value[2]);
}

void	hanlde_sort_five(int size, t_stack *a, t_stack *b, int flag)
{
	int		mid;
	int		push;
	int		rotate;

	push = 0;
	rotate = 0;
	if (flag == A)
	{
		mid = get_mid_value_five(a->top);
		while (size--)
		{
			if (a->top->value < mid)
			{
				push_stack(a, b, B);
				push++;
			}
			else
			{
				rotate_stack(a, A);
				rotate++;
			}
			if (push == 2)
				break ;
		}
		while (rotate--)
			reverse_rotate_stack(a, A);
	}
	else
	{
		mid = get_mid_value_five(b->top);
		while (size--)
		{
			if (b->top->value >= mid)
			{
				push_stack(b, a, A);
				push++;
			}
			else
			{
				rotate_stack(b, B);
				rotate++;
			}
			if (push == 3)
				break ;
		}
		while (rotate--)
			reverse_rotate_stack(b, B);
	}
	handle_arg_three_a(3, a);
	handle_arg_two(a, b, B);
}

void	handle_arg_five(t_stack *a, t_stack *b)
{
	int	pb;
	int	min;

	pb = 0;
	min = get_min_value(a->top, a->size);
	while (1)
	{
		if (a->top->value == min)
		{
			push_stack(a, b, B);
			pb++;
			min = get_min_value(a->top, a->size);
		}
		else
			rotate_stack(a, A);
		if (pb == 2)
			break ;
	}
	handle_arg_three_a(3, a);
	handle_arg_two(a, b, B);
}
