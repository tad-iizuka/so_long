/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:36 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/10 10:41:49 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

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
	*(unsigned int *)dst = color;
}

void	test(t_vars *vars)
{
	t_data	img;
	int		i;
	int		j;

	img.img = mlx_new_image(vars->mlx, WIN_W, WIN_H);
	img.addr = mlx_get_data_addr(img.img, \
		&img.bits_per_pixel, \
		&img.line_length, \
		&img.endian);
	i = 0;
	while (i < WIN_W)
	{
		j = 0;
		while (j < WIN_H)
		{
			if ((i + 1) % 10 == 0)
				my_mlx_pixel_put(&img, i, j, 0x00FFFFFF);
			else
				my_mlx_pixel_put(&img, i, j, 0x00FF0000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, img.img, 0, 0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		x;
	int		y;

	vars.frame = 0;
	vars.num_map = 0;
	vars.map = NULL;
	vars.mtx = NULL;
	vars.texture = NULL;
	if (argc < 2)
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (1);
	}
	if (!so_long_map(argv[1], &vars))
	{
		ft_putstr_fd("Error\n", STDOUT_FILENO);
		return (1);
	}
	vars.mlx = mlx_init();
	if (!vars.mlx)
	{
		print_error("mlx_init");
		return (1);
	}
	x = vars.w * PIXEL_W;
	y = vars.num_map * PIXEL_H;
	vars.mlx_win = mlx_new_window(vars.mlx, x, y, "so_long");
	if (!vars.mlx)
	{
		print_error("mlx_win");
		return (1);
	}
	so_long_layer_init(&vars);
	mlx_hook(vars.mlx_win, 33, 1L << 17, key_close, &vars);
	mlx_key_hook(vars.mlx_win, so_long_key_hook, &vars);
	mlx_loop_hook(vars.mlx, so_long_timer, &vars);
	mlx_loop(vars.mlx);
	return (1);
}
