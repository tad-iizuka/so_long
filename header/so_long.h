/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:24 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/09 13:32:10 by tiizuka          ###   ########.fr       */
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
# include	"../minilibx-linux/mlx_int.h"
# include	"../libft/libft.h"
# include	"so_long_error.h"

# define WIN_W	1920 / 2
# define WIN_H	1080 / 2
# define PIXEL_W	128
# define PIXEL_H	128
# define FPS	500

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

enum e_texture
{
	TYPE_0 = '0',
	TYPE_1 = '1',
	TYPE_C = 'C',
	TYPE_E = 'E',
	TYPE_P = 'P'
};

typedef struct s_texture
{
	int		update;
	int		type;
	int		animation;
	int		frame;
	int		max_frame;
	int		repeat;
}	t_texture;

typedef struct s_vars {
	void		*mlx;
	void		*mlx_win;
	int			x;
	int			y;
	int			w;
	int			size_map;
	int			num_map;
	t_map		**map;
	char		*mtx;
	t_texture	*texture;
	t_img		*type[5];
	size_t		frame;
}	t_vars;

void	print_error(char *str);
void	ft_print_utime(char *id);
int		so_long_timer(t_vars *vars);
int		so_long_map(char *path, t_vars *vars);
void	so_long_layer_init(t_vars *vars);
void	so_long_layer_update(t_vars *vars);

t_map	*map_new(char *str);
int		map_to_mtx(t_vars *vars);
void	map_free(t_vars *vars);
int		map_check_main(t_vars *vars);
int		map_check_route(t_vars *vars);
void	map_find_pos(t_vars *vars);

#endif
