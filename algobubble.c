/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobubble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:16 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/22 01:29:45 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		orderbublestack(t_stack *stack)
{
	int		order;
	int		way;
	t_dnode	*node;
	int		action;

	action = 0;
	node = stack->list;
	way = 1;
	order = 0;
	while (stackorder(stack) > 0)
	{
		order = stackorder(stack);
		if (node->value > node->next->value &&
			node->value != stack->start->value)
		{
			swapstack(stack);
			action++;
		}
		else
		{
			if (stack->start == stack->list)
				way = 0;
			if (way)
			{
				revrotatestack(stack);
				action++;
			}
			else
			{
				rotatestack(stack);
				action++;
			}
		}
	}
	return (action);
}

void	algobubble(t_ps *ps)
{
	int	order;
	int	way;

	way = 1;
	order = 0;
	while (stackorder(ps->stacka) > 0)
	{
		order = stackorder(ps->stacka);
		if (ps->stacka->list->value > ps->stacka->list->next->value &&
			ps->stacka->list->value != ps->stacka->start->value)
			sa(ps);
		else
		{
			if (ps->stacka->start == ps->stacka->list)
				way = 0;
			if (way)
				rra(ps);
			else
				ra(ps);
		}
	}
}
