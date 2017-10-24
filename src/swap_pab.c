/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_pab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:33:48 by apouchet          #+#    #+#             */
/*   Updated: 2017/04/27 16:33:54 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	pa(t_val *val)
{
	int	i;
	int	tmp;

	tmp = val->b[0];
	if (val->lb == 0)
		return ;
	val->la++;
	i = val->la;
	while (i > 0)
	{
		val->a[i] = val->a[i - 1];
		i--;
	}
	val->a[0] = tmp;
	i = 0;
	while (i < val->lb - 1)
	{
		val->b[i] = val->b[i + 1];
		i++;
	}
	val->lb--;
	if (val->check == 0)
		write(1, "pa\n", 3);
	val->coup++;
}

void	pb(t_val *val)
{
	int	i;
	int	tmp;

	tmp = val->a[0];
	if (val->la == 0)
		return ;
	i = val->lb;
	val->lb++;
	while (i > 0)
	{
		val->b[i] = val->b[i - 1];
		i--;
	}
	val->b[0] = tmp;
	i = 0;
	while (i < val->la - 1)
	{
		val->a[i] = val->a[i + 1];
		i++;
	}
	val->la--;
	if (val->check == 0)
		write(1, "pb\n", 3);
	val->coup++;
}
