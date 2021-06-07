/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:52:10 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/07 16:52:11 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include "structures.h"
# include "get_next_line_bonus.h"
# include "libft.h"

void	checker(t_stack *a, t_stack *b);

t_stack	*init_stack(void);
t_node	*make_stack(int argc, char **argv, t_stack **stack);

void	print_error(void);
int		check_arg(char *arg);
void	check_duplicate(t_node *a);
int		ft_atoi(char *arg);

void	swap_stack(t_stack *stack, int flag);
void	swap_all_stack(t_stack *a, t_stack *b, int flag);
void	push_stack(t_stack *from, t_stack *to, int flag);
void	rotate_stack(t_stack *stack, int flag);
void	rotate_all_stack(t_stack *a, t_stack *b, int flag);
void	reverse_rotate_stack(t_stack *stack, int flag);
void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag);

void	do_push(char *buf, t_stack *a, t_stack *b);
void	do_swap(char *buf, t_stack *a, t_stack *b);
void	do_rotate(char *buf, t_stack *a, t_stack *b);
void	do_reverse_rotate(char *buf, t_stack *a, t_stack *b);

void	free_all(t_stack *a, t_stack *b);

#endif
