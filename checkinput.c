/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:37:02 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/19 08:57:57 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	errornodigit(char *str, t_ps *ps)
{
	if (!ps->verbose)
		ft_putstr_fd("Error\n", 2);
	else
		ft_printf("{red}{bold}No digit !{eoc} {green}{bold}%s{eoc}", str);
	exit(EXIT_FAILURE);
}

void	errordoublevalue(int nb, t_ps *ps)
{
	if (!ps->verbose)
		ft_putstr_fd("Error\n", 2);
	else
		ft_printf("{red}{bold}Double value detected {inv} %d {eoc}", nb);
	exit(EXIT_FAILURE);
}

int		checknbstack(t_stack *stack, int nb, t_ps *ps)
{
	t_dnode *current;

	current = stack->list;
	while (current)
	{
		if (current->value == nb)
			errordoublevalue(nb, ps);
		current = current->next;
	}
	return (1);
}

int	checkstrint( char *str)
{
	if (*str == '-')
		++str;
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		else
			++str;
	}
	return (1);
}

int		checkinput(char *av, t_stack *stack, t_ps *ps)
{
	long	nb;
	char	*in;
	int		c;

	c = 0;
	in = av;
	if (!checkstrint(in))
		errornodigit(av, ps);
	nb = ft_atoi(av);
	if (nb > INT_MAX || nb < INT_MIN)
	{
		if (!ps->verbose)
			ft_putstr_fd("Error\n", 2);
		else
			ft_printf("{red}{bold}Non int detected {inv} %lld {eoc}", nb);
		exit(EXIT_FAILURE);
	}
	checknbstack(stack, nb, ps);
	return (nb);
}
