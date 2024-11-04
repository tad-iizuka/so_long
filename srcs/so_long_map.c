/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:55:45 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/04 07:38:19 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	map_read_debug(t_vars *vars)
{
	int	i;

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
}

t_map	*create_map(char *str, t_vars *vars)
{
	int		i;
	t_map	*map;
	t_map	**m;
	t_map	**p;

	map = map_new(str);
	if (!map)
		return (NULL);
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
		if (!str)
			break ;
		i = 0;
		while (str[i])
		{
			if (str[i] == '\n')
				str[i] = '\0';
			i++;
		}
		if (!create_map(str, vars))
			return (False);
	}
	return (vars->map != NULL);
}

int	so_long_map(char *path, t_vars *vars)
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
	r &= map_check_main(vars);
	if (!r)
		map_free(vars);
	return (r);
}
