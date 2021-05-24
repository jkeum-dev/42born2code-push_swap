#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "structures.h"

void	print_error(void);
int		check_arg(char *arg);
int		ft_atoi(char *arg);
t_stack	*init_stack(void);
t_node	*init_node(void);
t_node	*make_stack(int argc, char **argv, t_stack **stack);
void	push_pop(t_stack *from, t_stack *to);
void	swap_stack(t_stack *stack, int flag);
void	swap_all_stack(t_stack *a, t_stack *b, int flag);

#endif