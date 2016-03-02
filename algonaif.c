/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algonaif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:16 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 12:56:14 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "push_swap.h"

void	algonaif(t_ps *ps)
{
	while (stacklen(ps->stacka) > 1)
	{
		algonaifresolve(ps);
	}
	while (stacklen(ps->stackb) > 0)
	{
		pa(ps);
	}
}

void	algonaifresolve(t_ps *ps)
{
	int		maxa;
	int		pos;
	int		posmax;
	int		rotate;
	t_dnode	*c;

	maxa = INT_MAX;
	pos = 0;
	rotate = 0;
	posmax = 0;
	c = ps->stacka->list;
	while (c)
	{
		pos++;
		if (c->value < maxa)
		{
			posmax = pos;
			maxa = c->value;
		}
		c = c->next;
	}
	if (posmax > stacklen(ps->stacka) / 2)
	{
		rotate = (stacklen(ps->stacka) - posmax) + 1;
		while (rotate > 0)
		{
			rra(ps);
			rotate--;
		}
	}
	else
	{
		rotate = posmax - 1;
		while (rotate > 0)
		{
			ra(ps);
			rotate--;
		}
	}
	pb(ps);
}
