#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf.h"

typedef struct	s_dnode
{
	int				value;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}					t_dnode;

typedef struct		s_stack
{
	t_dnode			*list;
}					t_stack;

typedef struct		s_push_swap
{
	t_stack			*stacka;
	t_stack			*stackb;
}					t_ps;

t_ps				*newps(void);
t_stack				*newstack(void);
t_dnode				*newdnode(int value);
void				addstack(t_stack *this, int value);
void				addstackback(t_stack *this, int value);
void				viewstack(t_stack *this);
void				viewpile(t_stack *this);
int					stacklen(t_stack *this);
void				swapstack(t_stack *this);
void				pushstack(t_stack *dst, t_stack *src);
void				rotatestack(t_stack *this);
void				revrotatestack(t_stack *this);
int					gvn(t_dnode *node);
void				viewps(t_ps *this);

void	sa(t_ps *this);
void	sb(t_ps *this);
void	ss(t_ps *this);

void	pa(t_ps *this);
void	pb(t_ps *this);

void	ra(t_ps *this);
void	rb(t_ps *this);
void	rr(t_ps *this);

void	rra(t_ps *this);
void	rrb(t_ps *this);
void	rrr(t_ps *this);

void	algoboeuf(t_ps *ps);

#endif
