/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:22 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 09:16:07 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	set_p(t_texture *txt, int direction, char type)
{
	if (type != 'W')
		txt->type = 'P';
	txt->frame = 0;
	if (type == 'E' || type == 'W')
	{
		if (type == 'E')
			txt->direction = DIR_S;
		else
			txt->direction = direction;
		txt->animation = False;
		txt->max_frame = 0;
	}
	else
	{
		txt->direction = direction;
		txt->animation = is_animation(TYPE_P);
		txt->max_frame = get_frame_max(TYPE_P);
	}
	txt->update = True;
}

void	set_0(t_texture *tex)
{
	tex->type = '0';
	tex->frame = 0;
	tex->animation = is_animation(TYPE_0);
	tex->max_frame = get_frame_max(TYPE_0);
	tex->check = False;
	tex->update = True;
}
