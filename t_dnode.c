/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_dnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:56:01 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 06:48:06 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dnode	*newdnode(int value)
{
	t_dnode	*this;

	this = (t_dnode*)malloc(sizeof(t_dnode));
	this->value = value;
	this->next = NULL;
	this->prev = NULL;
	return (this);
}

int		gvn(t_dnode *node)
{
	if (node)
		return (node->value);
	else
		return (0);
}
