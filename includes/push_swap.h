#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "structures.h"

void	print_error(void);
int		check_arg(char *arg);
void	check_duplicate(t_node *a);
int		ft_atoi(char *arg);
t_stack	*init_stack(void);
t_node	*init_node(void);
t_node	*make_stack(int argc, char **argv, t_stack **stack);
void	init_value(t_value *var);
int		get_min_value(t_node *node, int size);
int		get_max_value(t_node *node, int size);

void	swap_stack(t_stack *stack, int flag);
void	swap_all_stack(t_stack *a, t_stack *b, int flag);
void	push_stack(t_stack *from, t_stack *to, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_all_stack(t_stack *a, t_stack *b, int flag);
void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag);

void	push_swap(t_stack *a, t_stack *b);
void	handle_arg_three_a(int r, t_stack *stack);
void	handle_arg_three_b(int r, t_stack *a, t_stack *b);
void	handle_under_three(int r, t_stack *a, t_stack *b, int flag);
void	select_pivot(int r, t_stack *stack, t_value *var);
void	a_to_b(int r, t_stack *a, t_stack *b);
void	b_to_a(int r, t_stack *a, t_stack *b);

#endif
