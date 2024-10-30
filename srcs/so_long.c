/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:36 by tiizuka           #+#    #+#             */
/*   Updated: 2024/10/30 15:42:59 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("[%d]\n", keycode);
	return (1);
}

int	key_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	exit(0);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		i;
	int		j;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, SCREEN_WIDHT, SCREEN_HEIGHT, "test");
	i = 0;
	while (i < SCREEN_WIDHT)
	{
		j = 0;
		while (j < SCREEN_HEIGHT)
		{
			mlx_pixel_put(vars.mlx, vars.mlx_win, i, j, 127);
			j++;
		}
		i++;
	}
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 33, 1L << 17, key_close, &vars);
	mlx_loop(vars.mlx);
	return (1);
}
