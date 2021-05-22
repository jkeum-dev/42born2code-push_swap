#include "push_swap.h"

t_listp	*make_listp(void)
{
	t_listp	*listp;

	listp = (t_listp *)malloc(sizeof(t_listp));
	if (!listp)
		return (NULL);
	listp->size = 0;
	listp->head = NULL;
	listp->tail = NULL;
	return (listp);
}

static t_stack	*make_node(int argc, char *argv)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = ft_atoi(argv);
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

static void	connect_list(t_stack **temp, t_stack **node, t_listp **listp)
{
	if (!*node)
	{
		*node = *temp;
		(*listp)->head = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		(*node) = (*node)->next;
	}
}

t_stack	*make_stack(int argc, char **argv, t_listp **listp)
{
	int		i;
	t_stack	*temp;
	t_stack	*node;

	i = 0;
	node = NULL;
	while (++i < argc)
	{
		temp = make_node(argc, argv[i]);
		if (!temp)
			return (NULL);
		connect_list(&temp, &node, listp);
		(*listp)->size++;
		if (i == argc - 1)
			(*listp)->tail = node;
	}
	while (node->prev)
		node = node->prev;
	return (node);
}
