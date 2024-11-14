/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:38:21 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/14 11:52:24 by tiizuka          ###   ########.fr       */
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
	int	r;

	r = False;
	if ((char)keycode == KEY_ESC)
	{
		key_close(vars);
		return (0);
	}
	if (vars->complete)
		return (1);
	if ((char)keycode == KEY_W)
		r = key_up(vars);
	else if ((char)keycode == KEY_S)
		r = key_down(vars);
	else if ((char)keycode == KEY_A)
		r = key_left(vars);
	else if ((char)keycode == KEY_D)
		r = key_right(vars);
	if (r)
	{
		so_long_layer_update(vars);
		if (!BONUS)
			ft_printf("STEP: \x1b[32m[%04d]\x1b[0m\n", ++vars->step);
	}
	return (0);
}
