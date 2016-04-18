/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 07:53:43 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 07:54:12 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacklen(t_stack *this)
{
	int		length;
	t_dnode	*current;

	length = 0;
	current = this->list;
	while (current)
	{
		length++;
		current = current->next;
	}
	return (length);
}

void	swapstack(t_stack *this)
{
	int	tmp;

	if (stacklen(this) > 1)
	{
		tmp = this->list->value;
		this->list->value = this->list->next->value;
		this->list->next->value = tmp;
	}
}

void	pushstack(t_stack *dst, t_stack *src)
{
	int		tmp;
	t_dnode	*left;

	if (stacklen(src) > 0)
	{
		left = src->list;
		tmp = left->value;
		if (src->list->next)
		{
			src->list = left->next;
			src->list->prev = NULL;
		}
		else
		{
			free(src->list);
			src->list = NULL;
		}
		addstack(dst, tmp);
	}
}

void	rotatestack(t_stack *this)
{
	t_dnode	*first;
	t_dnode	*last;

	if (stacklen(this) > 1)
	{
		first = this->list;
		last = this->list;
		while (last->next)
			last = last->next;
		last->next = first;
		first->prev = last;
		this->list = first->next;
		first->next = NULL;
		this->list->prev = NULL;
	}
}

void	revrotatestack(t_stack *this)
{
	t_dnode	*first;
	t_dnode	*last;

	if (stacklen(this) > 1)
	{
		first = this->list;
		last = this->list;
		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		first->prev = last;
		last->prev = NULL;
		this->list = last;
		this->list->next = first;
	}
}
