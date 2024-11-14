/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_common.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/14 14:25:13 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int	get_frame_max(char type)
{
	if (type == TYPE_C)
		return (FRAME_MAX_C);
	else if (type == TYPE_P)
		return (FRAME_MAX_P);
	return (FRAME_MAX);
}

int	is_animation(char type)
{
	if (type == TYPE_0 || type == TYPE_1 || type == TYPE_E)
		return (False);
	return (True);
}
