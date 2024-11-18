/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:24 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 13:55:33 by tiizuka          ###   ########.fr       */
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

# define FINISH_SUCCESS 1
# define FINISH_FAIL 2

# define PIXEL_W	64
# define PIXEL_H	64
# define FPS_100	6000
# define FPS_200	12000
# define FPS_400	24000
# define FPS_1000	60000
# define WIZARD_ANIMATION_DELAY 30

# define KEY_W 0x77
# define KEY_D 0x64
# define KEY_A 0x61
# define KEY_S 0x73
# define KEY_UP 0x52
# define KEY_DOWN 0x54
# define KEY_L 0x51
# define KEY_R 0x53
# define KEY_ESC 0x1b

# define DIR_W 0
# define DIR_S 1
# define DIR_A 2
# define DIR_D 3
# define FRAME_MAX_C 7
# define FRAME_MAX_P 8
# define FRAME_MAX 1
# define FRAME_MAX_W 8

# define NUM_ALPHA 26
# define NUM_NUM 10
# define NUM_SYM 3
// a: !
// b: ?
// c: 

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_map
{
	char	*map;
	int		x;
	int		num_0;
	int		num_1;
	int		num_c;
	int		num_e;
	int		num_p;
}	t_map;

enum e_texture
{
	TYPE_0 = '0',
	TYPE_1 = '1',
	TYPE_C = 'C',
	TYPE_E = 'E',
	TYPE_P = 'P',
	TYPE_W = 'W'
};

typedef struct s_texture
{
	int		update;
	int		type;
	int		animation;
	int		frame;
	int		max_frame;
	int		direction;
	int		repeat;
	int		check;
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
	int			num_wizard;
	int			num_space;
	int			step;
	int			complete;
	void		*img0[FRAME_MAX];
	void		*img1[FRAME_MAX];
	void		*img_c[FRAME_MAX_C];
	void		*img_e[FRAME_MAX];
	void		*img_pw[FRAME_MAX_P];
	void		*img_ps[FRAME_MAX_P];
	void		*img_pa[FRAME_MAX_P];
	void		*img_pd[FRAME_MAX_P];
	void		*img_ww[FRAME_MAX_W];
	void		*img_ws[FRAME_MAX_W];
	void		*img_wa[FRAME_MAX_W];
	void		*img_wd[FRAME_MAX_W];
	void		*img_alpha[NUM_ALPHA];
	void		*img_num[NUM_NUM];
	void		*img_sym[NUM_SYM];
	t_map		**map;
	char		*mtx;
	t_texture	*texture;
	t_img		*type[5];
	size_t		frame;
}	t_vars;

void	ft_random_init(void);
int		ft_random(int range);
void	ft_print_utime(char *id);

void	print_error(char *str);

int		loop_hook(t_vars *vars);
int		map_main(char *path, t_vars *vars);
void	layer_init(t_vars *vars);
void	layer_update(t_vars *vars);
void	layer_update_bonus(t_vars *vars);
int		key_hook(int keycode, t_vars *vars);
int		key_direction(t_vars *vars, int keycode);
int		key_close(t_vars *vars);

t_map	*map_new(char *str);
int		map_to_mtx(t_vars *vars);
void	map_free(t_vars *vars);
int		map_check(t_vars *vars);
int		map_check_route(t_vars *vars);
void	map_find_pos(t_vars *vars);
void	map_calc_wizard(t_vars *vars);
void	map_create_wizard(t_vars *vars);

int		get_frame_max(char type);
int		get_direction(char type);
int		is_animation(char type);
void	type_display(t_vars *vars, char type);

void	set_p(t_texture *txt, int direction, char type);
void	set_0(t_texture *txt);
void	init_images(t_vars *vars);
void	create_images_alnum(t_vars *vars, char *name, char *path, int num);
void	create_image_one(t_vars *vars, void **img, char *path, int i);
void	*get_image_alpha(t_vars *vars, char c);
void	*get_image_num(t_vars *vars, char c);
void	*get_image_w(t_vars *vars, int i);

void	set_w(t_texture *txt, int direction, char type);
void	wizard_move(t_vars *vars);
void	display_score(t_vars *vars, char *str);
void	display_str(t_vars *vars, char *str);
void	overlay_message_update(t_vars *vars);

#endif
