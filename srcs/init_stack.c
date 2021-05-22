#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node	*init_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	connect_list(t_node **temp, t_node **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *temp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

t_node	*make_stack(int argc, char **argv, t_stack **stack)
{
	int		i;
	t_node	*temp;
	t_node	*node;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		temp = init_node();
		temp->value = ft_atoi(argv[i]);
		if (!temp)
			return (NULL);
		connect_list(&temp, &node, stack);
		(*stack)->size++;
		if (i == argc - 1)
			(*stack)->bottom = node;
	}
	while (node->prev)
		node = node->prev;
	return (node);
}
