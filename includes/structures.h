#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_listp	t_listp;
typedef struct s_stack	t_stack;

struct s_listp
{
	int		size;
	t_stack	*top;
	t_stack	*bottom;
};

struct	s_stack
{
	int		value;
	t_stack	*prev;
	t_stack	*next;
};

#endif
