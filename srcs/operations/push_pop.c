#include "push_swap.h"

static void	from_size_one(t_stack *from, t_stack *to)
{
	if (to->size == 0)
	{
		to->top = from->top;
		to->bottom = to->top;
	}
	else
	{
		to->top->prev = from->top;
		from->top->next = to->top;
		to->top = to->top->prev;
	}
	from->top = NULL;
	from->bottom = NULL;
}

void	push_pop(t_stack *from, t_stack *to)
{
	if (from->size == 0)
		return ;
	if (from->size == 1)
		from_size_one(from, to);
	else
	{
		if (to->size == 0)
		{
			to->top = from->top;
			to->bottom = to->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->next = NULL;
		}
		else
		{
			to->top->prev = from->top;
			from->top = from->top->next;
			from->top->prev = NULL;
			to->top->prev->next = to->top;
			to->top = to->top->prev;
		}
	}
	to->size++;
	from->size--;
}
