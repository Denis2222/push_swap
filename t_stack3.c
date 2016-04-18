/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 08:36:38 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 08:38:17 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		countformovetofirstright(t_stack *stack, int n)
{
	t_dnode	*node;
	int		i;

	i = 0;
	node = stack->list;
	while (node)
	{
		if (node->value == n)
			return (i);
		i++;
		node = node->next;
	}
	return (0);
}

int		countformovetofirstleft(t_stack *stack, int n)
{
	t_dnode	*node;
	int		i;

	i = 1;
	node = lastnode(stack);
	while (node)
	{
		if (node->value == n)
			return (i * -1);
		i++;
		node = node->prev;
	}
	return (0);
}

int		countformovetofirst(t_stack *stack, int n)
{
	t_dnode	*node;
	int		pos;
	int		i;
	int		len;

	node = stack->list;
	pos = 1;
	i = 1;
	while (node)
	{
		if (node->value == n)
			pos = i;
		i++;
		node = node->next;
	}
	len = stacklen(stack);
	if (pos <= ((len + 1) / 2))
		return (countformovetofirstright(stack, n));
	else
		return (countformovetofirstleft(stack, n));
	return (0);
}

int		countforpos(t_stack *stack, int n)
{
	int		max;
	int		min;
	t_dnode	*node;
	int		nextval;

	nextval = -1;
	node = stack->list;
	max = maxvalue(stack);
	min = minvalue(stack);
	if (n > max || n < min)
		return (countformovetofirst(stack, max));
	else
	{
		nextval = min;
		while (node)
		{
			if (node->value < n && node->value > nextval)
				nextval = node->value;
			node = node->next;
		}
		return (countformovetofirst(stack, nextval));
	}
}
