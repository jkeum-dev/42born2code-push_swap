/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeum <jkeum@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 21:58:51 by jkeum             #+#    #+#             */
/*   Updated: 2021/06/07 15:28:47 by jkeum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define OPEN_MAX 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

int		get_next_line(int fd, char **line);
int		ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *save, char *buff);

#endif
