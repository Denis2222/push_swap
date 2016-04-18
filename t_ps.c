/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:55:55 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 09:22:40 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*newps(void)
{
	t_ps	*this;

	this = (t_ps*)malloc(sizeof(t_ps));
	this->stacka = NULL;
	this->stackb = NULL;
	this->stacko = NULL;
	this->action = NULL;
	this->bad = 0;
	this->verbose = 0;
	this->result = 0;
	this->algo = 0;
	this->graphique = 0;
	return (this);
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
		viewactionconcat(ps->action, out);
	}
	if (ps->verbose)
		ft_printf("coups:[%d]", nb);
}

void	viewps(t_ps *this)
{
	ft_printf("\n============\n");
	ft_printf("pile a:");
	viewpile(this->stacka);
	ft_printf("\npile b:");
	viewpile(this->stackb);
	ft_printf("\n============\n");
}
