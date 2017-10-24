/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:20:03 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/06 19:20:05 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ft_verif_str(char *tab, t_val *val, int mode)
{
	int i;

	i = 0;
	while (tab[i] != '\0')
	{
		if (((tab[i] >= '0' && tab[i] <= '9') || (tab[i] == ' ' && mode == 1)
			|| (tab[i] == '-' && tab[i + 1] >= '0' && tab[i + 1] <= '9'))
			&& i < 13)
			i++;
		else
			ft_exit(val, 1);
	}
}

void	ft_verif_nb(t_val *val)
{
	int i;
	int	j;

	i = 0;
	while (i < val->la)
	{
		j = i + 1;
		while (j < val->la)
		{
			if (val->a[i] == val->a[j])
				ft_exit(val, 1);
			j++;
		}
		i++;
	}
}

void	ft_start(t_val *val, int mode)
{
	val->lb = 0;
	val->coup = 0;
	if (mode == 1)
		val->check = 0;
	else
		val->check = 1;
	if (!(val->ordre = (int*)malloc(sizeof(int) * (val->la + 2))))
		ft_exit(val, 2);
	if (!(val->a = (int*)malloc(sizeof(int) * (val->la + 2))))
		ft_exit(val, 2);
	if (!(val->b = (int*)malloc(sizeof(int) * (val->la + 2))))
		ft_exit(val, 2);
}
