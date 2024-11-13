/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:22 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/13 12:37:26 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int	key_up(t_vars *vars)
{
	char	type;

	type = vars->texture[((vars->y - 1) * vars->w) + vars->x].type;
	if (type == '0' || type == 'C' || (type == 'E' && vars->num_c == 0))
	{
		vars->texture[((vars->y - 1) * vars->w) + vars->x].type = 'P';
		vars->texture[((vars->y - 1) * vars->w) + vars->x].update = True;
		vars->texture[((vars->y) * vars->w) + vars->x].type = '0';
		vars->texture[((vars->y) * vars->w) + vars->x].frame = 0;
		vars->texture[((vars->y) * vars->w) + vars->x].update = True;
		vars->y--;
		if (type == 'C')
			vars->num_c--;
		if (type == 'E')
			vars->complete = True;
		return (True);
	}
	return (False);
}

int	key_down(t_vars *vars)
{
	char	type;

	type = vars->texture[((vars->y + 1) * vars->w) + vars->x].type;
	if (type == '0' || type == 'C' || (type == 'E' && vars->num_c == 0))
	{
		vars->texture[((vars->y + 1) * vars->w) + vars->x].type = 'P';
		vars->texture[((vars->y + 1) * vars->w) + vars->x].update = True;
		vars->texture[((vars->y) * vars->w) + vars->x].type = '0';
		vars->texture[((vars->y) * vars->w) + vars->x].frame = 0;
		vars->texture[((vars->y) * vars->w) + vars->x].update = True;
		vars->y++;
		if (type == 'C')
			vars->num_c--;
		if (type == 'E')
			vars->complete = True;
		return (True);
	}
	return (False);
}

int	key_left(t_vars *vars)
{
	char	type;

	type = vars->texture[(vars->y * vars->w) + (vars->x - 1)].type;
	if (type == '0' || type == 'C' || (type == 'E' && vars->num_c == 0))
	{
		vars->texture[(vars->y * vars->w) + (vars->x - 1)].type = 'P';
		vars->texture[(vars->y * vars->w) + (vars->x - 1)].update = True;
		vars->texture[(vars->y * vars->w) + vars->x].type = '0';
		vars->texture[((vars->y) * vars->w) + vars->x].frame = 0;
		vars->texture[(vars->y * vars->w) + vars->x].update = True;
		vars->x--;
		if (type == 'C')
			vars->num_c--;
		if (type == 'E')
			vars->complete = True;
		return (True);
	}
	return (False);
}

int	key_right(t_vars *vars)
{
	char	type;

	type = vars->texture[(vars->y * vars->w) + (vars->x + 1)].type;
	if (type == '0' || type == 'C' || (type == 'E' && vars->num_c == 0))
	{
		vars->texture[(vars->y * vars->w) + (vars->x + 1)].type = 'P';
		vars->texture[(vars->y * vars->w) + (vars->x + 1)].update = True;
		vars->texture[(vars->y * vars->w) + vars->x].type = '0';
		vars->texture[((vars->y) * vars->w) + vars->x].frame = 0;
		vars->texture[(vars->y * vars->w) + vars->x].update = True;
		vars->x++;
		if (type == 'C')
			vars->num_c--;
		if (type == 'E')
			vars->complete = True;
		return (True);
	}
	return (False);
}
