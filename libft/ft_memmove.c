/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 21:58:57 by jkeum             #+#    #+#             */
/*   Updated: 2020/10/07 14:56:17 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp;
	const char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = src;
	temp = dest;
	if (dest <= src)
	{
		while (n--)
			*temp++ = *s++;
	}
	else
	{
		s += n;
		temp += n;
		while (n--)
			*--temp = *--s;
	}
	return (dest);
}
