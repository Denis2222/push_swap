/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoinsert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:17:58 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/23 22:40:11 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	posforval(t_stack *stack, int val)
{
	t_dnode	*c;
	int		pos;

	pos = 0;
	c = stack->list;
	while (c)
	{
		pos++;
		if (val > c->value && val < c->next->value)
			return (pos);
		c = c->next;
	}
	return (pos);
}

void	btoa(t_ps *ps)
{
	int	bval;
	int	pos;
	int	i;

	i = 0;
	bval = ps->stackb->list->value;
	pos = posforval(ps->stacka, bval);
	while (i < pos)
	{
		ra(ps);
		i++;
	}
	pa(ps);
	while (i)
	{
		rra(ps);
		i--;
	}
//	viewps(ps);
}

void	insertfirstbtoa(t_ps *ps)
{
	int	bval;

	bval = ps->stackb->list->value;
	if (bval > maxvalue(ps->stacka))
	{
		pa(ps);
		ra(ps);
	}
	else if (bval < minvalue(ps->stacka))
	{
		pa(ps);
	}
	else
	{
		//place in middle
		btoa(ps);
		//sleep(1);
	}
}

void	algoinsert(t_ps *ps)
{
	while (stacklen(ps->stacka) > 1)
	{
		pb(ps);
	}
	//viewps(ps);
	while (stackorder(ps->stacka) > 0 || stacklen(ps->stackb))
	{
		insertfirstbtoa(ps);
//		viewps(ps);
//		sleep(1);
	}
}
