/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/12 12:30:15 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static void	create_image0(t_vars *vars)
{
	int	width;
	int	height;

	vars->img0[0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/0/0.xpm", &width, &height);
}

static void	create_image1(t_vars *vars)
{
	int	width;
	int	height;

	vars->img1[0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/0.xpm", &width, &height);
	vars->img1[1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/1.xpm", &width, &height);
	vars->img1[2] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/2.xpm", &width, &height);
	vars->img1[3] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/3.xpm", &width, &height);
	vars->img1[4] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/4.xpm", &width, &height);
	vars->img1[5] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/5.xpm", &width, &height);
	vars->img1[6] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/6.xpm", &width, &height);
	vars->img1[7] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/7.xpm", &width, &height);
	vars->img1[8] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/8.xpm", &width, &height);
	vars->img1[9] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/1/9.xpm", &width, &height);
}

static void	create_imageC(t_vars *vars)
{
	int	width;
	int	height;

	vars->imgC[0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/0.xpm", &width, &height);
	vars->imgC[1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/1.xpm", &width, &height);
	vars->imgC[2] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/2.xpm", &width, &height);
	vars->imgC[3] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/3.xpm", &width, &height);
	vars->imgC[4] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/4.xpm", &width, &height);
	vars->imgC[5] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/5.xpm", &width, &height);
	vars->imgC[6] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/6.xpm", &width, &height);
	vars->imgC[7] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/7.xpm", &width, &height);
	vars->imgC[8] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/8.xpm", &width, &height);
	vars->imgC[9] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/C/9.xpm", &width, &height);
}

static void	create_imageP(t_vars *vars)
{
	int	width;
	int	height;

	vars->imgP[0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/0.xpm", &width, &height);
	vars->imgP[1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/1.xpm", &width, &height);
	vars->imgP[2] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/2.xpm", &width, &height);
	vars->imgP[3] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/3.xpm", &width, &height);
	vars->imgP[4] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/4.xpm", &width, &height);
	vars->imgP[5] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/5.xpm", &width, &height);
	vars->imgP[6] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/6.xpm", &width, &height);
	vars->imgP[7] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/7.xpm", &width, &height);
	vars->imgP[8] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/8.xpm", &width, &height);
	vars->imgP[9] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/P/9.xpm", &width, &height);
}

static void	create_imageE(t_vars *vars)
{
	int	width;
	int	height;

	vars->imgE[0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/0.xpm", &width, &height);
	vars->imgE[1] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/1.xpm", &width, &height);
	vars->imgE[2] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/2.xpm", &width, &height);
	vars->imgE[3] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/3.xpm", &width, &height);
	vars->imgE[4] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/4.xpm", &width, &height);
	vars->imgE[5] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/5.xpm", &width, &height);
	vars->imgE[6] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/6.xpm", &width, &height);
	vars->imgE[7] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/7.xpm", &width, &height);
	vars->imgE[8] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/8.xpm", &width, &height);
	vars->imgE[9] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/E/9.xpm", &width, &height);
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
		img = vars->imgP[vars->texture[i].frame];
	return (img);
}

// static char	*get_path(char type)
// {
// 	char	*path;

// 	path = NULL;
// 	if (type == TYPE_0)
// 		path = "./xpm/0/0.xpm";
// 	else if (type == TYPE_1)
// 		path = "./xpm/1/0.xpm";
// 	else if (type == TYPE_C)
// 		path = "./xpm/C/0.xpm";
// 	else if (type == TYPE_E)
// 		path = "./xpm/E/0.xpm";
// 	else if (type == TYPE_P)
// 		path = "./xpm/P/0.xpm";
// 	return (path);
// }

static void	type(t_vars *vars, char type)
{
	int		i;
	t_img	*img;
	// char	*path;
	// int		img_width;
	// int		img_height;

	i = 0;
	while (vars->size_map > i)
	{
		if (vars->texture[i].update && vars->texture[i].type == type)
		{
			vars->texture[i].update = False;
			// path = get_path(type);
			// img = mlx_xpm_file_to_image(vars->mlx, 
			// 	path, &img_width, &img_height);
			img = get_image(vars, type, i);
			mlx_put_image_to_window(vars->mlx, \
				vars->mlx_win, img, \
				i % vars->w * PIXEL_H, \
				i / vars->w * PIXEL_W);
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
			// free(img->image);
			// free(img);
		}
		i++;
	}
}

void	so_long_layer_update(t_vars *vars)
{
	type(vars, '1');
	type(vars, '0');
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
	create_image0(vars);
	create_image1(vars);
	create_imageC(vars);
	create_imageE(vars);
	create_imageP(vars);
}
