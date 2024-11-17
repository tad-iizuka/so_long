/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_update_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/15 14:08:23 by tiizuka          ###   ########.fr       */
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

void	display_score(t_vars *vars, char *str)
{
	int		i;
	int		z;
	t_img	*img;

	z = 4 - ft_strlen(str);
	i = 0;
	while (i < z)
	{
		img = get_image_num(vars, '0');
		mlx_put_image_to_window(vars->mlx, \
			vars->mlx_win, img, \
			((vars->w * PIXEL_W / 2) - (25 * 2)) + i * 25, 16);
		i++;
	}
	i = 0;
	while (str[i])
	{
		img = get_image_num(vars, str[i]);
		mlx_put_image_to_window(vars->mlx, \
			vars->mlx_win, img, \
			((vars->w * PIXEL_W / 2) - (25 * 2)) \
			+ (z + i) * 25, 16);
		i++;
	}
}

static void	display_str(t_vars *vars, char *str)
{
	int		i;
	t_img	*img;

	i = 0;
	while (str[i])
	{
		img = get_image_alpha(vars, str[i]);
		mlx_put_image_to_window(vars->mlx, \
			vars->mlx_win, img, \
			((vars->w * PIXEL_W / 2) - ((25 * ft_strlen(str)) / 2)) \
			+ (i * 25), \
			((vars->num_map * PIXEL_H / 2) - 16));
		i++;
	}
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

void	so_long_layer_update_bonus(t_vars *vars)
{
	if (vars->complete == FINISH_SUCCESS)
		display_str(vars, "GOALa");
	else if (vars->complete == FINISH_FAIL)
		display_str(vars, "FAILa");
	vars->wizard_update++;
	// if (vars->wizard_update < WIZARD_ANIMATION_DELAY)
	// 	type_display(vars, 'W');
	if (vars->wizard_update > WIZARD_ANIMATION_DELAY)
	{
		villan_move(vars);
	}
	if (vars->wizard_update == WIZARD_ANIMATION_DELAY)
		update_wizard_delay_timer(vars);
}
