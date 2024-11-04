/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:24 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/04 14:08:43 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include	<stdio.h>
# include	<string.h>
# include	<stdlib.h>
# include	<X11/Xlib.h>
# include	<sys/ipc.h>
# include	<sys/shm.h>
# include	<sys/time.h>
# include	<sys/stat.h>
# include	<fcntl.h>
# include	<time.h>
// # include	<X11/extensions/XShm.h>
# include	"../minilibx-linux/mlx.h"
# include	"../libft/libft.h"
# include	"so_long_error.h"

# define WIN_W	1920 / 2
# define WIN_H	1080 / 2
# define FPS60	833

typedef struct s_map
{
	char	*map;
	int		x;
	int		num_0;
	int		num_1;
	int		num_C;
	int		num_E;
	int		num_P;
}	t_map;

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		num_map;
	t_map	**map;
	char	*mtx;
	size_t	frame;
}	t_vars;

void	print_error(char *str);
void	ft_print_utime(char *id);
int		so_long_timer(t_vars *vars);
int		so_long_map(char *path, t_vars *vars);

t_map	*map_new(char *str);
int		map_to_mtx(t_vars *vars);
void	map_free(t_vars *vars);
int		map_check_main(t_vars *vars);
void	map_find_pos(t_vars *vars);

#endif
