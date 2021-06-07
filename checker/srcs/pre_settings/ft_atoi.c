/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:31:01 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/07 15:24:37 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_atoi(char *arg)
{
	int			i;
	int			sign;
	long long	value;

	if (!check_arg(arg))
		print_error();
	i = 0;
	sign = 1;
	value = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		if (arg[i++] == '-')
			sign = -1;
	}
	while (arg[i])
		value = value * 10 + (arg[i++] - '0');
	value = value * sign;
	if (value > MAX_INT || value < MIN_INT)
		print_error();
	return (value);
}
