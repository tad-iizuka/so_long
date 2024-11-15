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
	img = vars->imgALPHA[c - 'A'];
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
			(i + 1 + 6) * 25, 16);
		i++;
	}
	i = 0;
	while (str[i])
	{
		img = get_image_num(vars, str[i]);
		mlx_put_image_to_window(vars->mlx, \
			vars->mlx_win, img, \
			(i + 1 + 6 + z) * 25, 16);
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
			(i + 1) * 25, 16);
		i++;
	}
}

void	so_long_layer_update_bonus(t_vars *vars)
{
	char	*p;

	display_str(vars, "SCORE");
	p = ft_itoa(vars->step);
	if (p)
	{
		display_score(vars, p);
		free(p);
	}
}
