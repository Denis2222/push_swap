/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 07:39:10 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 07:39:26 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_ps *this)
{
	if (stacklen(this->stackb) > 0)
	{
		pushstack(this->stacka, this->stackb);
		actionps(this, PA);
	}
}

void	pb(t_ps *this)
{
	if (stacklen(this->stacka) > 0)
	{
		pushstack(this->stackb, this->stacka);
		actionps(this, PB);
	}
}

void	ra(t_ps *this)
{
	if (stacklen(this->stacka) > 1)
	{
		rotatestack(this->stacka);
		actionps(this, RA);
	}
}

void	rb(t_ps *this)
{
	if (stacklen(this->stackb) > 1)
	{
		rotatestack(this->stackb);
		actionps(this, RB);
	}
}
