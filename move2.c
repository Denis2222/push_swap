/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 07:37:27 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 07:39:32 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_ps *this)
{
	rotatestack(this->stacka);
	rotatestack(this->stackb);
	actionps(this, RR);
}

void	rra(t_ps *this)
{
	if (stacklen(this->stacka) > 1)
	{
		revrotatestack(this->stacka);
		actionps(this, RRA);
	}
}

void	rrb(t_ps *this)
{
	if (stacklen(this->stackb) > 1)
	{
		revrotatestack(this->stackb);
		actionps(this, RRB);
	}
}

void	rrr(t_ps *this)
{
	revrotatestack(this->stacka);
	revrotatestack(this->stackb);
	actionps(this, RRR);
}
