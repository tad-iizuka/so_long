/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:28:47 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 11:59:29 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	loop_hook(t_vars *vars)
{
	vars->frame++;
	if ((vars->frame % FPS_100) == 0 && !vars->complete)
		layer_update(vars);
	if ((vars->frame % FPS_200) == 0 && vars->complete)
		layer_update(vars);
	if ((vars->frame % FPS_400) == 0)
		overlay_message_update(vars);
	if ((vars->frame % FPS_1000) == 0)
		layer_update_bonus(vars);
	return (True);
}
