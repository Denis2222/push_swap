/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:56:05 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 07:54:31 by dmoureu-         ###   ########.fr       */
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

void	viewstack(t_stack *this)
{
	t_dnode	*current;

	current = this->list;
	while (current)
	{
		ft_printf(" %d {green} prev: %d next: %d {eoc}\n",
		current->value, gvn(current->prev), gvn(current->next));
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
