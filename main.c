/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 05:24:17 by dmoureu-         ###   ########.fr       */
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
	checktwolast(ps);
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
	
	ft_printf("%d", lastnode(ps->stacka)->value);
	algom(ps);
	if (ps->verbose)
		viewps(ps);
	return (ps);
}

int	main(int ac, char **av)
{
	t_ps	**test;
	int i;
	int min;
	int best;

	best = 0;
	i = 0;
	min = -1;
	test = (t_ps**)malloc(sizeof(t_ps) * 10);
	if (ac > 1)
	{
		test[0] = mainm(ac, av);
		test[1] = mainnaif(ac, av);
		test[2] = mainbubble(ac, av);
		test[3] = mainbubblerev(ac, av);
		test[4] = NULL;
		while (test[i])
		{
			if (min < 0 || countaction(test[i]) < best)
			{
				best = countaction(test[i]);
				min = i;
			}
		ft_printf("%d   %d\n", countaction(test[i]), min);
			i++;
		}
		viewaction(test[min]);
	}
	return (0);
}
