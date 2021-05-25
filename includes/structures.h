#ifndef STRUCTURES_H
# define STRUCTURES_H

# define A 1
# define B 2
# define ALL 3

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;
typedef struct s_cmp	t_cmp;

struct	s_stack
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

struct	s_cmp
{
	int	min;
	int	mid;
	int	max;
};


#endif
