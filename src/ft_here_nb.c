/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_nb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 19:19:29 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/06 19:19:32 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_here_nb(int *tab, int min, int max, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] > min && tab[i] <= max)
			return (1);
		i++;
	}
	return (0);
}
