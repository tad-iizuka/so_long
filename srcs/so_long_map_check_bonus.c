/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:07:47 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/16 14:57:37 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	map_calc_wizard(t_vars *vars)
{
	int	w;

	w = vars->num_space - vars->num_c;
	vars->num_space = w;
	if (w < 5)
		vars->num_wizard = 1;
	else
		vars->num_wizard = ((w - 5) / 20) + 1;
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
		x = ft_random(vars->num_space - 1);
		m = vars->mtx;
		z = 0;
		while (z++ < vars->size_map)
		{
			if (*m == '0')
			{
				if (!x--)
				{
					*m = 'C';
					break ;
				}
			}
			m++;
		}
		i++;
	}
}
