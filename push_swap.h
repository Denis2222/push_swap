/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:36:32 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/03/23 22:43:28 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf.h"

typedef enum Action Action;
enum Action
{
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	PA,
	PB
};

typedef struct	s_dnode
{
	int				value;
	struct s_dnode	*next;
	struct s_dnode	*prev;
}					t_dnode;

typedef struct		s_stack
{
	t_dnode			*start;
	t_dnode			*list;
}					t_stack;

typedef	struct		s_psa
{
	Action			type;
	struct s_psa	*next;
}					t_psa;

typedef struct		s_push_swap
{
	t_stack			*stacka;
	t_stack			*stackb;
	t_stack			*stacko;
	t_psa			*action;

	int				verbose;
	int				algo;
	int				graphique;
}					t_ps;

t_ps				*newps(void);
t_psa				*newpsa(Action action);
void				viewaction(t_ps *ps);
t_stack				*newstack(void);
t_dnode				*newdnode(int value);
int					checkinput(char *av, t_stack *stack);
int					checkparam(t_ps *ps, int ac, char **av);
void				addstack(t_stack *this, int value);
void				addstackback(t_stack *this, int value);
void				addstackopti(t_stack *this, int value);
void				viewstack(t_stack *this);
void				viewpile(t_stack *this);
int					stacklen(t_stack *this);
void				swapstack(t_stack *this);
void				pushstack(t_stack *dst, t_stack *src);
void				rotatestack(t_stack *this);
void				revrotatestack(t_stack *this);
int					gvn(t_dnode *node);
void				viewps(t_ps *this);

int		minvalue(t_stack *stack);
int		maxvalue(t_stack *stack);
int		badvalue(t_stack *stack);
void	pushvaluetob(t_ps *ps, int val);

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

void	algonaif(t_ps *ps);
void	algonaifresolve(t_ps *ps);
void	algobubble(t_ps *ps);
void	algoradix(t_ps *ps);
void	algoinsert(t_ps *ps);
int		getbitval(int n, int bit);
void	algot(t_ps *ps);

int		stackorder(t_stack *stack);
void	resolveinline(t_stack *stack);
void	analysediff(t_stack *a, t_stack *b);

void	checkswitchrotate(t_stack *stack, char c);
void	checkswap(t_stack *stack, char c);
void	checkrotate(t_stack *stack, char c);
void	checkbasic(t_stack *stack, char c);

#endif