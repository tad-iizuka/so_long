/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:22 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/15 14:38:50 by tiizuka          ###   ########.fr       */
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

int	so_long_key_direction(t_vars *vars, int keycode)
{
	int	r;

	r = False;
	if ((char)keycode == KEY_W || (char)keycode == KEY_UP)
		r = key_up(vars);
	else if ((char)keycode == KEY_S || (char)keycode == KEY_DOWN)
		r = key_down(vars);
	else if ((char)keycode == KEY_A || (char)keycode == KEY_L)
		r = key_left(vars);
	else if ((char)keycode == KEY_D || (char)keycode == KEY_R)
		r = key_right(vars);
	return (r);
}
