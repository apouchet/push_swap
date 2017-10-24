/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:11:41 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/08 19:11:43 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		tri_main(t_val *val, int i, char *tab, int argc)
{
	long	tmp;

	if (argc <= 2)
		ft_verif_str(tab, val, 1);
	else
		ft_verif_str(tab, val, 2);
	tmp = ft_atoi(tab);
	if (tmp > 2147483647 || tmp < -2147483648)
		ft_exit(val, 1);
	val->a[i++] = (int)tmp;
	return (i);
}

char	**choix_main(t_val *val, char **tab, int argc, char *str)
{
	int i;

	i = 0;
	if (argc <= 2)
	{
		tab = ft_strsplit(str, ' ');
		while (tab[i] != NULL)
			i++;
		val->la = i;
	}
	else
		val->la = argc - 1;
	return (tab);
}

int		main(int argc, char **argv)
{
	int		i;
	char	**tab;
	t_val	val;

	tab = NULL;
	i = 0;
	if (argc <= 1)
		return (0);
	tab = choix_main(&val, tab, argc, argv[1]);
	ft_start(&val, 1);
	while (argc <= 2 && i < val.la)
		i = tri_main(&val, i, tab[i], argc);
	while (argc > 2 && i < val.la)
		i = tri_main(&val, i, argv[i + 1], argc);
	ft_verif_nb(&val);
	if (i <= 3)
		ft_mini_push(&val);
	else
		ft_push_swap(&val);
	ft_exit(&val, 0);
}
