/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:38:21 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/12 11:04:49 by tiizuka          ###   ########.fr       */
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
	if (vars->complete)
		return (1);
	if ((char)keycode == KEY_W)
		key_up(vars);
	else if ((char)keycode == KEY_S)
		key_down(vars);
	else if ((char)keycode == KEY_A)
		key_left(vars);
	else if ((char)keycode == KEY_D)
		key_right(vars);
	else
		printf("Hello from key_hook! [%02x]\n", (unsigned char)keycode);
	return (0);
}
