/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 13:55:21 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static void	init_image(void **p, int size)
{
	int		i;

	i = 0;
	while (i < size)
		p[i++] = NULL;
}

void	init_images(t_vars *vars)
{
	init_image(vars->img0, FRAME_MAX);
	init_image(vars->img1, FRAME_MAX);
	init_image(vars->img_e, FRAME_MAX);
	init_image(vars->img_c, FRAME_MAX_C);
	init_image(vars->img_pw, FRAME_MAX_P);
	init_image(vars->img_ps, FRAME_MAX_P);
	init_image(vars->img_pa, FRAME_MAX_P);
	init_image(vars->img_pd, FRAME_MAX_P);
	if (BONUS)
	{
		init_image(vars->img_alpha, NUM_ALPHA);
		init_image(vars->img_num, NUM_NUM);
		init_image(vars->img_sym, NUM_SYM);
		init_image(vars->img_ww, FRAME_MAX_W);
		init_image(vars->img_ws, FRAME_MAX_W);
		init_image(vars->img_wa, FRAME_MAX_W);
		init_image(vars->img_wd, FRAME_MAX_W);
	}
}

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
	create_image_one(vars, vars->img_e, "./xpm/E/0.xpm", 0);
	create_image(vars, vars->img_c, "./xpm/C/", TYPE_C);
	create_image(vars, vars->img_pw, "./xpm/P/W/", TYPE_P);
	create_image(vars, vars->img_ps, "./xpm/P/S/", TYPE_P);
	create_image(vars, vars->img_pa, "./xpm/P/A/", TYPE_P);
	create_image(vars, vars->img_pd, "./xpm/P/D/", TYPE_P);
	if (BONUS)
	{
		create_images_alnum(vars, "A.xpm", "./xpm/ALPHA/", NUM_ALPHA);
		create_images_alnum(vars, "0.xpm", "./xpm/NUM/", NUM_NUM);
		create_images_alnum(vars, "a.xpm", "./xpm/ALPHA/", NUM_SYM);
		create_image(vars, vars->img_ww, "./xpm/W/W/", TYPE_W);
		create_image(vars, vars->img_ws, "./xpm/W/S/", TYPE_W);
		create_image(vars, vars->img_wa, "./xpm/W/A/", TYPE_W);
		create_image(vars, vars->img_wd, "./xpm/W/D/", TYPE_W);
	}
}

void	layer_init(t_vars *vars)
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
		vars->texture[i].direction = get_direction(vars->mtx[i]);
		vars->texture[i].repeat = True;
		vars->texture[i].check = False;
		i++;
	}
	i = 0;
	while (vars->size_map > i)
		vars->texture[i++].update = True;
	create_images(vars);
}
