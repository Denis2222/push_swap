/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:24:14 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/23 22:43:31 by dmoureu-         ###   ########.fr       */
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
	if (c == 'g')
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
				if (av[i][a] == 'g')
					ps->graphique = 1;
				a++;
			}
			if (!ft_isdigit(av[i][1]))
				i++;
			else
				valid = 0;
		}
		else
			valid = 0;
	}
	return (i);
}

