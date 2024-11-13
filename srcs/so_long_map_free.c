/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:48:10 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/13 11:34:42 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	image_free_sub(void **p)
{
	int		i;
	t_img	*img;

	i = 0;
	i = 0;
	while (i < FRAME_MAX)
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
	image_free_sub(vars->img1);
	image_free_sub(vars->imgC);
	image_free_sub(vars->imgE);
	image_free_sub(vars->imgPW);
	image_free_sub(vars->imgPS);
	image_free_sub(vars->imgPA);
	image_free_sub(vars->imgPD);
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
