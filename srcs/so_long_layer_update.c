/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/13 12:31:24 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static void	*get_image_p(t_vars *vars, int i)
{
	void	*img;

	img = NULL;
	if (vars->texture[i].direction == DIR_W)
		img = vars->imgPW[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_S)
		img = vars->imgPS[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_A)
		img = vars->imgPA[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_D)
		img = vars->imgPD[vars->texture[i].frame];
	return (img);
}

static void	*get_image(t_vars *vars, char type, int i)
{
	void	*img;

	img = NULL;
	if (type == TYPE_0)
		img = vars->img0[vars->texture[i].frame];
	else if (type == TYPE_1)
		img = vars->img1[vars->texture[i].frame];
	else if (type == TYPE_C)
		img = vars->imgC[vars->texture[i].frame];
	else if (type == TYPE_E)
		img = vars->imgE[vars->texture[i].frame];
	else if (type == TYPE_P)
		img = get_image_p(vars, i);
	return (img);
}

static void	update_animation(t_vars *vars, char type, int i)
{
	if (type != '0')
	{
		if (vars->texture[i].animation)
		{
			vars->texture[i].frame++;
			if (vars->texture[i].frame == vars->texture[i].max_frame)
				vars->texture[i].frame = 0;
			vars->texture[i].update = True;
		}
	}
}

static void	type(t_vars *vars, char type)
{
	int		i;
	t_img	*img;

	i = 0;
	while (vars->size_map > i)
	{
		if (vars->texture[i].update && vars->texture[i].type == type)
		{
			vars->texture[i].update = False;
			img = get_image(vars, type, i);
			mlx_put_image_to_window(vars->mlx, \
				vars->mlx_win, img, \
				i % vars->w * PIXEL_H, \
				i / vars->w * PIXEL_W);
			update_animation(vars, type, i);
		}
		i++;
	}
}

void	so_long_layer_update(t_vars *vars)
{
	ft_print_utime("so_long_layer_update\n");
	type(vars, '1');
	type(vars, '0');
	type(vars, 'C');
	type(vars, 'E');
	type(vars, 'P');
}
