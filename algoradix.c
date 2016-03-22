/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoradix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:02:12 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/21 20:25:19 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getbitval(int n, int bit)
{
	if (n < 0)
		n *= -1;
	if (n >> bit & 1)
		return (1);
	return (0);
}

int	getunsignedmax(t_stack *stack)
{
	int	max;

	max = 0;
	t_dnode *node;
	node = stack->list;

	while (node)
	{
		if (node->value > max)
			max = node->value;
		else if(node->value * -1 > max)
			max = node->value * -1;
		node = node->next;
	}
	return (max);
}

int	getbitmax(int max)
{
	int i;
	int	bit;

	i = 0;
	bit = 0;
	while (i < 32)
	{
		if (getbitval(max, i))
			bit = i;
		i++;
	}
	return (bit);
}

int	algoradixwhatpush(t_dnode *node, int bit)
{
	int		bittomove;
	int		bitpos;
	int		pos;

	pos = 0;
	bittomove = 0;
	bitpos = 0;
	while (node && !bittomove)
	{
		if (!getbitval(node->value, bit))
		{
			bittomove = 1;
			bitpos = pos;
		}
		node = node->next;
		pos++;
	}
	if (bittomove)
		return (bitpos);
	return (-1);
}

void	algoradixpush(t_ps *ps, int bit)
{
	int	nextpos;
	int	i;

	i = 0;
	nextpos = algoradixwhatpush(ps->stacka->list, bit);
	//sleep(1);
	while (nextpos >= 0)
	{
		if (nextpos <= stacklen(ps->stacka) / 2)
		{
			i = 0;
			while (i < nextpos)
			{
				ra(ps);
				i++;
			}
		}
		else
		{
			i = 0;
			while (i < stacklen(ps->stacka) - nextpos)
			{
				rra(ps);
				i++;
			}
		}
		pb(ps);
		nextpos = algoradixwhatpush(ps->stacka->list, bit);
		viewps(ps);
	}
	viewps(ps);
	while (stacklen(ps->stackb))
	{
		rrb(ps);
		pa(ps);
	}
	viewps(ps);
}

void	algoradix(t_ps *ps)
{
	int	bitmax;
	int	bit;

	bit = 0;
	bitmax = getbitmax(getunsignedmax(ps->stacka));
	while (bit <= bitmax)
	{
		algoradixpush(ps, bit);
		bit++;
	}
	//algobubble(ps);
}
