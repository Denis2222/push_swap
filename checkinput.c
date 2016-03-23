/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:37:02 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/23 18:27:06 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errornodigit(char *str)
{
	ft_printf("{red}{bold}No digit detected !{eoc} {green}{bold}%s{eoc}", str);
	exit(EXIT_FAILURE);
}

void	errordoublevalue(int nb)
{
	ft_printf("{red}{bold}Double value detected {inv} %d {eoc}", nb);
	exit(EXIT_FAILURE);
}

int		checknbstack(t_stack *stack, int nb)
{
	t_dnode *current;

	current = stack->list;
	while (current)
	{
		if (current->value == nb)
			errordoublevalue(nb);
		current = current->next;
	}
	return (1);
}

int		checkinput(char *av, t_stack *stack)
{
	int		nb;
	char	*in;

	in = av;
	while (*in)
	{
		if (!isdigit(*in) && *in != '-' && *in != '+')
			errornodigit(av);
		in++;
	}
	nb = ft_atoi(av);
	checknbstack(stack, nb);
	return (nb);
}
