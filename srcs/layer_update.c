/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 12:56:41 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static void	*get_image_p(t_vars *vars, int i)
{
	void	*img;

	img = NULL;
	if (vars->texture[i].direction == DIR_W)
		img = vars->img_pw[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_S)
		img = vars->img_ps[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_A)
		img = vars->img_pa[vars->texture[i].frame];
	else if (vars->texture[i].direction == DIR_D)
		img = vars->img_pd[vars->texture[i].frame];
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
		img = vars->img_c[vars->texture[i].frame];
	else if (type == TYPE_E)
		img = vars->img_e[vars->texture[i].frame];
	else if (type == TYPE_P)
		img = get_image_p(vars, i);
	else if (type == TYPE_W)
		img = get_image_w(vars, i);
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
			if (vars->complete)
				vars->texture[i].animation = False;
		}
	}
}

void	type_display(t_vars *vars, char type)
{
	int		i;
	t_img	*img;

	i = 0;
	while (vars->size_map > i)
	{
		if (vars->texture[i].type == type)
		{
			vars->texture[i].update = False;
			img = get_image(vars, type, i);
			mlx_put_image_to_window(vars->mlx, \
				vars->mlx_win, img, \
				i % vars->w * PIXEL_H, \
				i / vars->w * PIXEL_W);
			update_animation(vars, type, i);
			vars->texture[i].check = False;
		}
		i++;
	}
}

void	layer_update(t_vars *vars)
{
	char	*p;

	type_display(vars, '1');
	type_display(vars, '0');
	type_display(vars, 'C');
	type_display(vars, 'E');
	type_display(vars, 'P');
	if (BONUS)
	{
		type_display(vars, 'W');
		p = ft_itoa(vars->step);
		if (p)
		{
			display_score(vars, p);
			free(p);
		}
	}
}
