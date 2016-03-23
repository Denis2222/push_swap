/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/23 22:51:19 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int ac, char **av)
{
	t_ps	*ps;
	int		i;
	int		nb;

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
		algobubble(ps);
		if (ps->verbose)
			viewps(ps);
		viewaction(ps);
	}
	return (0);
}
