/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_timer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:28:47 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 08:06:46 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	so_long_timer(t_vars *vars)
{
	vars->frame++;
	if ((vars->frame % FPS) == 0)
	{
		ft_print_utime("update 1\n");
		so_long_layer_update(vars);
	}
	if ((vars->frame % FPS_1) == 0)
	{
		ft_print_utime("update 2\n");
		if (BONUS)
			so_long_layer_update_bonus(vars);
	}
	return (True);
}
