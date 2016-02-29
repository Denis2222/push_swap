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
			i++;
		}
	
		while (stacklen(ps->stacka) > 1)
		{
			algoboeuf(ps);
		}
		while (stacklen(ps->stackb) > 0)
		{
			pa(ps);
		}
		viewps(ps);
	}
	return (0);
}
