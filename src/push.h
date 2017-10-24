/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 16:05:03 by apouchet          #+#    #+#             */
/*   Updated: 2017/04/27 16:05:04 by apouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct	s_val
{
	int			*a;
	int			*b;
	int			la;
	int			lb;
	int			min;
	int			max;
	int			maxi;
	int			coup;
	int			*ordre;
	int			check;
}				t_val;

void			sa(t_val *val);

void			sb(t_val *val);

void			ss(t_val *val);

void			rra(t_val *val);

void			rrb(t_val *val);

void			rrr(t_val *val);

void			rr(t_val *val);

void			ra(t_val *val);

void			rb(t_val *val);

void			pa(t_val *val);

void			pb(t_val *val);

void			decoupe(t_val *val);

void			ft_swap(t_val *val, int	min, int max, char c);

void			ft_double(t_val *val, int mode);

void			ft_triple(t_val *val);

int				ft_here_nb(int *tab, int min, int max, int len);

long			ft_atoi(char *str);

int				verif_a(t_val *val);

void			ft_verif_nb(t_val *val);

void			ft_verif_str(char *tab, t_val *val, int mode);

void			ft_start(t_val *val, int mode);

void			ft_exit(t_val *val, int mode);

void			ft_tri_plat(t_val *val);

char			*ft_strstr(const char *big, const char *little);

void			ft_bzero(void *s, size_t n);

void			*ft_memalloc(size_t size);

size_t			ft_strlen(const char *s);

char			**ft_strsplit(const char *s, char c);

void			ft_push_swap(t_val *val);

void			ft_mini_push(t_val *v);

#endif
