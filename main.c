/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 04:20:58 by dmoureu-         ###   ########.fr       */
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
	algobubble(ps, 0);
	if (ps->verbose)
		viewps(ps);
	return (ps);
}

t_ps	*mainbubblerev(int ac, char **av)
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
	algobubble(ps, 1);
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
//	t_ps	**test;
	t_ps	*psnaif;
	t_ps	*psbubble;
	t_ps	*psbubblerev;
	t_ps	*psm;

//	test = (t_ps**)malloc(sizeof(t_ps) * 10);
	if (ac > 1)
	{
		psnaif = mainnaif(ac, av);
		psbubble = mainbubble(ac, av);
		psbubblerev = mainbubblerev(ac, av);
		psm = mainm(ac, av);


		viewaction(psm);
		ft_printf("\nnaif:%d\nbubble:%d\nbubblerev:%d\nalgom:%d",countaction(psnaif), countaction(psbubble), countaction(psbubblerev),countaction(psm));
	}
	return (0);
}
