/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:22 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 07:06:49 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static void	update_p_pos(t_vars *vars, int dir)
{
	if (dir == DIR_W)
		vars->y--;
	else if (dir == DIR_S)
		vars->y++;
	else if (dir == DIR_A)
		vars->x--;
	else
		vars->x++;
}

static void	check_hit_box(t_vars *vars, char type)
{
	if (type == 'W')
		vars->complete = FINISH_FAIL;
	else if (type == 'C')
		vars->num_c--;
	else if (type == 'E')
		vars->complete = FINISH_SUCCESS;
}

static int	key_cont(t_vars *vars, t_texture *to, int dir)
{
	char	type;

	type = to->type;
	if (type == '0' || type == 'C' || type == 'W' || \
		(type == 'E' && vars->num_c == 0))
	{
		set_p(to, dir, type);
		set_0(&vars->texture[(vars->y * vars->w) + vars->x]);
		update_p_pos(vars, dir);
		check_hit_box(vars, type);
		return (True);
	}
	else
	{
		vars->texture[(vars->y * vars->w) + vars->x].direction = dir;
		vars->texture[(vars->y * vars->w) + vars->x].update = True;
	}
	return (False);
}

int	so_long_key_direction(t_vars *vars, int keycode)
{
	int	r;

	r = False;
	if ((char)keycode == KEY_W || (char)keycode == KEY_UP)
		r = key_cont(vars, &vars->texture[((vars->y - 1) * vars->w) + vars->x], \
			DIR_W);
	else if ((char)keycode == KEY_S || (char)keycode == KEY_DOWN)
		r = key_cont(vars, &vars->texture[((vars->y + 1) * vars->w) + vars->x], \
			DIR_S);
	else if ((char)keycode == KEY_A || (char)keycode == KEY_L)
		r = key_cont(vars, &vars->texture[(vars->y * vars->w) + (vars->x - 1)], \
			DIR_A);
	else if ((char)keycode == KEY_D || (char)keycode == KEY_R)
		r = key_cont(vars, &vars->texture[(vars->y * vars->w) + (vars->x + 1)], \
			DIR_D);
	return (r);
}
