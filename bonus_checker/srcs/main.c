/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:52:46 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/08 17:25:10 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

int		main(int argc, char *argv[])
{
	t_stack *a;
	t_stack	*b;

	if (argc > 1)
	{
		a = init_stack();
		a->top = make_stack(argc, argv, &a);
		check_duplicate(a->top);
		b = init_stack();
		checker(a, b);
		free_all(a, b);
	}
	return (0);
}
