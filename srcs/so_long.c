/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:36 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/16 07:16:49 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	so_long_init(t_vars *vars)
{
	vars->frame = 0;
	vars->num_map = 0;
	vars->complete = False;
	vars->map = NULL;
	vars->mtx = NULL;
	vars->texture = NULL;
	vars->step = 0;
	ft_random_init();
}

void	so_long_window_init(t_vars *vars, char *argv[])
{
	int		x;
	int		y;

	vars->mlx = mlx_init();
	if (!vars->mlx)
	{
		print_error("mlx_init");
		return ;
	}
	x = vars->w * PIXEL_W;
	y = vars->num_map * PIXEL_H;
	vars->mlx_win = mlx_new_window(vars->mlx, x, y, argv[0]);
	if (!vars->mlx)
	{
		print_error("mlx_win");
		return ;
	}
	so_long_layer_init(vars);
	mlx_hook(vars->mlx_win, 33, 1L << 17, key_close, vars);
	mlx_hook(vars->mlx_win, ON_KEYDOWN, 1L << 0, so_long_key_hook, vars);
	mlx_loop_hook(vars->mlx, so_long_timer, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc < 2)
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (1);
	}
	so_long_init(&vars);
	if (!so_long_map(argv[1], &vars))
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (1);
	}
	so_long_window_init(&vars, argv);
	return (1);
}
