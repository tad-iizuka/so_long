/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:55:49 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 13:17:20 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	image_free_sub(void **p, int size)
{
	int		i;
	t_img	*img;

	i = 0;
	while (i < size)
	{
		if (p[i])
		{
			img = p[i];
			if (img)
			{
				if (img->image)
					free(img->image);
				free(img);
			}
		}
		i++;
	}
}

void	image_free_one(void **p)
{
	t_img	*img;

	img = p[0];
	if (img)
	{
		if (img->image)
			free(img->image);
		free(img);
	}
}

void	image_free(t_vars *vars)
{
	image_free_one(vars->img0);
	image_free_one(vars->img1);
	image_free_one(vars->img_e);
	image_free_sub(vars->img_c, get_frame_max(TYPE_C));
	image_free_sub(vars->img_pw, get_frame_max(TYPE_P));
	image_free_sub(vars->img_ps, get_frame_max(TYPE_P));
	image_free_sub(vars->img_pa, get_frame_max(TYPE_P));
	image_free_sub(vars->img_pd, get_frame_max(TYPE_P));
	if (BONUS)
	{
		image_free_sub(vars->img_alpha, NUM_ALPHA);
		image_free_sub(vars->img_num, NUM_NUM);
		image_free_sub(vars->img_sym, NUM_SYM);
		image_free_sub(vars->img_ww, get_frame_max(TYPE_W));
		image_free_sub(vars->img_ws, get_frame_max(TYPE_W));
		image_free_sub(vars->img_wa, get_frame_max(TYPE_W));
		image_free_sub(vars->img_wd, get_frame_max(TYPE_W));
	}
}

void	map_free(t_vars *vars)
{
	int		i;

	i = 0;
	while (vars->num_map > i)
	{
		free(vars->map[i]->map);
		free(vars->map[i++]);
	}
	if (vars->map)
		free(vars->map);
	if (vars->mtx)
		free(vars->mtx);
	if (vars->texture)
		free(vars->texture);
	image_free(vars);
	vars->map = NULL;
	vars->num_map = 0;
	vars->mtx = NULL;
}
