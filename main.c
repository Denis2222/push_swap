/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/11 06:23:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*mainnaif(int ac, char **av)
{
	t_ps	*ps;
	int		i;
	int		nb;

	ps = newps();
	ps->stacka = newstack();
	ps->stackb = newstack();
	i = checkparam(ps, ac, av);
	while (i < ac)
	{
		nb = checkinput(av[i], ps->stacka);
		addstackback(ps->stacka, nb);
		i++;
	}
	if (ps->verbose)
		viewps(ps);
	algonaif(ps);
	if (ps->verbose)
		viewps(ps);
	return (ps);
}


t_ps	*mainbubble(int ac, char **av)
{
	t_ps	*ps;
	int		i;
	int		nb;

	ps = newps();
	ps->stacka = newstack();
	ps->stackb = newstack();
	i = checkparam(ps, ac, av);
	while (i < ac)
	{
		nb = checkinput(av[i], ps->stacka);
		addstackback(ps->stacka, nb);
		i++;
	}
	if (ps->verbose)
		viewps(ps);
	algobubble(ps);
	if (ps->verbose)
		viewps(ps);
	return (ps);
}

t_ps	*mainm(int ac, char **av)
{
	t_ps	*ps;
	int		i;
	int		nb;

	ps = newps();
	ps->stacka = newstack();
	ps->stackb = newstack();
	i = checkparam(ps, ac, av);
	while (i < ac)
	{
		nb = checkinput(av[i], ps->stacka);
		addstackback(ps->stacka, nb);
		i++;
	}
	if (ps->verbose)
		viewps(ps);
	algom(ps);
	if (ps->verbose)
		viewps(ps);
	return (ps);
}

int	main(int ac, char **av)
{
	t_ps	*psnaif;
	t_ps	*psbubble;
	t_ps	*psm;

	if (ac > 1)
	{
		psnaif = mainnaif(ac, av);
		psbubble = mainbubble(ac, av);
		psm = mainm(ac, av);


		viewaction(psm);
		ft_printf("%d %d %d",countaction(psnaif), countaction(psbubble), countaction(psm));
	}
	return (0);
}
