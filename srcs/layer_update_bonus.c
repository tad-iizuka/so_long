/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:00:39 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 12:55:57 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	*get_image_w(t_vars *vars, int i)
{
	void	*img;

	img = NULL;
	if (vars->texture[i].direction == DIR_W)
		img = vars->img_ww[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_S)
		img = vars->img_ws[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_A)
		img = vars->img_wa[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_D)
		img = vars->img_wd[vars->texture[i].frame];
	return (img);
}

static void	update_wizard_delay_timer(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->size_map > i)
	{
		if (vars->texture[i].type == TYPE_W)
		{
			vars->texture[i].animation = True;
			vars->texture[i].update = True;
		}
		i++;
	}
}

void	overlay_message_update(t_vars *vars)
{
	if (!BONUS)
		return ;
	if (vars->complete == FINISH_SUCCESS)
		display_str(vars, "GOALa");
	else if (vars->complete == FINISH_FAIL)
		display_str(vars, "FAILa");
}

void	layer_update_bonus(t_vars *vars)
{
	if (!BONUS)
		return ;
	wizard_move(vars);
	update_wizard_delay_timer(vars);
}
