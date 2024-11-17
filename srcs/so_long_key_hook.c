/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:38:21 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/17 10:21:21 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int	key_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	map_free(vars);
	if (vars->mlx)
		free(vars->mlx);
	exit(0);
	return (0);
}

int	so_long_key_hook(int keycode, t_vars *vars)
{
	if ((char)keycode == KEY_ESC)
	{
		key_close(vars);
		return (0);
	}
	if (vars->complete != False)
		return (1);
	if (so_long_key_direction(vars, keycode))
	{
		so_long_layer_update(vars);
		vars->step++;
		if (!BONUS)
		{
			ft_printf("STEP: \x1b[32m[%04d]\x1b[0m\n", vars->step);
			if (vars->complete == FINISH_SUCCESS)
				ft_printf("GAME: \x1b[31m[GOAL]\x1b[0m ESC to Quit.\n");
		}
	}
	return (0);
}
