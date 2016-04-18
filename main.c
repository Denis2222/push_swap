/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 23:55:31 by dmoureu-         ###   ########.fr       */
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
		nb = checkinput(av[i], ps->stacka, ps);
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
		nb = checkinput(av[i], ps->stacka, ps);
		addstackback(ps->stacka, nb);
		i++;
	}
	if (ps->verbose)
		viewps(ps);
	if (stacklen(ps->stacka) > 0 && stackorder(ps->stacka) != 0)
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
		nb = checkinput(av[i], ps->stacka, ps);
		addstackback(ps->stacka, nb);
		i++;
	}
	if (ps->verbose)
		viewps(ps);
	if (stacklen(ps->stacka) > 0 && stackorder(ps->stacka) != 0)
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
		nb = checkinput(av[i], ps->stacka, ps);
		addstackback(ps->stacka, nb);
		i++;
	}
	if (ps->verbose)
		viewps(ps);
	if (stacklen(ps->stacka) > 0 && stackorder(ps->stacka) != 0)
		algom(ps);
	if (ps->verbose)
		viewps(ps);
	return (ps);
}

int		main(int ac, char **av)
{
	t_ps	**test;
	int		i;
	int		min;
	int		best;

	best = 0;
	i = -1;
	min = -1;
	if (ac > 1)
	{
		test = testarray(mainm(ac, av), mainnaif(ac, av),
					mainbubble(ac, av), mainbubblerev(ac, av));
		while (test[++i])
		{
			if (min < 0 || countaction(test[i]) < best)
			{
				best = countaction(test[i]);
				min = i;
			}
		}
		viewaction(test[min]);
		if (test[min]->result)
			ft_printf("[move:%d]\n", countaction(test[min]));
	}
	return (0);
}
