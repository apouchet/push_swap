/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:29:47 by apouchet          #+#    #+#             */
/*   Updated: 2017/04/27 16:29:48 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ra(t_val *val)
{
	int tmp;
	int	i;

	if (val->la <= 1)
		return ;
	i = 0;
	tmp = val->a[0];
	while (i < val->la - 1)
	{
		val->a[i] = val->a[i + 1];
		i++;
	}
	val->a[i] = tmp;
	if (val->check == 0)
		write(1, "ra\n", 3);
	val->coup++;
}

void	rb(t_val *val)
{
	int tmp;
	int	i;

	if (val->lb <= 1)
		return ;
	i = 0;
	tmp = val->b[0];
	while (i < val->lb - 1)
	{
		val->b[i] = val->b[i + 1];
		i++;
	}
	val->b[i] = tmp;
	if (val->check == 0)
		write(1, "rb\n", 3);
	val->coup++;
}

void	rr(t_val *val)
{
	int tmp;
	int	i;

	if (val->lb <= 1 || val->la <= 1)
		return ;
	i = 0;
	tmp = val->b[0];
	while (i < val->lb - 1)
	{
		val->b[i] = val->b[i + 1];
		i++;
	}
	val->b[i] = tmp;
	i = 0;
	tmp = val->a[0];
	while (i < val->la - 1)
	{
		val->a[i] = val->a[i + 1];
		i++;
	}
	val->a[i] = tmp;
	if (val->check == 0)
		write(1, "rr\n", 3);
	val->coup++;
}
