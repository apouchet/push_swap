/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:20:12 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/06 19:20:14 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_swap(t_val *val, int min, int max, char c)
{
	if (c == 'a')
	{
		while (ft_here_nb(val->a, min, max, val->la) == 1)
		{
			if ((val->a[0] > min && val->a[0] <= max) || val->a[0] == val->min)
				pb(val);
			else
				ra(val);
		}
	}
	if (c == 'b')
	{
		while (ft_here_nb(val->b, min, max, val->lb))
		{
			if (val->b[0] > min && val->b[0] <= max)
				pa(val);
			else
				rb(val);
		}
	}
}

void	ft_tri_plat(t_val *v)
{
	int	type;

	type = 0;
	while (!(v->a[0] < v->a[1] && v->a[1] < v->a[2] && v->a[0] < v->a[2]))
	{
		if (v->a[0] < v->a[1] && v->a[1] > v->a[2] && v->a[0] < v->a[2])
			type = 2;
		else if (v->a[0] > v->a[1] && v->a[1] < v->a[2] && v->a[0] < v->a[2])
			type = 3;
		else if (v->a[0] < v->a[1] && v->a[1] > v->a[2] && v->a[0] > v->a[2])
			type = 2;
		else if (v->a[0] > v->a[1] && v->a[1] < v->a[2] && v->a[0] > v->a[2])
			type = 3;
		else if (v->a[0] > v->a[1] && v->a[1] > v->a[2] && v->a[0] > v->a[2])
			type = 3;
		if (type == 2)
		{
			ra(v);
			sa(v);
			rra(v);
		}
		else if (type == 3)
			sa(v);
	}
}
