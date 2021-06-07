/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:30:52 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/07 16:52:42 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	free_a(t_stack *a)
{
	t_node	*node;
	t_node	*temp;

	node = a->top;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(a);
}

static void	free_b(t_stack *b)
{
	t_node	*node;
	t_node	*temp;

	node = b->top;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free(node);
		if (temp)
			node = temp;
		else
			break ;
	}
	free(b);
}

void		free_all(t_stack *a, t_stack *b)
{
	free_a(a);
	free_b(b);
}
