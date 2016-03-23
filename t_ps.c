/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:55:55 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/23 22:49:42 by dmoureu-         ###   ########.fr       */
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
	this->graphique = 0;
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
	char	*out;
	nb = 0;
	psa = ps->action;
	while (psa)
	{
		nb++;
		psa = psa->next;
	}
	out = (char*)malloc(sizeof(char) * ((nb * 4) + 1));
	ft_memset(out, '\0', ((nb * 4) + 1));
	if (!ps->verbose)
	{
		psa = ps->action;
		while (psa)
		{
			ft_strcat(out, actiontostr(psa->type));
			psa = psa->next;
			if (psa)
				ft_strcat(out, " ");
			else
				ft_strcat(out, "\n");
		}
		ft_putstr(out);
	}
	if (ps->verbose)
		ft_printf("coups:[%d]", nb);
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
	if (ps->graphique)
		viewps(ps);
}

void	viewps(t_ps *this)
{
	ft_printf("\n============\n");
	ft_printf("pile a:");
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
