/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_common_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 08:06:52 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/16 08:31:28 by tiizuka          ###   ########.fr       */
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
