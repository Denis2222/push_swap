/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:55:55 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/22 01:40:09 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps *newps(void)
{
	t_ps	*this;

	this = (t_ps*)malloc(sizeof(t_ps));
	this->stacka = NULL;
	this->stackb = NULL;
	this->stacko = NULL;
	this->action = NULL;
	this->verbose = 0;
	this->algo = 0;
	return (this);
}

char *actiontostr(Action type)
{
	if (type == 0)
		return ("sa");
	if (type == 1)
		return ("sb");
	if (type == 2)
		return ("ss");
	if (type == 3)
		return ("ra");
	if (type == 4)
		return ("rb");
	if (type == 5)
		return ("rr");
	if (type == 6)
		return ("rra");
	if (type == 7)
		return ("rrb");
	if (type == 8)
		return ("rrr");
	if (type == 9)
		return ("pa");
	if (type == 10)
		return ("pb");
	return ("");
}

void	viewaction(t_ps *ps)
{
	t_psa	*psa;
	int		nb;

	nb = 0;
	if (!ps->verbose)
	{
		psa = ps->action;
		while (psa)
		{
			nb++;
			ft_printf("%s", actiontostr(psa->type));
			psa = psa->next;
			if (psa)
				ft_printf(" ");
			else
				ft_printf("\n");
		}
		if (ps->verbose)
			ft_printf("coups:[%d]", nb);
	}
}

void	actionps(t_ps *ps, Action type)
{
	t_psa *psa;

	if (ps->verbose)
		ft_printf("%s ", actiontostr(type));
	psa = ps->action;
	if (psa)
	{
		while (psa->next)
			psa = psa->next;
		psa->next = newpsa(type);
	}
	else
	{
		ps->action = newpsa(type);
	}
}

void	viewps(t_ps *this)
{
	ft_printf("\npile a:");
	viewpile(this->stacka);
	ft_printf("\npile b:");
	viewpile(this->stackb);
//	ft_printf("\npile o:");
//	viewpile(this->stacko);
	ft_printf("\n============\n");
}

void	sa(t_ps *this)
{
	if (stacklen(this->stacka) > 1)
	{
		actionps(this, SA);
		swapstack(this->stacka);
	}
}

void	sb(t_ps *this)
{
	if (stacklen(this->stackb) > 1)
	{
		actionps(this, SB);
		swapstack(this->stackb);
	}
}

void	ss(t_ps *this)
{
	actionps(this, SS);
	swapstack(this->stacka);
	swapstack(this->stackb);
}

void	pa(t_ps *this)
{
	if (stacklen(this->stackb) > 0)
	{
		actionps(this, PA);
		pushstack(this->stacka, this->stackb);
	}
}

void	pb(t_ps *this)
{
	if (stacklen(this->stacka) > 0)
	{
		actionps(this, PB);
		pushstack(this->stackb, this->stacka);
	}
}

void	ra(t_ps *this)
{
	if (stacklen(this->stacka) > 1)
	{
		actionps(this, RA);
		rotatestack(this->stacka);
	}
}

void	rb(t_ps *this)
{
	if (stacklen(this->stackb) > 1)
	{
		actionps(this, RB);
		rotatestack(this->stackb);
	}
}

void	rr(t_ps *this)
{
	actionps(this, RR);
	rotatestack(this->stacka);
	rotatestack(this->stackb);
}

void	rra(t_ps *this)
{
	if (stacklen(this->stacka) > 1)
	{
		actionps(this, RRA);
		revrotatestack(this->stacka);
	}
}

void	rrb(t_ps *this)
{
	if (stacklen(this->stackb) > 1)
	{
		actionps(this, RRB);
		revrotatestack(this->stackb);
	}
}

void	rrr(t_ps *this)
{
	actionps(this, RRR);
	revrotatestack(this->stacka);
	revrotatestack(this->stackb);
}
