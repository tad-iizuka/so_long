/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/11 12:12:06 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static char	*get_path(char type)
{
	char	*path;

	path = NULL;
	if (type == TYPE_0)
		path = "./xpm/0/0.xpm";
	else if (type == TYPE_1)
		path = "./xpm/1/0.xpm";
	else if (type == TYPE_C)
		path = "./xpm/C/0.xpm";
	else if (type == TYPE_E)
		path = "./xpm/E/0.xpm";
	else if (type == TYPE_P)
		path = "./xpm/P/0.xpm";
	return	(path);
}

static void	type(t_vars *vars, char type)
{
	int		i;
	t_img	*img;
	char	*path;
	int		img_width;
	int		img_height;

	i = 0;
	while (vars->size_map > i)
	{
		if (vars->texture[i].update && vars->texture[i].type == type)
		{
			vars->texture[i].update = False;
			path = get_path(type);
			img = mlx_xpm_file_to_image(vars->mlx, \
				path, &img_width, &img_height);
			mlx_put_image_to_window(vars->mlx, \
				vars->mlx_win, img, \
				i % vars->w * PIXEL_H, \
				i / vars->w * PIXEL_W);
			free(img->image);
			free(img);
		}
		i++;
	}
}

void	so_long_layer_update(t_vars *vars)
{
	type(vars, '1');
	// type(vars, '0');
	type(vars, 'C');
	type(vars, 'E');
	type(vars, 'P');
}

void	so_long_layer_init(t_vars *vars)
{
	int			i;
	t_texture	*texture;

	texture = (t_texture *)malloc(sizeof(t_texture) * vars->size_map);
	if (!texture)
		return ;
	vars->texture = texture;
	i = 0;
	while (vars->size_map > i)
	{
		vars->texture[i].type = vars->mtx[i];
		vars->texture[i].update = False;
		vars->texture[i].animation = True;
		vars->texture[i].frame = 0;
		vars->texture[i].max_frame = 10;
		vars->texture[i].repeat = True;
		i++;
	}
	i = 0;
	while (vars->size_map > i)
	{
		vars->texture[i++].update = True;
	}
}
