/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:16:22 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/11 12:29:48 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int key_up(t_vars *vars)
{
    (void)vars;
    ft_printf("[%d][%d]->[%d]\n", vars->y, vars->x, vars->texture[(vars->y*vars->w) + vars->x].type);
    return (0);
}

int key_down(t_vars *vars)
{
    (void)vars;
    return (0);
}

int key_left(t_vars *vars)
{
    (void)vars;
    return (0);
}

int key_right(t_vars *vars)
{
    (void)vars;
    return (0);
}
