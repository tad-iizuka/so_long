/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/16 07:43:28 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static int	create_image(t_vars *vars, void **img, char *path, char type)
{
	int		i;
	char	*p;
	char	str[6];
	int		w;
	int		h;

	i = 0;
	while (i < get_frame_max(type))
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
	create_image_one(vars, vars->img0, "./xpm/0/0.xpm", 0);
	create_image_one(vars, vars->img1, "./xpm/1/0.xpm", 0);
	create_image_one(vars, vars->imgE, "./xpm/E/0.xpm", 0);
	create_image(vars, vars->imgC, "./xpm/C/", TYPE_C);
	create_image(vars, vars->imgPW, "./xpm/P/W/", TYPE_P);
	create_image(vars, vars->imgPS, "./xpm/P/S/", TYPE_P);
	create_image(vars, vars->imgPA, "./xpm/P/A/", TYPE_P);
	create_image(vars, vars->imgPD, "./xpm/P/D/", TYPE_P);
	if (BONUS)
	{
		create_images_alnum(vars, "A.xpm", "./xpm/ALPHA/", NUM_ALPHA);
		create_images_alnum(vars, "0.xpm", "./xpm/NUM/", NUM_NUM);
		create_images_alnum(vars, "a.xpm", "./xpm/ALPHA/", NUM_SYM);
		create_image(vars, vars->imgWW, "./xpm/W/W/", TYPE_W);
		create_image(vars, vars->imgWS, "./xpm/W/S/", TYPE_W);
		create_image(vars, vars->imgWA, "./xpm/W/A/", TYPE_W);
		create_image(vars, vars->imgWD, "./xpm/W/D/", TYPE_W);
	}
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
		vars->texture[i].animation = is_animation(vars->mtx[i]);
		vars->texture[i].frame = 0;
		vars->texture[i].max_frame = get_frame_max(vars->mtx[i]);
		vars->texture[i].direction = DIR_S;
		vars->texture[i].repeat = True;
		i++;
	}
	i = 0;
	while (vars->size_map > i)
		vars->texture[i++].update = True;
	create_images(vars);
}
