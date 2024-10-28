/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:36 by tiizuka           #+#    #+#             */
/*   Updated: 2024/10/28 17:33:37 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, SCREEN_WIDHT, SCREEN_HEIGHT, "test");
	i = 0;
	while (i < SCREEN_WIDHT)
	{
		j = 0;
		while (j < SCREEN_WIDHT)
		{
			mlx_pixel_put(mlx, mlx_win, i, j, 127);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
	return (1);
}
