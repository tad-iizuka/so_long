/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:24 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/14 11:46:32 by tiizuka          ###   ########.fr       */
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
# include	"../minilibx-linux/mlx.h"
# include	"../minilibx-linux/mlx_int.h"
# include	"../libft/libft.h"
# include	"so_long_error.h"

# ifndef BONUS
#  define BONUS 0
# endif

# define WIN_W	1920 / 2
# define WIN_H	1080 / 2
# define PIXEL_W	64
# define PIXEL_H	64
# define FPS	6000 
// # define FPS	3000

# define KEY_W 0x77
# define KEY_D 0x64
# define KEY_A 0x61
# define KEY_S 0x73
# define KEY_ESC 0x1b

# define DIR_W 0
# define DIR_S 1
# define DIR_A 2
# define DIR_D 3
# define FRAME_MAX_C 7
# define FRAME_MAX_P 8
# define FRAME_MAX 1

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
	int		direction;	// 0:w, 1:s, 2:a, 3:d
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
	int			num_c;
	int			step;
	int			complete;
	void		*img0[1];
	void		*img1[1];
	void		*imgC[10];
	void		*imgE[10];
	void		*imgPW[8];
	void		*imgPS[8];
	void		*imgPA[8];
	void		*imgPD[8];
	t_map		**map;
	char		*mtx;
	t_texture	*texture;
	t_img		*type[5];
	size_t		frame;
}	t_vars;

int		ft_random(int range);
void	ft_print_utime(char *id);

void	print_error(char *str);

int		key_close(t_vars *vars);
int		key_up(t_vars *vars);
int		key_down(t_vars *vars);
int		key_left(t_vars *vars);
int		key_right(t_vars *vars);
int		so_long_timer(t_vars *vars);
int		so_long_map(char *path, t_vars *vars);
void	so_long_layer_init(t_vars *vars);
void	so_long_layer_update(t_vars *vars);
int		so_long_key_hook(int keycode, t_vars *vars);

t_map	*map_new(char *str);
int		map_to_mtx(t_vars *vars);
void	map_free(t_vars *vars);
int		map_check_main(t_vars *vars);
int		map_check_route(t_vars *vars);
void	map_find_pos(t_vars *vars);

int		get_frame_max(char type);
int		is_animation(char type);

void	set_p(t_texture *txt, int direction);
void	set_0(t_texture *txt);

#endif
