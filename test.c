/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoureu- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 08:54:51 by dmoureu-          #+#    #+#             */
/*   Updated: 2016/04/18 09:03:33 by dmoureu-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps	**testarray(t_ps *psm, t_ps *psnaif, t_ps *psbubble, t_ps *psbubblerev)
{
	t_ps	**test;

	test = (t_ps**)malloc(sizeof(t_ps) * 10);
	if (!test)
		return (NULL);
	test[0] = psm;
	test[1] = psnaif;
	test[2] = psbubble;
	test[3] = psbubblerev;
	test[4] = NULL;
	return (test);
}
