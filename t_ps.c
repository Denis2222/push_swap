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

void	sa(t_ps *this)
{
	swapstack(this->stacka);
	ft_printf("sa ");
}

void	sb(t_ps *this)
{
	ft_printf("sa ");
	swapstack(this->stackb);
}

void	ss(t_ps *this)
{
	ft_printf("ss ");
	swapstack(this->stacka);
	swapstack(this->stackb);
}

void	pa(t_ps *this)
{
	ft_printf("pa ");
	pushstack(this->stacka, this->stackb);
}

void	pb(t_ps *this)
{
	ft_printf("pb ");
	pushstack(this->stackb, this->stacka);
}

void	ra(t_ps *this)
{
	ft_printf("ra ");
	rotatestack(this->stacka);
}

void	rb(t_ps *this)
{
	ft_printf("rb ");
	rotatestack(this->stackb);
}

void	rr(t_ps *this)
{
	ft_printf("rr ");
	rotatestack(this->stacka);
	rotatestack(this->stackb);
}

void	rra(t_ps *this)
{
	ft_printf("rra ");
	revrotatestack(this->stacka);
}

void	rrb(t_ps *this)
{
	ft_printf("rrb ");
	revrotatestack(this->stackb);
}

void	rrr(t_ps *this)
{
	ft_printf("rrr ");
	revrotatestack(this->stacka);
	revrotatestack(this->stackb);
}

