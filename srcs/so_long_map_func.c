/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:48:10 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/12 12:25:55 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

int	map_to_mtx(t_vars *vars)
{
	int		i;
	int		w;
	char	*mtx;

	i = 0;
	w = 0;
	while (vars->num_map > i)
		w += vars->map[i++]->x;
	mtx = (char *)malloc(sizeof(char) * w);
	if (!mtx)
		return (False);
	vars->mtx = mtx;
	i = 0;
	while (vars->num_map > i)
	{
		ft_memcpy(mtx, vars->map[i]->map, vars->map[i]->x);
		mtx += vars->map[i]->x;
		i++;
	}
	return (True);
}

void	map_free(t_vars *vars)
{
	int	i;
	t_img *img;

	i = 0;
	while (vars->num_map > i)
	{
		free(vars->map[i]->map);
		free(vars->map[i++]);
	}
	if (vars->map)
		free(vars->map);
	if (vars->mtx)
		free(vars->mtx);
	if (vars->texture)
		free(vars->texture);
	if (vars->img0[0])
	{
		img = vars->img0[0];
		free(img->image);
		free(img);
	}

	while (i < 10)
	{
		if (vars->img1[i])
		{
			img = vars->img1[i];
			free(img->image);
			free(img);
		}
		if (vars->imgC[i])
		{
			img = vars->imgC[i];
			free(img->image);
			free(img);
		}
		if (vars->imgP[i])
		{
			img = vars->imgP[i];
			free(img->image);
			free(img);
		}
		if (vars->imgE[i])
		{
			img = vars->imgE[i];
			free(img->image);
			free(img);
		}
		i++;
	}
	vars->map = NULL;
	vars->num_map = 0;
	vars->mtx = NULL;
}

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

static void	map_count_type(t_map *map)
{
	int	i;

	i = 0;
	while (map->x > i)
	{
		if (map->map[i] == '0')
			map->num_0++;
		else if (map->map[i] == '1')
			map->num_1++;
		else if (map->map[i] == 'C')
			map->num_C++;
		else if (map->map[i] == 'E')
			map->num_E++;
		else if (map->map[i] == 'P')
			map->num_P++;
		i++;
	}
}

t_map	*map_new(char *str)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = str;
	map->x = ft_strlen(str);
	map->num_0 = 0;
	map->num_1 = 0;
	map->num_C = 0;
	map->num_E = 0;
	map->num_P = 0;
	map_count_type(map);
	return (map);
}
