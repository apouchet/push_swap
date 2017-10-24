/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:29:40 by apouchet          #+#    #+#             */
/*   Updated: 2017/04/27 16:29:42 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rra(t_val *val)
{
	int tmp;
	int	i;

	if (val->la <= 1)
		return ;
	i = val->la - 1;
	tmp = val->a[i];
	while (i > 0)
	{
		val->a[i] = val->a[i - 1];
		i--;
	}
	val->a[0] = tmp;
	if (val->check == 0)
		write(1, "rra\n", 4);
	val->coup++;
}

void	rrb(t_val *val)
{
	int tmp;
	int	i;

	if (val->lb <= 1)
		return ;
	i = val->lb - 1;
	tmp = val->b[i];
	while (i > 0)
	{
		val->b[i] = val->b[i - 1];
		i--;
	}
	val->b[0] = tmp;
	if (val->check == 0)
		write(1, "rrb\n", 4);
	val->coup++;
}

void	rrr(t_val *val)
{
	int tmp;
	int	i;

	if (val->la <= 1 || val->lb <= 1)
		return ;
	i = val->la - 1;
	tmp = val->a[i];
	while (i > 0)
	{
		val->a[i] = val->a[i - 1];
		i--;
	}
	val->a[0] = tmp;
	i = val->lb - 1;
	tmp = val->b[i];
	while (i > 0)
	{
		val->b[i] = val->b[i - 1];
		i--;
	}
	val->b[0] = tmp;
	if (val->check == 0)
		write(1, "rrr\n", 4);
	val->coup++;
}
