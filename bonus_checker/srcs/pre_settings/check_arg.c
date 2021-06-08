/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:30:38 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/07 15:24:32 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	chk_arg_length(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (arg[0] == '+' || arg[0] == '-')
	{
		i++;
		len--;
	}
	while (arg[i] == '0')
		i++;
	while (arg[i++])
		len++;
	return (len);
}

static int	is_numeric(char *arg)
{
	int	i;

	if (!arg)
		return (0);
	i = -1;
	if (arg[0] == '+' || arg[0] == '-')
		i++;
	while (arg[++i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
	}
	return (1);
}

int			check_arg(char *arg)
{
	int	len;

	len = chk_arg_length(arg);
	if (!is_numeric(arg) || len > 11 || len < 0)
		return (0);
	else
		return (1);
}

void		check_duplicate(t_node *a)
{
	int		cur_value;
	t_node	*temp;

	while (a->next)
	{
		temp = a->next;
		cur_value = a->value;
		while (temp)
		{
			if (temp->value == cur_value)
				print_error();
			if (temp->next)
				temp = temp->next;
			else
				break ;
		}
		a = a->next;
	}
	while (a->prev)
		a = a->prev;
}
