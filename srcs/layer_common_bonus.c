/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_common_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:06:52 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 12:13:21 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	*get_image_alpha(t_vars *vars, char c)
{
	void	*img;

	img = NULL;
	if (c <= 'Z')
		img = vars->img_alpha[c - 'A'];
	else
		img = vars->img_sym[c - 'a'];
	return (img);
}

void	*get_image_num(t_vars *vars, char c)
{
	void	*img;

	img = NULL;
	img = vars->img_num[c - '0'];
	return (img);
}

void	display_score(t_vars *vars, char *str)
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

void	display_str(t_vars *vars, char *str)
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
