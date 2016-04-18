/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_move.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 08:09:33 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 08:31:51 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*newmove(void)
{
	t_move	*move;

	move = (t_move*)malloc(sizeof(t_move));
	move->init = 0;
	move->movea = 0;
	move->movea = 0;
	move->total = 0;
	move->tma = 0;
	move->tmb = 0;
	move->tem = 0;
	return (move);
}

void	temptomove(t_move *m)
{
	m->init = 1;
	m->movea = m->tma;
	m->moveb = m->tmb;
	m->total = m->tem;
}
