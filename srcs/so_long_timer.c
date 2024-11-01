/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_timer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 12:28:47 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/02 14:16:47 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	so_long_timer(t_vars *vars)
{
	vars->frame++;
	if ((vars->frame % FPS60) == 0)
		printf("[%zu]\n", vars->frame / FPS60 % 60);
	return (True);
}