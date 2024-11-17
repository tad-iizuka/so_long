/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_common.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 09:27:17 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int	get_frame_max(char type)
{
	if (type == TYPE_C)
		return (FRAME_MAX_C);
	else if (type == TYPE_P)
		return (FRAME_MAX_P);
	else if (type == TYPE_W)
		return (FRAME_MAX_W);
	return (FRAME_MAX);
}

int	get_direction(char type)
{
	if (type == TYPE_W)
		return (ft_random(4));
	return (DIR_S);
}

int	is_animation(char type)
{
	if (type == TYPE_0 || type == TYPE_1 || type == TYPE_E)
		return (False);
	if (type == TYPE_W)
		return (True);
	return (BONUS);
}

void	create_image_one(t_vars *vars, void **img, char *path, int i)
{
	int		w;
	int		h;

	img[i] = mlx_xpm_file_to_image(vars->mlx, path, &w, &h);
}
