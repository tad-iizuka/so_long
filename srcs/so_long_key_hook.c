/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:38:21 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/11 12:22:29 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int so_long_key_hook(int keycode, t_vars *vars)
{
    (void)vars;
	if ((char)keycode == KEY_ESC)
	{
		key_close(vars);
		return (0);
	}
	else if ((char)keycode == KEY_W)
		key_up(vars);
	else if ((char)keycode == KEY_S)
		key_down(vars);
	else if ((char)keycode == KEY_A)
		key_left(vars);
	else if ((char)keycode == KEY_D)
		key_right(vars);
	else
		printf("Hello from key_hook! [%02x]\n", (unsigned char)keycode);
	return (0);
}
