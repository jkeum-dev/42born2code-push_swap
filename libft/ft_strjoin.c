/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 06:05:01 by jkeum             #+#    #+#             */
/*   Updated: 2021/05/26 19:40:58 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(res = (char *)malloc(s1_len + s2_len + 1)))
		return (NULL);
	i = -1;
	while (++i < s1_len)
		res[i] = s1[i];
	j = -1;
	while (++j < s2_len)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}
