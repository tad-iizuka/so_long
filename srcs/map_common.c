/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_common.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:56:12 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 11:59:57 by tiizuka          ###   ########.fr       */
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
			map->num_c++;
		else if (map->map[i] == 'E')
			map->num_e++;
		else if (map->map[i] == 'P')
			map->num_p++;
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
	map->num_c = 0;
	map->num_e = 0;
	map->num_p = 0;
	map_count_type(map);
	return (map);
}
