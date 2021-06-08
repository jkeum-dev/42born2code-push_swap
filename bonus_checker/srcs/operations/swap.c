/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:30:07 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/07 14:45:41 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_stack(t_stack *stack, int flag)
{
	t_node	*temp;
	t_node	*top_next;

	if (stack->size < 2)
		return ;
	top_next = stack->top->next;
	temp = stack->top;
	temp->next = top_next->next;
	stack->top = top_next;
	stack->top->prev = NULL;
	stack->top->next = temp;
	temp->prev = stack->top;
	if (stack->size == 2)
		stack->bottom = stack->top->next;
	if (flag == A)
		ft_putendl_fd("sa", 1);
	else if (flag == B)
		ft_putendl_fd("sb", 1);
}

void	swap_all_stack(t_stack *a, t_stack *b, int flag)
{
	swap_stack(a, flag);
	swap_stack(b, flag);
	if (flag == ALL)
		ft_putendl_fd("ss", 1);
}
