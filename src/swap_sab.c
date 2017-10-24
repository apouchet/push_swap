/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:29:34 by apouchet          #+#    #+#             */
/*   Updated: 2017/04/27 16:29:36 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sa(t_val *val)
{
	int	tmp;

	if (val->la <= 1)
		return ;
	tmp = val->a[0];
	val->a[0] = val->a[1];
	val->a[1] = tmp;
	if (val->check == 0)
		write(1, "sa\n", 3);
	val->coup++;
}

void	sb(t_val *val)
{
	int	tmp;

	if (val->lb <= 1)
		return ;
	tmp = val->b[0];
	val->b[0] = val->b[1];
	val->b[1] = tmp;
	if (val->check == 0)
		write(1, "sb\n", 3);
	val->coup++;
}

void	ss(t_val *val)
{
	int	tmp;

	if (val->lb <= 1 || val->la <= 1)
		return ;
	tmp = val->a[0];
	val->a[0] = val->a[1];
	val->a[1] = tmp;
	tmp = val->b[0];
	val->b[0] = val->b[1];
	val->b[1] = tmp;
	if (val->check == 0)
		write(1, "ss\n", 3);
	val->coup++;
}
