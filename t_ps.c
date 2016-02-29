#include "push_swap.h"

t_ps *newps(void)
{
	t_ps	*this;

	this = (t_ps*)malloc(sizeof(t_ps));
	this->stacka = NULL;
	this->stackb = NULL;
	return (this);
}

void	viewps(t_ps *this)
{
	ft_printf("\npile a:");
	viewpile(this->stacka);
	ft_printf("\npile b:");
	viewpile(this->stackb);
}
