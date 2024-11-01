/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:39:24 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/01 18:35:31 by tiizuka          ###   ########.fr       */
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
# include	<time.h>
# include	<X11/extensions/XShm.h>
# include	"../minilibx-linux/mlx.h"
# include	"../libft/libft.h"
# include	"so_long_error.h"

# define WIN_W 1920
# define WIN_H 1080

typedef struct s_vars {
	void	*mlx;
	void	*mlx_win;
}	t_vars;

void	print_error(char *str);
void	ft_print_utime(char *id);

#endif
