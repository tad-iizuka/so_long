/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:22 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/14 14:46:23 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	set_p(t_texture *txt, int direction)
{
	txt->type = 'P';
	txt->frame = 0;
	txt->direction = direction;
	txt->animation = is_animation(TYPE_P);
	txt->max_frame = get_frame_max(TYPE_P);
	txt->update = True;
}

void	set_0(t_texture *txt)
{
	txt->type = '0';
	txt->frame = 0;
	txt->animation = is_animation(TYPE_0);
	txt->max_frame = get_frame_max(TYPE_0);
	txt->update = True;
}
