/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 10:38:21 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/10 10:58:06 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int so_long_key_hook(int keycode, t_vars *vars)
{
    (void)vars;
	printf("Hello from key_hook! [%02x]\n", (unsigned char)keycode);
	return (0);
}
