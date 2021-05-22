#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "structures.h"

void	print_error(void);
int		check_arg(char *arg);
int		ft_atoi(char *arg);
t_listp	*make_listp(void);
t_stack	*make_stack(int argc, char **argv, t_listp **listp);

#endif