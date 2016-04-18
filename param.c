/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 18:24:14 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 06:50:37 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		isparam(char c)
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

void	applyparam(t_ps *ps, char c)
{
	if (c == 'v')
		ps->verbose = 1;
	if (c == 'b')
		ps->algo = 1;
	if (c == 'g')
		ps->graphique = 1;
}

int		checkparam(t_ps *ps, int ac, char **av)
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
				applyparam(ps, av[i][a]);
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
