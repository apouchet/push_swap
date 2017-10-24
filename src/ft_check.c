/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 15:23:45 by apouchet          #+#    #+#             */
/*   Updated: 2017/06/07 15:23:47 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int		ft_check_r(t_val *val, char *l)
{
	if (l[0] == 'r' && l[1] == 'r' && l[2] == 'a' && l[3] == '\0')
		rra(val);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'b' && l[3] == '\0')
		rrb(val);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == 'r' && l[3] == '\0')
		rrr(val);
	else if (l[0] == 'r' && l[1] == 'a' && l[2] == '\0')
		ra(val);
	else if (l[0] == 'r' && l[1] == 'b' && l[2] == '\0')
		rb(val);
	else if (l[0] == 'r' && l[1] == 'r' && l[2] == '\0')
		rr(val);
	else if (l[0] == 's' && l[1] == 'a' && l[2] == '\0')
		sa(val);
	else if (l[0] == 's' && l[1] == 'b' && l[2] == '\0')
		sb(val);
	else if (l[0] == 's' && l[1] == 's' && l[2] == '\0')
		ss(val);
	else if (l[0] == 'p' && l[1] == 'a' && l[2] == '\0')
		pa(val);
	else if (l[0] == 'p' && l[1] == 'b' && l[2] == '\0')
		pb(val);
	else
		return (-1);
	return (2);
}

void	ft_check(t_val *val)
{
	int		get;
	char	*line;

	get = 2;
	while (get > 0)
	{
		get = get_next_line(0, &line);
		if (line[0] == 'r' || line[0] == 'p' || line[0] == 's')
			get = ft_check_r(val, line);
		else if (line[0] != '\0')
		{
			free(line);
			get = -1;
			break ;
		}
		free(line);
	}
	if (verif_a(val) == 0 && val->lb == 0 && get != -1)
		write(1, "OK\n", 3);
	else if (get != -1)
		write(1, "KO\n", 3);
	else if (get == -1)
		write(2, "Error\n", 6);
}

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
	if (argc == 1)
		return (0);
	tab = choix_main(&val, tab, argc, argv[1]);
	ft_start(&val, 2);
	while (argc <= 2 && i < val.la)
		i = tri_main(&val, i, tab[i], argc);
	while (argc > 2 && i < val.la)
		i = tri_main(&val, i, argv[i + 1], argc);
	ft_verif_nb(&val);
	ft_check(&val);
	ft_exit(&val, 0);
}
