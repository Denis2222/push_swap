/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:56:05 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/21 13:22:30 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(void)
{
	t_stack	*this;

	this = (t_stack*)malloc(sizeof(t_stack));
	this->list = NULL;
	this->start = NULL;
	return (this);
}

void	addstack(t_stack *this, int value)
{
	t_dnode	*new;

	new = newdnode(value);
	if (!this->list)
	{
		this->list = new;
		this->start = new;
	}
	else
	{
		new->next = this->list;
		this->list->prev = new;
		this->list = new;
		if (new->value > this->start->value)
			this->start = new;
	}
}

void	addstackback(t_stack *this, int value)
{
	t_dnode	*new;
	t_dnode	*current;

	new = newdnode(value);
	if (!this->list)
	{
		this->list = new;
		this->start = new;
	}
	else
	{
		if (new->value > this->start->value)
			this->start = new;
		current = this->list;
		while (current->next)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
}

void	addstackopti(t_stack *this, int value)
{
	t_dnode	*current;
	t_dnode	*prev;
	t_dnode	*next;
	t_dnode	*new;
	int		add;

	if (this->list)
		current = this->list;
	add = 0;
	if (!this->list || current->value > value)
	{
		addstack(this, value);
		add++;
	}
	else
	{
		while (current->next && !add && current->value < value)
			current = current->next;
		if (current->value > value && !add)
		{
			prev = current->prev;
			next = current;
			new = newdnode(value);
			prev->next = new;
			new->prev = prev;
			new->next = next;
			next->prev = new;
		}
		else
		{
			addstackback(this, value);
		}
	}
}

void	viewstack(t_stack *this)
{
	t_dnode	*current;

	current = this->list;
	while (current)
	{
		ft_printf(" %d {green} prev: %d next: %d {eoc}\n", current->value, gvn(current->prev), gvn(current->next));
		current = current->next;
	}
}

void	viewpile(t_stack *this)
{
	t_dnode	*current;

	current = this->list;
	if (stacklen(this) == 0)
		return ;
	while (current->next)
		current = current->next;
	while (current)
	{
		if (this->start && current->value == this->start->value)
			ft_printf("{red}%d {eoc}", current->value);
		else
			ft_printf("%d ", current->value);
		current = current->prev;
	}
}

int	stacklen(t_stack *this)
{
	int		length;
	t_dnode	*current;

	length = 0;
	current = this->list;
	while(current)
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

void	analysediff(t_stack *a, t_stack *b)
{
	t_dnode *na;
	t_dnode *nb;

	na = a->list;
	nb = b->list;
	while (na)
	{
		if (na->next->value != nb->value)
			ft_printf("%d not in place", na->value);
		na = na->next;
		nb = nb->next;
	}
}
