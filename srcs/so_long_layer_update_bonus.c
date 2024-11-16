/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_update_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/15 14:08:23 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static void	*get_image_alpha(t_vars *vars, char c)
{
	void	*img;

	img = NULL;
	if (c <= 'Z')
		img = vars->imgALPHA[c - 'A'];
	else
		img = vars->imgSYM[c - 'a'];
	return (img);
}

static void	*get_image_num(t_vars *vars, char c)
{
	void	*img;

	img = NULL;
	img = vars->imgNUM[c - '0'];
	return (img);
}

static void	display_score(t_vars *vars, char *str)
{
	int		i;
	int		z;
	t_img	*img;

	z = 4 - ft_strlen(str);
	i = 0;
	while (i < z)
	{
		img = get_image_num(vars, '0');
		mlx_put_image_to_window(vars->mlx, \
			vars->mlx_win, img, \
			((vars->w * PIXEL_W / 2) - (25 * 2)) + i * 25, 16);
		i++;
	}
	i = 0;
	while (str[i])
	{
		img = get_image_num(vars, str[i]);
		mlx_put_image_to_window(vars->mlx, \
			vars->mlx_win, img, \
			((vars->w * PIXEL_W / 2) - (25 * 2)) \
			+ (z + i) * 25, 16);
		i++;
	}
}

static void	display_str(t_vars *vars, char *str)
{
	int		i;
	t_img	*img;

	i = 0;
	while (str[i])
	{
		img = get_image_alpha(vars, str[i]);
		mlx_put_image_to_window(vars->mlx, \
			vars->mlx_win, img, \
			((vars->w * PIXEL_W / 2) - ((25 * ft_strlen(str)) / 2)) \
			+ (i * 25), \
			((vars->num_map * PIXEL_H / 2) - 16));
		i++;
	}
}

void	so_long_layer_update_bonus(t_vars *vars)
{
	char	*p;

	p = ft_itoa(vars->step);
	if (p)
	{
		display_score(vars, p);
		free(p);
	}
	if (vars->complete)
		display_str(vars, "GOALa");
}
