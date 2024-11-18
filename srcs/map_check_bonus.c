/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:53:39 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 14:14:31 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	map_calc_wizard(t_vars *vars)
{
	int	w;

	w = vars->num_space - vars->num_c - 1;
	vars->num_space = w;
	if (w != 0 && w < 10)
		vars->num_wizard = 1;
	else
		vars->num_wizard = ((w - 10) / 25) + 1;
}

void	map_create_wizard(t_vars *vars)
{
	int		i;
	int		x;
	char	*m;
	int		z;

	i = 0;
	while (i < vars->num_wizard)
	{
		x = ft_random(vars->num_space - vars->num_c - 1);
		m = vars->mtx;
		z = 0;
		while (z++ < vars->size_map)
		{
			if (*m == '0')
			{
				if (!x--)
				{
					*m = 'W';
					break ;
				}
			}
			m++;
		}
		i++;
	}
}
