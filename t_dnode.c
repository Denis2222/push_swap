#include "push_swap.h"

t_dnode	*newdnode(int value)
{
	t_dnode *this;

	this = (t_dnode*)malloc(sizeof(t_dnode));
	this->value = value;
	this->next = NULL;
	this->prev = NULL;
	return (this);
}


int	gvn(t_dnode *node)
{
	if (node)
		return (node->value);
	else
		return (0);
}
