/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:20:53 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/06 19:20:54 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_ordre(t_val *val)
{
	int i;
	int j;

	i = 0;
	j = 0;
	val->ordre[j++] = val->min;
	while (j < val->la)
	{
		val->ordre[j] = val->maxi;
		while (i < val->la)
		{
			if (val->ordre[j] > val->a[i] && val->a[i] > val->ordre[j - 1])
				val->ordre[j] = val->a[i];
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_max(t_val *val)
{
	int	i;

	i = 0;
	val->max = val->a[0];
	val->min = val->a[0];
	while (i < val->la)
	{
		if (val->max < val->a[i])
			val->max = val->a[i];
		if (val->min > val->a[i])
			val->min = val->a[i];
		i++;
	}
	while ((val->a[i - 1] == val->min || val->a[i - 2] == val->min))
		rra(val);
	while ((val->a[i - 3] == val->min || val->a[i - 4] == val->min)
		&& val->la < 6 && val->a[0] != val->min)
		ra(val);
	val->maxi = val->max;
	ft_ordre(val);
	decoupe(val);
}

int		ft_pos(t_val *val, int nb)
{
	int i;

	i = 0;
	while (val->b[i] != nb && i < val->lb)
		i++;
	if (i >= val->lb - 1 && val->b[i] != nb)
		return (-1);
	if (i > val->lb / 2)
		return (1);
	return (0);
}

void	ft_push_swap(t_val *val)
{
	int pos;
	int i;

	i = val->la - 1;
	if (verif_a(val) == 0)
		ft_exit(val, 0);
	ft_max(val);
	while (i >= 0)
	{
		pos = ft_pos(val, val->ordre[i]);
		while (val->b[0] != val->ordre[i])
		{
			if (pos)
				rrb(val);
			else
				rb(val);
			if (i > 2 && val->b[0] == val->ordre[i - 1])
				pa(val);
		}
		pa(val);
		if (val->a[0] > val->a[1])
			sa(val);
		if (ft_pos(val, val->ordre[--i]) == -1)
			i--;
	}
}

void	ft_mini_push(t_val *v)
{
	int	type;

	type = 0;
	while (v->la == 3 && !(v->a[0] < v->a[1] &&
		v->a[1] < v->a[2] && v->a[0] < v->a[2]))
	{
		if (v->a[0] < v->a[1] && v->a[1] > v->a[2] && v->a[0] < v->a[2])
			type = 5;
		else if (v->a[0] > v->a[1] && v->a[1] < v->a[2] && v->a[0] < v->a[2])
			type = 3;
		else if (v->a[0] < v->a[1] && v->a[1] > v->a[2] && v->a[0] > v->a[2])
			type = 4;
		else if (v->a[0] > v->a[1] && v->a[1] < v->a[2] && v->a[0] > v->a[2])
			type = 5;
		else if (v->a[0] > v->a[1] && v->a[1] > v->a[2] && v->a[0] > v->a[2])
			type = 3;
		if (type == 3)
			sa(v);
		else if (type == 4)
			rra(v);
		else if (type == 5)
			ra(v);
	}
	if (v->la == 2 && v->a[0] > v->a[1])
		sa(v);
}
