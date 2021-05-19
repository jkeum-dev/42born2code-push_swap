/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:05:00 by jkeum             #+#    #+#             */
/*   Updated: 2020/10/11 17:12:04 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (!lst)
		return ;
	curr = *lst;
	if (!curr)
		ft_lstadd_front(lst, new);
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
		new->next = NULL;
	}
}
