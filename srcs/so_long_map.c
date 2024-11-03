/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:55:45 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/03 12:30:32 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

char	*ft_strrpc(char *s, int c)
{
	char	*p;

	p = s;
	while (*s)
	{
		if (*s == (char)c)
			*s = '\0';
		s++;
	}
	return (p);
}

t_map	*create_map(char *str, t_vars *vars)
{
	int		i;
	t_map	*map;
	t_map	**m;
	t_map	**p;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = ft_strrpc(str, '\n');
	map->x = ft_strlen(str);
	map->num_0 = 0;
	map->num_1 = 0;
	map->num_C = 0;
	map->num_E = 0;
	map->num_P = 0;
	i = 0;
	while (map->x > i)
	{
		if (str[i] == '0')
			map->num_0++;
		else if (str[i] == '1')
			map->num_1++;
		else if (str[i] == 'C')
			map->num_C++;
		else if (str[i] == 'E')
			map->num_E++;
		else if (str[i] == 'P')
			map->num_P++;
		i++;
	}
	p = vars->map;
	m = (t_map **)malloc(sizeof(t_map *) * (vars->num_map + 1));
	vars->map = m;
	i = 0;
	while (vars->num_map > i)
	{
		vars->map[i] = p[i];
		i++;
	}
	vars->map[i] = map;
	vars->num_map++;
	if (p)
		free(p);
	return (map);
}

int	so_long_map_read(int fd, t_vars *vars)
{
	char	*str;
	int		i;

	while (1)
	{
		str = get_next_line(fd);
		if (str)
			create_map(str, vars);
		else
			break ;
	}
	i = 0;
	while (vars->num_map > i)
	{
		ft_printf("map [%s]\n", vars->map[i]->map);
		ft_printf("x [%d]\n", vars->map[i]->x);
		ft_printf("0 [%d]\n", vars->map[i]->num_0);
		ft_printf("1 [%d]\n", vars->map[i]->num_1);
		ft_printf("C [%d]\n", vars->map[i]->num_C);
		ft_printf("E [%d]\n", vars->map[i]->num_E);
		ft_printf("P [%d]\n\n", vars->map[i]->num_P);
		i++;
	}
	return (vars->map != NULL);
}

int	so_long_map_open(char *path, t_vars *vars)
{
	int		fd;
	int		r;

	r = True;
	errno = 0;
	fd = open(path, O_RDONLY);
	if (errno)
	{
		perror("so_long");
		return (False);
	}
	r = so_long_map_read(fd, vars);
	close(fd);
	return (r);
}

int	so_long_map(char *path, t_vars *vars)
{
	return (so_long_map_open(path, vars));
}
