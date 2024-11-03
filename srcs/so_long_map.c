/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:55:45 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/03 08:35:53 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	so_long_map_check(char *path)
{
	(void)path;
	return (False);
}

int	so_long_map_read(int fd, t_vars *vars)
{
	int		r;
	char	*str;

	r = True;
	(void)vars;
	while (1)
	{
		str = get_next_line(fd);
		ft_printf("%s", str);
		if (str)
			free(str);
		else
			break ;
	}
	return (r);
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
	int	r;

	(void)vars;
	r = so_long_map_open(path, vars);
	return (r);
}
