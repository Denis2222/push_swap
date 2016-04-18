/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 07:36:46 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 07:39:36 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *this)
{
	if (stacklen(this->stacka) > 1)
	{
		swapstack(this->stacka);
		actionps(this, SA);
	}
}

void	sb(t_ps *this)
{
	if (stacklen(this->stackb) > 1)
	{
		swapstack(this->stackb);
		actionps(this, SB);
	}
}

void	ss(t_ps *this)
{
	swapstack(this->stacka);
	swapstack(this->stackb);
	actionps(this, SS);
}
