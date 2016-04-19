/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobubble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:16 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/19 01:47:43 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checktwolast(t_ps *ps)
{
	t_dnode *current;
	t_dnode *prev;

	if (stacklen(ps->stacka) > 4)
	{
		current = ps->stacka->list;
		while (current->next)
		{
			prev = current;
			current = current->next;
		}
		if (prev->value > current->value)
		{
			rra(ps);
			rra(ps);
			sa(ps);
			ra(ps);
			ra(ps);
		}
	}
}

void	algobubble(t_ps *ps)
{
	int	order;
	int	i;

	i = 0;
	if (stacklen(ps->stacka) > 0 && stackorder(ps->stacka) != 0)
	{
		checktwolast(ps);
		order = 0;
		while (stackorder(ps->stacka) > 0 && i < BUBBLE_MAX)
		{
			order = stackorder(ps->stacka);
			if (ps->stacka->list->value > ps->stacka->list->next->value &&
				ps->stacka->list->value != ps->stacka->start->value)
				sa(ps);
			else
				ra(ps);
			i++;
		}
		if (stackorder(ps->stacka) > 0)
			ps->bad = 1;
	}
}

void	algobubblerev(t_ps *ps)
{
	int	order;
	int	i;

	i = 0;
	if (stacklen(ps->stacka) > 0 && stackorder(ps->stacka) != 0)
	{
		checktwolast(ps);
		order = 0;
		while (stackorder(ps->stacka) > 0 && i < BUBBLE_MAX)
		{
			order = stackorder(ps->stacka);
			if (ps->stacka->list->value > ps->stacka->list->next->value &&
				ps->stacka->list->value != ps->stacka->start->value)
				sa(ps);
			else
			{
				rra(ps);
			}
			i++;
		}
		if (stackorder(ps->stacka) > 0)
			ps->bad = 1;
	}
}
