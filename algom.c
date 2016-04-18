/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newalgom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 08:25:19 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 08:27:08 by dmoureu-         ###   ########.fr       */
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
	t_dnode   *ca;
	t_move    *m;

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
			break;
		ca = ca->next;
	}
	while (m->movea || m->moveb)
	{
		moovy(ps, m);
		movy(ps, m);
	}
	pb(ps);
}

void algom(t_ps *ps) {
	int mb;

	pb(ps);
	while (stacklen(ps->stacka) > 0)
	{
		findbestpb(ps);
	}
	mb = countformovetofirst(ps->stackb, maxvalue(ps->stackb));
	while(mb)
	{
		if (mb > 0)
		{
			rb(ps);
			mb--;
		}
		else if(mb < 0)
		{
			rrb(ps);
			mb++;
		}
	}
	while (stacklen(ps->stackb) > 0)
		pa(ps);
}
