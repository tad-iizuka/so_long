/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_route.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:43:23 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/04 08:43:46 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

int	map_check_route_sub_find(int x, int y, char *mtx, t_vars *vars)
{
	int	r;

	r = True;
	if (mtx[(vars->w * y) + x] == '0')
		mtx[(vars->w * y) + x] = 'x';
	else if (mtx[(vars->w * y) + x] == 'C')
		mtx[(vars->w * y) + x] = 'x';
	else if (mtx[(vars->w * y) + x] == 'P')
		mtx[(vars->w * y) + x] = 'x';
	else
		r = False;
	return (r);
}

int	map_check_route_sub(int x, int y, char *mtx, t_vars *vars)
{
	if (mtx[(vars->w * y) + x] == 'E')
		return (True);
	else if (!map_check_route_sub_find(x, y, mtx, vars))
		return (False);
	if ((y - 1) >= 1)
	{
		if (map_check_route_sub(x, (y - 1), mtx, vars))
			return (True);
	}
	if ((y + 1) < vars->num_map - 1)
	{
		if (map_check_route_sub(x, (y + 1), mtx, vars))
			return (True);
	}
	if ((x - 1) >= 1)
	{
		if (map_check_route_sub((x - 1), y, mtx, vars))
			return (True);
	}
	if ((x + 1) < vars->w - 1)
	{
		if (map_check_route_sub((x + 1), y, mtx, vars))
			return (True);
	}
	return (False);
}

int	map_check_route(t_vars *vars)
{
	int		r;
	char	*mtx;

	r = False;
	mtx = (char *)malloc(sizeof(char) * vars->size_map);
	if (!mtx)
		return (False);
	ft_memcpy(mtx, vars->mtx, vars->size_map);
	r = map_check_route_sub(vars->x, vars->y, mtx, vars);
	free(mtx);
	return (r);
}
