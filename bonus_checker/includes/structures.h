/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:52:23 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/07 16:52:24 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# define A 1
# define B 2
# define ALL 3

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;

struct	s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
};

struct	s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
};

#endif
