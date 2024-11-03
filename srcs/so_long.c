/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:36 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/03 08:28:49 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	printf("[%d]\n", (char)keycode);
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
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;

	(void)argc;
	(void)argv;
	relative_path = "./player.xpm";
	vars.frame = 0;
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
	if (argc > 1)
		so_long_map(argv[1], &vars);
	img = mlx_xpm_file_to_image(vars.mlx, \
		relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img, 0, 0);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 33, 1L << 17, key_close, &vars);
	mlx_loop_hook(vars.mlx, so_long_timer, &vars);
	mlx_loop(vars.mlx);
	return (1);
}
