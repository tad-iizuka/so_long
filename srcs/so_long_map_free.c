/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:48:10 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/15 14:33:29 by tiizuka          ###   ########.fr       */
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
			free(img->image);
			free(img);
		}
		i++;
	}
}

void	image_free_one(void **p)
{
	t_img	*img;

	img = p[0];
	free(img->image);
	free(img);
}

void	image_free(t_vars *vars)
{
	image_free_one(vars->img0);
	image_free_one(vars->img1);
	image_free_one(vars->imgE);
	image_free_sub(vars->imgC, get_frame_max(TYPE_C));
	image_free_sub(vars->imgPW, get_frame_max(TYPE_P));
	image_free_sub(vars->imgPS, get_frame_max(TYPE_P));
	image_free_sub(vars->imgPA, get_frame_max(TYPE_P));
	image_free_sub(vars->imgPD, get_frame_max(TYPE_P));
	if (BONUS)
	{
		image_free_sub(vars->imgALPHA, NUM_ALPHA);
		image_free_sub(vars->imgNUM, NUM_NUM);
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
