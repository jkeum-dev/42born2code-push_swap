#include "push_swap.h"

// void	push_node(t_stack **stack, t_node *node)
// {
// 	t_node	*new;

// 	new = init_node();
// 	new->value = node->value;
// 	if (!*stack)
// 	{
// 		*stack = init_stack();
// 		(*stack)->bottom = new;
// 		(*stack)->top = (*stack)->bottom;
// 	}
// 	else
// 	{
// 		(*stack)->top->prev = new;
// 		new->next = (*stack)->top;
// 		(*stack)->top = new;
// 	}
// 	(*stack)->size++;
// }

// void	pop_node(t_stack **stack)
// {
// 	if (!*stack)
// 		return ;
// 	if ((*stack)->top->next)
// 	{
// 		(*stack)->top = (*stack)->top->next;
// 		free((*stack)->top->prev);
// 		(*stack)->top->prev = NULL;
// 	}
// 	else
// 	{
// 		free((*stack)->top);
// 		(*stack)->top = NULL;
// 		(*stack)->bottom = NULL;
// 	}
// 	(*stack)->size--;
// }

void	push_pop(t_stack **from, t_stack **to)
{
	if ((*from)->size == 0)
		return ;
	if ((*from)->size == 1)
	{
		if ((*to)->size == 0)
		{
			(*to)->top = (*from)->top;
			(*to)->bottom = (*to)->top;
		}
		else
		{
			(*to)->top->prev = (*from)->top;
			(*from)->top->next = (*to)->top;
			(*to)->top = (*to)->top->prev;
		}
		(*from)->top = NULL;
		(*from)->bottom = NULL;
	}
	else
	{
		if ((*to)->size == 0)
		{
			(*to)->top = (*from)->top;
			(*to)->bottom = (*to)->top;
			(*from)->top = (*from)->top->next;
			(*from)->top->prev = NULL;
			(*to)->top->next = NULL;
		}
		else
		{
			(*to)->top->prev = (*from)->top;
			(*from)->top = (*from)->top->next;
			(*from)->top->prev = NULL;
			(*to)->top->prev->next = (*to)->top;
			(*to)->top = (*to)->top->prev;
		}
	}
	(*to)->size++;
	(*from)->size--;
}