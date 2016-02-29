#include "push_swap.h"

t_stack	*newstack(void)
{
	t_stack	*this;

	this = (t_stack*)malloc(sizeof(t_stack));
	this->list = NULL;
	return (this);
}

void	addstack(t_stack *this, int value)
{
	t_dnode	*new;

	new = newdnode(value);
	if (!this->list)
		this->list = new;
	else
	{
		new->next = this->list;
		this->list->prev = new;
		this->list = new;
	}
}

void	addstackback(t_stack *this, int value)
{
	t_dnode	*new;
	t_dnode	*current;

	new = newdnode(value);
	if (!this->list)
		this->list = new;
	else
	{
		current = this->list;
		while (current->next)
			current = current->next;
		new->prev = current;
		current->next = new;
	}
}


void	viewstack(t_stack *this)
{
	t_dnode	*current;

	current = this->list;
	while (current)
	{
		ft_printf("%d {green}prev:%d next%d {eoc}\n", current->value, gvn(current->prev), gvn(current->next));
		current = current->next;
	}
}

void	viewpile(t_stack *this)
{
	t_dnode	*current;

	current = this->list;
	if (stacklen(this) == 0)
		return ;
	while (current->next)
		current = current->next;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->prev;
	}
}

int	stacklen(t_stack *this)
{
	int		length;
	t_dnode	*current;

	length = 0;
	current = this->list;
	while(current)
	{
		length++;
		current = current->next;
	}
	return (length);
}

void	swapstack(t_stack *this)
{
	int	tmp;

	if (stacklen(this) > 1)
	{
		tmp = this->list->value;
		this->list->value = this->list->next->value;
		this->list->next->value = tmp;
	}
	ft_printf("\nswap");
}

void	pushstack(t_stack *dst, t_stack *src)
{
	int		tmp;
	t_dnode	*left;
	if (stacklen(src) > 0)
	{
		left = src->list;
		tmp = left->value;
		if (src->list->next)
		{
		src->list = left->next;
		src->list->prev = NULL;
		}
		else
		{
			free(src->list);
			src->list = NULL;
		}
		addstack(dst, tmp);
	}
	ft_printf("\npush");
}

void	rotatestack(t_stack *this)
{
	t_dnode	*first;
	t_dnode	*last;

	if (stacklen(this) > 1)
	{
		first = this->list;
		last = this->list;
		while (last->next)
			last = last->next;
		last->next = first;
		first->prev = last;
		this->list = first->next;
		first->next = NULL;
		this->list->prev = NULL;
	}
}

void	revrotatestack(t_stack *this)
{
	t_dnode	*first;
	t_dnode	*last;

	if (stacklen(this) > 1)
	{
		first = this->list;
		last = this->list;
		while (last->next)
			last = last->next;

		last->prev->next = NULL;
		first->prev = last;
		last->prev = NULL;
		this->list = last;
		this->list->next = first;
	}
}
