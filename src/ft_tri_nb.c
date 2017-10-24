/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:19:53 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/06 19:19:55 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_double(t_val *val, int mode)
{
	if (mode == 1)
	{
		if (val->b[0] < val->b[1])
			sb(val);
		pa(val);
		pa(val);
	}
	else
	{
		if (val->a[0] > val->a[1])
			sa(val);
	}
}

void	ft_triple(t_val *val)
{
	ft_double(val, 2);
	if (!(val->b[0] < val->b[1] && val->b[0] < val->b[2]))
	{
		if (val->b[0] > val->b[1] && val->b[0] > val->b[2])
			pa(val);
		else if ((val->b[0] > val->b[1] && val->b[0] < val->b[2]) ||
			(val->b[0] < val->b[1] && val->b[0] > val->b[2]))
		{
			rb(val);
			if (val->b[0] < val->b[1])
				sb(val);
			pa(val);
			rrb(val);
		}
		ft_double(val, 1);
	}
	else if (val->b[0] < val->b[1] && val->b[0] < val->b[2])
	{
		rb(val);
		ft_double(val, 1);
		rrb(val);
		pa(val);
	}
}

void	decoupe(t_val *val)
{
	int nb;
	int p;

	nb = 34;
	if (val->la < 200)
		nb -= 7;
	p = 1;
	if (val->la < 6)
	{
		ft_swap(val, val->min - 1, val->ordre[2], 'a');
		ft_triple(val);
		ft_exit(val, 0);
	}
	if (val->la > nb)
		ft_swap(val, val->min - 1, val->ordre[nb], 'a');
	else
		ft_swap(val, val->min - 1, val->maxi, 'a');
	while (val->la != 0)
	{
		if (val->la > nb)
			ft_swap(val, val->ordre[nb * p], val->ordre[nb * (p + 1)], 'a');
		else
			ft_swap(val, val->ordre[nb * p], val->maxi, 'a');
		p++;
	}
}
