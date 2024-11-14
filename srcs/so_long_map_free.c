/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:48:10 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/14 14:22:38 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	image_free_sub(void **p, char type)
{
	int		i;
	t_img	*img;

	i = 0;
	i = 0;
	while (i < get_frame_max(type))
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

void	image_free(t_vars *vars)
{
	t_img	*img;

	if (vars->img0[0])
	{
		img = vars->img0[0];
		free(img->image);
		free(img);
	}
	if (vars->img1[0])
	{
		img = vars->img1[0];
		free(img->image);
		free(img);
	}
	if (vars->imgE[0])
	{
		img = vars->imgE[0];
		free(img->image);
		free(img);
	}
	image_free_sub(vars->imgC, TYPE_C);
	image_free_sub(vars->imgPW, TYPE_P);
	image_free_sub(vars->imgPS, TYPE_P);
	image_free_sub(vars->imgPA, TYPE_P);
	image_free_sub(vars->imgPD, TYPE_P);
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
