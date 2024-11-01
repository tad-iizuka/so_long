/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:36 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/01 18:43:17 by tiizuka          ###   ########.fr       */
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

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	test(t_vars *vars)
{
	t_data	img;

	img.img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
}

int	render_next_frame(t_vars *vars)
{
	(void)vars;
	ft_print_utime("next frame");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	// int		i;
	// int		j;

	(void)argc;
	(void)argv;
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		print_error("mlx_init");
		return (1);
	}
	vars.mlx_win = mlx_new_window(vars.mlx, WIN_W, WIN_H, "so_long");
	if (!vars.mlx)
	{
		print_error("mlx_win");
		return (1);
	}
	test(&vars);
	// i = 0;
	// while (i < WIN_W)
	// {
	// 	j = 0;
	// 	while (j < WIN_H)
	// 	{
	// 		mlx_pixel_put(vars.mlx, vars.mlx_win, i, j, 127);
	// 		j++;
	// 	}
	// 	i++;
	// }
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 33, 1L << 17, key_close, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (1);
}
