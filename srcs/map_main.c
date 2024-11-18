/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:55:45 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 20:17:37 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

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

int	map_main_read(int fd, t_vars *vars)
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

int	map_main(char *path, t_vars *vars)
{
	int		fd;
	int		r;

	r = True;
	if (ft_strnstr(path, ".ber", ft_strlen(path)) == NULL)
		return (print_error(ERR_FILENAME_INVALID));
	errno = 0;
	fd = open(path, O_RDONLY);
	if (errno)
	{
		perror("so_long");
		return (False);
	}
	r = map_main_read(fd, vars);
	close(fd);
	if (!r)
		return (print_error(ERR_FILE_INVALID));
	r &= map_check(vars);
	if (!r)
		map_free(vars);
	return (r);
}
