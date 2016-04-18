/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_psa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 00:09:26 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 06:51:29 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_psa	*newpsa(Action action)
{
	t_psa	*this;

	this = (t_psa*)malloc(sizeof(t_psa));
	this->type = action;
	this->next = NULL;
	return (this);
}
