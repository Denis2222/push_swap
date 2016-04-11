#include "push_swap.h"

int countformovetofirst(t_stack *stack, int n)
{
    t_dnode *node;
    t_dnode *nodelast;

    int     pos;
    int     i;
    int     len;
    node = stack->list;
    pos = 1;
    i = 1;

    while (node)
    {
      if (node->value == n)
      {
          pos = i;
      }
      i++;
      nodelast = node;
      node = node->next;
    }

    len = stacklen(stack);
    if (pos <= ((len+1)/2))
    {
          i = 0;
          node = stack->list;
          while (node)
          {
            if (node->value == n)
            {
                return (i);
            }
            i++;
            node = node->next;
          }
    }
    else
    {
      i = 1;
      node = nodelast;
      while (node)
      {
        if (node->value == n)
        {
          return (i  * -1);
        }
        i++;
        node = node->prev;
      }
    }
}

int countforpos(t_stack *stack, int n){
  int     max;
  int     min;
  t_dnode *node;
  int     nextval;

  nextval = -1;
  node = stack->list;
  max = maxvalue(stack);
  min = minvalue(stack);
  if (n > max || n < min)
  {
      return countformovetofirst(stack, max);
  }
  else
  {
    nextval = min;
    while (node)
    {
      if (node->value < n && node->value > nextval)
      {
        nextval = node->value;
      }
      node = node->next;
    }
    return countformovetofirst(stack, nextval);
  }
}

void findbestpb(t_ps *ps) {
  t_dnode *ca;
  int movea;
  int moveb;
  int total;
  int init;
  int tma;
  int tmb;
  int tem;

  int counter;


  //counter = 0;
  init = 0;
  movea = 0;
  movea = 0;
  total = 0;
  tma = 0;
  tmb = 0;
  tem = 0;
  ca = ps->stacka->list;
  while (ca)
  {
/*    if (counter < 5)
    {*/
      tma = countformovetofirst(ps->stacka, ca->value);
      tmb = countforpos(ps->stackb, ca->value);
      tem = 1 + ft_abs(tma) + ft_abs(tmb);
      //ft_printf("for %d to b cout=a(%d)+b(%d)    %d\n", ca->value, tma, tmb, tem);
      if (init == 0 || tem < total)
      {
        init = 1;
        movea = tma;
        moveb = tmb;
        total = tem;
      }
      //counter++;
    //}
    if (!ca->next)
      break;
    ca = ca->next;
  }
/*  counter = 0;
  while (ca)
  {
    if (counter < 5)
    {
      tma = countformovetofirst(ps->stacka, ca->value);
      tmb = countforpos(ps->stackb, ca->value);
      tem = 1 + ft_abs(tma) + ft_abs(tmb);
      //ft_printf("for %d to b cout=a(%d)+b(%d)    %d\n", ca->value, tma, tmb, tem);
      if (init == 0 || tem < total)
      {
        init = 1;
        movea = tma;
        moveb = tmb;
        total = tem;
      }
      counter++;
    }
    ca = ca->prev;
  }*/

  //ft_printf("==========================================\nbest : a: %d b: %d   total %d \n", movea, moveb, total);
  while (movea || moveb)
  {

    if (movea > 0 && moveb > 0)
    {
      //ft_printf("-------------------------------------------------\n");
      rr(ps);
      movea--;
      moveb--;
    }

    if (movea < 0 && moveb < 0)
    {
      //ft_printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
      rrr(ps);
      movea++;
      moveb++;
    }

    if (movea > 0)
    {
      ra(ps);
      movea--;
    }

    else if(movea < 0)
    {
      rra(ps);
      movea++;
    }
    if (moveb > 0)
    {
      rb(ps);
      moveb--;
    }
    else if(moveb < 0)
    {
      rrb(ps);
      moveb++;
    }
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
  {
    pa(ps);
  }
}
