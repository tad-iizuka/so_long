/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:22 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/15 12:35:33 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int	key_up(t_vars *vars)
{
	char	type;

	type = vars->texture[((vars->y - 1) * vars->w) + vars->x].type;
	if (type == '0' || type == 'C' || (type == 'E' && vars->num_c == 0))
	{
		set_p(&vars->texture[((vars->y - 1) * vars->w) + vars->x], DIR_W, type);
		set_0(&vars->texture[((vars->y) * vars->w) + vars->x]);
		vars->y--;
		if (type == 'C')
			vars->num_c--;
		if (type == 'E')
			vars->complete = True;
		return (True);
	}
	else
	{
		vars->texture[(vars->y * vars->w) + vars->x].direction = DIR_W;
		vars->texture[(vars->y * vars->w) + vars->x].update = True;
	}
	return (False);
}

int	key_down(t_vars *vars)
{
	char	type;

	type = vars->texture[((vars->y + 1) * vars->w) + vars->x].type;
	if (type == '0' || type == 'C' || (type == 'E' && vars->num_c == 0))
	{
		set_p(&vars->texture[((vars->y + 1) * vars->w) + vars->x], DIR_S, type);
		set_0(&vars->texture[((vars->y) * vars->w) + vars->x]);
		vars->y++;
		if (type == 'C')
			vars->num_c--;
		if (type == 'E')
			vars->complete = True;
		return (True);
	}
	else
	{
		vars->texture[(vars->y * vars->w) + vars->x].direction = DIR_S;
		vars->texture[(vars->y * vars->w) + vars->x].update = True;
	}
	return (False);
}

int	key_left(t_vars *vars)
{
	char	type;

	type = vars->texture[(vars->y * vars->w) + (vars->x - 1)].type;
	if (type == '0' || type == 'C' || (type == 'E' && vars->num_c == 0))
	{
		set_p(&vars->texture[(vars->y * vars->w) + (vars->x - 1)], DIR_A, type);
		set_0(&vars->texture[(vars->y * vars->w) + vars->x]);
		vars->x--;
		if (type == 'C')
			vars->num_c--;
		if (type == 'E')
			vars->complete = True;
		return (True);
	}
	else
	{
		vars->texture[(vars->y * vars->w) + vars->x].direction = DIR_A;
		vars->texture[(vars->y * vars->w) + vars->x].update = True;
	}
	return (False);
}

int	key_right(t_vars *vars)
{
	char	type;

	type = vars->texture[(vars->y * vars->w) + (vars->x + 1)].type;
	if (type == '0' || type == 'C' || (type == 'E' && vars->num_c == 0))
	{
		set_p(&vars->texture[(vars->y * vars->w) + (vars->x + 1)], DIR_D, type);
		set_0(&vars->texture[(vars->y * vars->w) + vars->x]);
		vars->x++;
		if (type == 'C')
			vars->num_c--;
		if (type == 'E')
			vars->complete = True;
		return (True);
	}
	else
	{
		vars->texture[(vars->y * vars->w) + vars->x].direction = DIR_D;
		vars->texture[(vars->y * vars->w) + vars->x].update = True;
	}
	return (False);
}
