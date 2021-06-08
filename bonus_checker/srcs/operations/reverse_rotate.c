/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:30:02 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/07 14:45:33 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate_stack(t_stack *stack, int flag)
{
	t_node	*temp;
	t_node	*bottom_prev;

	if (stack->size < 2)
		return ;
	temp = stack->bottom;
	bottom_prev = stack->bottom->prev;
	stack->top->prev = temp;
	temp->next = stack->top;
	temp->prev = NULL;
	stack->top = temp;
	stack->bottom = bottom_prev;
	stack->bottom->next = NULL;
	if (flag == A)
		ft_putendl_fd("rra", 1);
	else if (flag == B)
		ft_putendl_fd("rrb", 1);
}

void	reverse_rotate_all_stack(t_stack *a, t_stack *b, int flag)
{
	reverse_rotate_stack(a, flag);
	reverse_rotate_stack(b, flag);
	if (flag == ALL)
		ft_putendl_fd("rrr", 1);
}
