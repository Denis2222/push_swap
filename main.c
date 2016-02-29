#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ps	*ps;
	int		i;

	ps = newps();
	ps->stacka = newstack();
	ps->stackb = newstack();


	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			addstackback(ps->stacka, ft_atoi(av[i]));
			//ft_printf("push %d in stacka\n", ft_atoi(av[i]));
			i++;
		}

		viewps(ps);
		swapstack(ps->stacka);
		viewps(ps);
		pushstack(ps->stackb, ps->stacka);
		pushstack(ps->stackb, ps->stacka);
		pushstack(ps->stackb, ps->stacka);
		viewps(ps);
		rotatestack(ps->stacka);
		rotatestack(ps->stackb);
		viewps(ps);
		revrotatestack(ps->stacka);
		revrotatestack(ps->stackb);
		viewps(ps);
		swapstack(ps->stacka);
		viewps(ps);
		pushstack(ps->stacka, ps->stackb);
		pushstack(ps->stacka, ps->stackb);
		pushstack(ps->stacka, ps->stackb);
		viewps(ps);
	}

	return (0);
}
