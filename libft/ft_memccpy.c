/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 21:47:21 by jkeum             #+#    #+#             */
/*   Updated: 2020/10/07 21:47:27 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*temp;
	unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	temp = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n--)
	{
		*temp = *s;
		if (*s == (unsigned char)c)
			return (temp + 1);
		temp++;
		s++;
	}
	return (NULL);
}
