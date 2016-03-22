/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/22 01:40:51 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isparam(char c)
{
	if (c == 'v')
	{
		return (1);
	}
	if (c == 'b')
	{
		return (1);
	}
	return (0);
}

int	checkparam(t_ps *ps, int ac, char **av)
{
	int valid;
	int	i;
	int	a;

	a = 1;
	i = 1;
	valid = 1;
	while (i < ac && valid)
	{
		if (av[i][0] == '-')
		{
			while (isparam(av[i][a]))
			{
				if (av[i][a] == 'v')
					ps->verbose = 1;
				if (av[i][a] == 'b')
					ps->algo = 1;
				a++;
			}
			i++;
		}
		else
		{
			valid = 0;
		}
	}
	return (i);
}

int	main(int ac, char **av)
{
	t_ps	*ps;
	int		i;
	int		nb;
//	int		bad;

	ps = newps();
	ps->stacka = newstack();
	ps->stackb = newstack();
	ps->stacko = newstack();
	if (ac > 1)
	{
		i = checkparam(ps, ac, av);
		while (i < ac)
		{
			nb = checkinput(av[i], ps->stacka);
			addstackback(ps->stacka, nb);
			addstackopti(ps->stacko, nb);
			i++;
		}
		if (ps->verbose)
			viewps(ps);
		algot(ps);
		//		algot(ps);
//		bad = badvalue(ps->stacka);
//		ft_printf("%d", bad);
//		pushvaluetob(ps, bad);
//		checkbasic(ps->stacka, 'a');
		if (ps->verbose)
			viewps(ps);

		viewaction(ps);
	}
	return (0);
}
