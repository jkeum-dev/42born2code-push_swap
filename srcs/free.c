#include "push_swap.h"

void	free_all(t_stack *a, t_stack *b)
{
	t_node	*node;
	t_node	*temp;

	node = a->top;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(a);
	free(b);
}
