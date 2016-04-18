/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:37:02 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 21:29:19 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		checkinput(char *av, t_stack *stack, t_ps *ps)
{
	int		nb;
	char	*in;

	in = av;
	while (*in)
	{
		if (!isdigit(*in) && *in != '-' && *in != '+')
			errornodigit(av, ps);
		in++;
	}
	nb = ft_atoi(av);
	checknbstack(stack, nb, ps);
	return (nb);
}
