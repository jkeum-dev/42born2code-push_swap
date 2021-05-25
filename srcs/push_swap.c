#include "push_swap.h"

int		is_big_three(int value, t_value *big)
{
	if (value != big->first && value != big->second && value != big->third)
		return (0);
	else
		return (1);
}

void	left_three_value_a(t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (++i < a->size)
	{
		if (!is_big_three(a->top->value, a->big))
			push_stack(a, b, B);
		else
			rotate_stack(a, A);
	}
	while (a->top->prev)
		a->top = a->top->prev;
}

void	push_swap(t_stack *a, t_stack *b)
{
	/*	1. Only the three largest numbers are left on stack a.	*/
	left_three_value_a(a, b);
	/*	2. Sort stack a.	*/
	/*	3. Find the max value on stack b.	*/
	/*	4. Until the value reaches top,
		ra if the value is above half, and rra if it is below half.	*/
	/*	5. pa	*/
	/*	6. Repeat 3~5 until the stack b is empty.	*/
}