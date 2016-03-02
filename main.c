/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:33:04 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/02 17:46:05 by dmoureu-         ###   ########.fr       */
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
		i = 1;
		while (i < ac)
		{
			nb = checkinput(av[i], ps->stacka);
			addstackback(ps->stacka, nb);
			addstackopti(ps->stacko, nb);
			i++;
		}

		//addstack(ps->stacko, 4);
		//addstack(ps->stacko, 8);
		//addstackback(ps->stacko, 16);
		//addstack(ps->stacko, 1);

		viewps(ps);

		ft_printf("value first elen stacko%d", ps->stacko->list->value);
		//algonaif(ps);
		//viewps(ps);
	}
	return (0);
}
