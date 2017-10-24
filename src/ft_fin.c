/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:19:17 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/06 19:19:21 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		verif_a(t_val *val)
{
	int i;

	i = 0;
	while (i < val->la - 1)
	{
		if (val->a[i] > val->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}

void	ft_exit(t_val *val, int mode)
{
	if (mode != 2 && mode != 3)
	{
		free(val->a);
		free(val->b);
		free(val->ordre);
	}
	if (mode == 1 || mode == 3)
		write(2, "Error\n", 6);
	exit(0);
}
