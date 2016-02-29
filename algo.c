#include <limits.h>
#include "push_swap.h"

void	algoboeuf(t_ps *ps)
{
	int		maxa;
	int		pos;
	int		posmax;
	int		rotate;
	t_dnode	*c;

	maxa = INT_MAX;
	pos = 0;
	rotate = 0;
	posmax = 0;
	c = ps->stacka->list;
	while (c)
	{
		pos++;
		if (c->value < maxa)
		{
			posmax = pos;
			maxa = c->value;
		}
		c = c->next;
	}

	if (posmax > stacklen(ps->stacka) / 2)
	{
		rotate = (stacklen(ps->stacka) - posmax) + 1;
		while (rotate > 0)
		{
			rra(ps);
			rotate--;
		}
	}
	else
	{
		rotate = posmax - 1;
		while (rotate > 0)
		{
			ra(ps);
			rotate--;
		}
	}
	pb(ps);
}
