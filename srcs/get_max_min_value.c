#include "push_swap.h"

int	get_min_value(t_node *node, int size)
{
	int	min;

	min = node->value;
	while (size--)
	{
		if (min > node->value)
			min = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}

int	get_max_value(t_node *node, int size)
{
	int	max;

	max = node->value;
	while (size--)
	{
		if (max < node->value)
			max = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

// void	get_second_big(t_stack *stack)
// {
// 	t_node	*node;

// 	node = stack->top;
// 	if (node->value == stack->var->max)
// 		node = node->next;
// 	stack->var->max_next = node->value;
// 	while (node)
// 	{
// 		if (stack->var->max != node->value)
// 		{
// 			if (stack->var->max_next < node->value)
// 				stack->var->max_next = node->value;
// 		}
// 		if (node->next)
// 			node = node->next;
// 		else
// 			break ;
// 	}
// 	while (node->prev)
// 		node = node->prev;
// }

// void	get_var_two_values(t_stack *stack)
// {
// 	if (stack->size < 2)
// 		return ;
// 	stack->var = (t_value *)malloc(sizeof(t_value));
// 	if (!stack->var)
// 		return ;
// 	get_max_value(stack);
// 	get_second_var(stack);
// }
