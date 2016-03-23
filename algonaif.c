/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algonaif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:16 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/23 20:42:07 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	algonaif(t_ps *ps)
{
	while (stacklen(ps->stacka) > 1 && stackorder(ps->stacka))
	{
		//viewps(ps);
		algonaifresolve(ps);
	}
	while (stacklen(ps->stackb) > 0)
	{
		pa(ps);
	}
}

int		posminstack(t_stack *stack)
{
	int	posmin;
	int	min;
	t_dnode	*c;
	int		pos;

	pos = 0;
	c = stack->list;
	min = INT_MAX;
	posmin = 0;
	while (c)
	{
		pos++;
		if (c->value < min)
		{
			posmin = pos;
			min = c->value;
		}
		c = c->next;
	}
	return (posmin);
}

void	algonaifresolve(t_ps *ps)
{
	int		posmin;
	int		rotate;

	rotate = 0;
	posmin = posminstack(ps->stacka);
	if (posmin > stacklen(ps->stacka) / 2 + 1)
	{
		rotate = (stacklen(ps->stacka) - posmin) + 1;
		while (rotate > 0)
		{
			rra(ps);
			rotate--;
		}
	}
	else
	{
		rotate = posmin - 1;
		while (rotate > 0)
		{
			ra(ps);
			rotate--;
		}
	}
	if (stackorder(ps->stacka))
		pb(ps);
}
