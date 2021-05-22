#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;

struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
};

struct	s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
};

#endif
