/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_update_bonus_sub.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 13:08:52 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	villan_move(t_vars *vars)
{
	int			i;
	int			d;
	t_texture	*tex;

	(void)tex;
	i = 0;
	while (vars->size_map > i)
	{
		if (vars->texture[i].type == 'W')
		{
			d = ft_random(4);
		}
		i++;
	}
}
