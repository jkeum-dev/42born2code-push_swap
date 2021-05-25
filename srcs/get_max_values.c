#include "push_swap.h"

/*
**	void	get_min_value(t_node *node, t_cmp *cmp)
**	{
**		cmp->min = node->value;
**		while (node)
**		{
**			if (cmp->min > node->value)
**				cmp->min = node->value;
**			if (node->next)
**				node = node->next;
**			else
**				break ;
**		}
**		while (node->prev)
**			node = node->prev;
**	}
*/

void	get_max_value(t_stack *stack)
{
	t_node	*node;

	if (!stack->big)
	{
		stack->big = (t_value *)malloc(sizeof(t_value));
		if (!stack->big)
			return ;
	}
	node = stack->top;
	stack->big->first = node->value;
	while (node)
	{
		if (stack->big->first < node->value)
			stack->big->first = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
}

void	get_second_big(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (node->value == stack->big->first)
		node = node->next;
	stack->big->second = node->value;
	while (node)
	{
		if (stack->big->first != node->value)
		{
			if (stack->big->second < node->value)
				stack->big->second = node->value;
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
}

void	get_third_big(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	if (node->value == stack->big->first || node->value == stack->big->second)
		node = node->next;
	if (node->value == stack->big->first || node->value == stack->big->second)
		node = node->next;	
	stack->big->third = node->value;
	while (node)
	{
		if (stack->big->first != node->value &&
		stack->big->second != node->value)
		{
			if (stack->big->third < node->value)
				stack->big->third = node->value;
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
}

void	get_big_three_values(t_stack *stack)
{
	if (stack->size < 3)
		return ;
	stack->big = (t_value *)malloc(sizeof(t_value));
	if (!stack->big)
		return ;
	get_max_value(stack);
	get_second_big(stack);
	get_third_big(stack);
}
