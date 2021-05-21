#include "push_swap.h"

t_stack	*init_node(int idx, int argc, char *argv, t_stack *prev)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(stack));
	if (!stack)
		return (NULL);
	stack->value = ft_atoi(argv);
	if (!prev)
		stack->prev = NULL;
	else
	{
		stack->prev = prev;
		prev->next = stack;
	}
	stack->next = NULL;
	return (stack);
}

t_stack	*init_stack(int argc, char **argv)
{
	int		i;
	t_stack	*stack;

	i = 0;
	stack = NULL;
	while (++i < argc)
	{
		stack = init_node(i, argc, argv[i], stack);
		// if (!stack)
		// 	free_stack(stack);
	}
	while (stack->prev)
		stack = stack->prev;
	return (stack);
}