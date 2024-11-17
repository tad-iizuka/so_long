/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_update_bonus_sub.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 09:43:28 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

static void	check_hit_box(t_vars *vars, char type)
{
	if (type == 'P')
		vars->complete = FINISH_FAIL;
}

static int	key_cont(t_vars *vars, t_texture *to, int dir, int i)
{
	char	type;

	type = to->type;
	if (type == '0' || type == 'P')
	{
		set_w(to, dir, type);
		set_0(&vars->texture[i]);
		check_hit_box(vars, type);
		return (True);
	}
	else
	{
		vars->texture[i].direction = dir;
		vars->texture[i].update = True;
	}
	return (False);
}

static void	key_direction(t_vars *vars, int keycode, int i)
{
	if ((char)keycode == KEY_UP)
		key_cont(vars, &vars->texture[i - vars->w], DIR_W, i);
	else if ((char)keycode == KEY_DOWN)
		key_cont(vars, &vars->texture[i + vars->w], DIR_S, i);
	else if ((char)keycode == KEY_L)
		key_cont(vars, &vars->texture[i + 1], DIR_D, i);
	else if ((char)keycode == KEY_R)
		key_cont(vars, &vars->texture[i - 1], DIR_A, i);
}

void	villan_move(t_vars *vars)
{
	int			i;
	int			keycode;

	if (vars->complete != False)
		return ;
	i = 0;
	while (vars->size_map > i)
	{
		if (vars->texture[i].type == 'W' && !vars->texture[i].check)
		{
			keycode = ft_random(4);
			if (keycode == 0)
				key_direction(vars, KEY_UP, i);
			else if (keycode == 1)
				key_direction(vars, KEY_DOWN, i);
			else if (keycode == 2)
				key_direction(vars, KEY_L, i);
			else
				key_direction(vars, KEY_R, i);
		}
		i++;
	}
}
