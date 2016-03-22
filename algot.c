/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 20:32:06 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/22 01:53:40 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checkrotate(t_stack *stack, char c)
{
	int	order;

	order = stackorder(stack);
	rotatestack(stack);
	if (stackorder(stack) < order)
	{
		ft_printf("r%c ", c);
	}
	else
	{
		revrotatestack(stack);
	}
}

void	checkswap(t_stack *stack, char c)
{
	int	order;

	order = stackorder(stack);
	swapstack(stack);
	if (stackorder(stack) < order)
	{
		ft_printf("s%c ", c);
	}
	else
	{
		swapstack(stack);
	}
}

void	checkswitchrotate(t_stack *stack, char c)
{
	int	order;

	order = stackorder(stack);
	swapstack(stack);
	rotatestack(stack);
	if (stackorder(stack) < order)
	{
		ft_printf("s%c r%c", c, c);
	}
	else
	{
		revrotatestack(stack);
		swapstack(stack);
	}
}

void	checkbasic(t_stack *stack, char c)
{
	checkrotate(stack, c);
	checkswap(stack, c);
	checkswitchrotate(stack, c);
}

void	algot(t_ps *ps)
{
	//While not order
	while (stackorder(ps->stacka) > 0 || stacklen(ps->stackb))
	{
		// While value not ordered in stacka
		while (badvalue(ps->stacka) <= maxvalue(ps->stacka))
		{
			ft_printf("%d", badvalue(ps->stacka));
			pushvaluetob(ps, badvalue(ps->stacka));
		}
		while (stacklen(ps->stackb))
		{
			if (ps->stackb->list->value < ps->stacka->list->value)
				pa(ps);
			if (ps->stacka->list->next)
			{
				if (ps->stacka->list->next->value > ps->stackb->list->value && ps->stacka->list->value < ps->stackb->list->value)
				{
					ra(ps);
					pa(ps);
					rra(ps);
				}
			}
			else
			{
				ra(ps);
			}
			sleep(1);
		}
	}
}
