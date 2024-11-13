/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/13 13:27:07 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static void	create_image0(t_vars *vars)
{
	int		w;
	int		h;

	vars->img0[0] = mlx_xpm_file_to_image(vars->mlx, \
		"./xpm/0/0.xpm", &w, &h);
}

static int	create_image(t_vars *vars, void **img, char *path)
{
	int		i;
	char	*p;
	char	str[6];
	int		w;
	int		h;

	i = 0;
	while (i < 10)
	{
		ft_strlcpy(&str[0], "0.xpm", sizeof(str));
		str[0] += i;
		p = ft_strjoin(path, str);
		if (p)
		{
			img[i] = mlx_xpm_file_to_image(vars->mlx, \
				p, &w, &h);
			free(p);
		}
		else
			return (False);
		i++;
	}
	return (True);
}

static void	create_images(t_vars *vars)
{
	create_image0(vars);
	create_image(vars, vars->img1, "./xpm/1/");
	create_image(vars, vars->imgC, "./xpm/C/");
	create_image(vars, vars->imgE, "./xpm/E/");
	create_image(vars, vars->imgP, "./xpm/P/");
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
		vars->texture[i++].update = True;
	create_images(vars);
}
