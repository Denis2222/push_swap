/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 06:54:21 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 06:57:31 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	stackorder(t_stack *stack)
{
	int		order;
	t_dnode	*current;

	current = stack->list;
	order = 0;
	while (current->next)
	{
		if (current->value > current->next->value)
			order++;
		current = current->next;
	}
	return (order);
}

void	resolveinline(t_stack *stack)
{
	int	way;

	way = 1;
	while (stackorder(stack) > 0)
	{
		if (stack->list->value > stack->list->next->value &&
			stack->list->value != stack->start->value)
			swapstack(stack);
		else
		{
			if (stack->start == stack->list)
				way = 0;
			if (way)
				revrotatestack(stack);
			else
				rotatestack(stack);
		}
		sleep(1);
	}
}

int		minvalue(t_stack *stack)
{
	int		min;
	t_dnode	*current;

	min = INT_MAX;
	current = stack->list;
	while (current)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
	}
	return (min);
}

t_dnode	*lastnode(t_stack *stack)
{
	t_dnode *current;

	current = stack->list;
	while (current->next)
	{
		current = current->next;
	}
	return (current);
}

int		maxvalue(t_stack *stack)
{
	int		max;
	t_dnode	*current;

	max = INT_MIN;
	current = stack->list;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	return (max);
}

int		badvalue(t_stack *stack)
{
	t_dnode *current;

	current = lastnode(stack);
	while (current)
	{
		if (current->prev && current->next)
		{
			if (current->prev->value > current->value &&
				current->value < current->next->value)
				return (current->value);
			if (current->prev->value < current->value &&
				current->value > current->next->value)
				return (current->value);
		}
		current = current->prev;
	}
	return (maxvalue(stack) + 1);
}
