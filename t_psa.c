/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_psa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:09:26 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 12:16:16 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_psa	*newpsa(enum e_action action)
{
	t_psa	*this;

	this = (t_psa*)malloc(sizeof(t_psa));
	this->type = action;
	this->next = NULL;
	return (this);
}

char	*actiontostr(enum e_action type)
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

int		countaction(t_ps *ps)
{
	t_psa	*psa;
	int		nb;

	if (ps->bad)
		return (INT_MAX);
	nb = 0;
	psa = ps->action;
	while (psa)
	{
		nb++;
		psa = psa->next;
	}
	return (nb);
}

void	viewactionconcat(t_psa *psa, char *out)
{
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

void	actionps(t_ps *ps, enum e_action type)
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
