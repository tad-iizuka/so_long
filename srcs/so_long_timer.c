/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_timer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:28:47 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 13:09:20 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	so_long_timer(t_vars *vars)
{
	vars->frame++;
	if ((vars->frame % FPS) == 0)
	{
		so_long_layer_update(vars);
		if (BONUS)
			so_long_layer_update_bonus(vars);
	}
	return (True);
}
