#include "push_swap.h"

void	get_mid_value(t_node *node, t_cmp *cmp)
{
	int		num;
	int		sub;
	int		sub_next;
	t_node	*temp;

	if (!node->next)
	{
		cmp->mid = node->value;
		return ;
	}
	num = (cmp->max + cmp->min) / 2;
	sub = node->value - num;
	temp = node;
	while (node)
	{
		if (sub < 0)
			sub *= -1;
		if (node->next)
		{
			sub_next = node->next->value - num;
			if (sub_next < 0)
				sub_next *= -1;
			if (sub > sub_next)
			{
				sub = node->next->value - num;
				temp = node->next;
			}
			node = node->next;
		}
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	cmp->mid = temp->value;
}

void	get_min_value(t_node *node, t_cmp *cmp)
{
	cmp->min = node->value;
	while (node)
	{
		if (cmp->min > node->value)
			cmp->min = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
}

void	get_max_value(t_node *node, t_cmp *cmp)
{
	cmp->max = node->value;
	while (node)
	{
		if (cmp->max < node->value)
			cmp->max = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
}
