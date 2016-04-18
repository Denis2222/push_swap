/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algobubble.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:16 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 04:15:25 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checktwolast(t_ps *ps)
{
	t_dnode *current;
	t_dnode *prev;

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

void	algobubble(t_ps *ps, int way)
{
	int	order;

	if (stacklen(ps->stacka) > 4)
		checktwolast(ps);
	order = 0;
	while (stackorder(ps->stacka) > 0)
	{
		order = stackorder(ps->stacka);
		if (ps->stacka->list->value > ps->stacka->list->next->value &&
			ps->stacka->list->value != ps->stacka->start->value)
			sa(ps);
		else
		{
			if (way)
				rra(ps);
			else
				ra(ps);
		}
	}
}
