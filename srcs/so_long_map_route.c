/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_route.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 06:43:23 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/16 13:52:56 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	map_find_pos(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->num_map > y)
	{
		x = 0;
		while (vars->map[y]->x > x)
		{
			if (vars->map[y]->map[x] == 'P')
			{
				vars->x = x;
				vars->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

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
	int	r;

	r = False;
	if (mtx[(vars->w * y) + x] == 'E')
		return (True);
	else if (!map_check_route_sub_find(x, y, mtx, vars))
		return (False);
	if ((y - 1) >= 1)
		r |= map_check_route_sub(x, (y - 1), mtx, vars);
	if ((y + 1) < vars->num_map - 1)
		r |= map_check_route_sub(x, (y + 1), mtx, vars);
	if ((x - 1) >= 1)
		r |= map_check_route_sub((x - 1), y, mtx, vars);
	if ((x + 1) <= vars->w - 1)
		r |= map_check_route_sub((x + 1), y, mtx, vars);
	return (r);
}

void	map_count_for_wizard(t_vars *vars, char *mtx)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (vars->size_map > i)
	{
		if (mtx[i] == 'x')
			w++;
		i++;
	}
	vars->num_wizard = w;
}

int	map_check_route(t_vars *vars)
{
	int		r;
	char	*mtx;
	int		i;

	r = False;
	mtx = (char *)malloc(sizeof(char) * vars->size_map);
	if (!mtx)
		return (False);
	ft_memcpy(mtx, vars->mtx, vars->size_map);
	r = map_check_route_sub(vars->x, vars->y, mtx, vars);
	i = 0;
	while (vars->size_map > i)
	{
		if (mtx[i] == 'C')
		{
			r = False;
			break ;
		}
		i++;
	}
	if (BONUS)
		map_count_for_wizard(vars, mtx);
	free(mtx);
	return (r);
}
