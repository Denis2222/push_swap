/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/19 03:23:48 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	*algo(int ac, char **av, void (f) (t_ps*))
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
	f(ps);
	if (ps->verbose)
		viewps(ps);
	return (ps);
}

int		comparealgo(t_ps **test)
{
	int		i;
	int		min;
	int		best;

	best = 0;
	min = -1;
	i = -1;
	while (test[++i])
		if (min < 0 || countaction(test[i]) < best)
		{
			best = countaction(test[i]);
			min = i;
		}
	i = -1;
	while (test[++i])
	{
		if (test[i]->algo)
		{
			if (min != i)
				ft_printf("[%d] %d\n", i, countaction(test[i]));
			else
				ft_printf("{green}[%d] %d{eoc} \n", i, countaction(test[i]));
		}
	}
	return (min);
}

int		main(int ac, char **av)
{
	t_ps	**test;
	int		min;

	if (ac > 1)
	{
		test = testarray(
				algo(ac, av, algom),
				algo(ac, av, algonaif),
				algo(ac, av, algobubble),
				algo(ac, av, algobubblerev));
		min = comparealgo(test);
		viewaction(test[min]);
		if (test[min]->result && !test[min]->algo)
			ft_printf("[move:%d]\n", countaction(test[min]));
	}
	return (0);
}
