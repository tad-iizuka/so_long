/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_common_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:22 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 09:07:43 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	set_w(t_texture *tex, int direction, char type)
{
	tex->check = True;
	tex->type = 'W';
	tex->frame = 0;
	tex->direction = direction;
	if (type == 'P')
	{
		tex->animation = False;
		tex->max_frame = 0;
	}
	else
	{
		tex->animation = is_animation(TYPE_W);
		tex->max_frame = get_frame_max(TYPE_W);
	}
	tex->update = True;
}
