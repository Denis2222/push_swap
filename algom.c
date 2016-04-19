/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algom.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <dmoureu-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 08:25:19 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/19 00:54:21 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	moovy(t_ps *ps, t_move *m)
{
	if (m->movea > 0 && m->moveb > 0)
	{
		rr(ps);
		(m->movea)--;
		(m->moveb)--;
	}
	if (m->movea < 0 && m->moveb < 0)
	{
		rrr(ps);
		(m->movea)++;
		(m->moveb)++;
	}
}

void	movy(t_ps *ps, t_move *m)
{
	if (m->movea > 0)
	{
		ra(ps);
		(m->movea)--;
	}
	else if (m->movea < 0)
	{
		rra(ps);
		(m->movea)++;
	}
	if (m->moveb > 0)
	{
		rb(ps);
		(m->moveb)--;
	}
	else if (m->moveb < 0)
	{
		rrb(ps);
		(m->moveb)++;
	}
}

void	findbestpb(t_ps *ps)
{
	t_dnode	*ca;
	t_move	*m;

	m = newmove();
	ca = ps->stacka->list;
	while (ca)
	{
		m->tma = countformovetofirst(ps->stacka, ca->value);
		m->tmb = countforpos(ps->stackb, ca->value);
		m->tem = 1 + ft_abs(m->tma) + ft_abs(m->tmb);
		if (m->init == 0 || m->tem < m->total)
			temptomove(m);
		if (!ca->next)
			break ;
		ca = ca->next;
	}
	while (m->movea || m->moveb)
	{
		moovy(ps, m);
		movy(ps, m);
	}
	free(m);
	pb(ps);
}

void	algom(t_ps *ps)
{
	int	mb;

	if (stacklen(ps->stacka) > 0 && stackorder(ps->stacka) != 0)
	{
		pb(ps);
		while (stacklen(ps->stacka) > 0)
			findbestpb(ps);
		mb = countformovetofirst(ps->stackb, maxvalue(ps->stackb));
		while (mb)
		{
			if (mb > 0)
			{
				rb(ps);
				mb--;
			}
			else if (mb < 0)
			{
				rrb(ps);
				mb++;
			}
		}
		while (stacklen(ps->stackb) > 0)
			pa(ps);
	}
}
