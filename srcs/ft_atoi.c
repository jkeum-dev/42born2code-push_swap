#include "push_swap.h"

int	ft_atoll(char *arg)
{
	int			i;
	int			sign;
	long long	value;

	if (!check_arg(arg))
		exit(0);
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
	if (value > INT32_MAX || value < INT32_MIN)
		exit(0);
	return (value);
}
