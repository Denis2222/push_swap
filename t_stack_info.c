#include "push_swap.h"

int	stackorder(t_stack *stack)
{
	int		order;
	t_dnode	*current;

	current = stack->list;
	order = 0;
	while (current->next)
	{
		if (current->value > current->next->value)
			order++;
		current = current->next;
	}
	return (order);
}

void	resolveinline(t_stack *stack)
{
	int	order;
	int	way;

	way = 1;
	order = 0;
	while (stackorder(stack) > 0)
	{
		order = stackorder(stack);
		if (stack->list->value > stack->list->next->value && stack->list->value != stack->start->value)
			swapstack(stack);
		else
		{
			if (stack->start == stack->list)
				way = 0;
			if (way)
				revrotatestack(stack);
			else
				rotatestack(stack);
		}
		sleep(1);
	}
}
