/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:55:45 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/03 13:29:32 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	so_long_map_check(char *path)
{
	(void)path;
	return (False);
}

int	so_long_map_read(char *path)
{
	int		fd;
	int		r;
	char	*str;

	r = True;
	errno = 0;
	fd = open(path, O_RDONLY);
	if (errno)
	{
		perror("so_long");
		return (False);
	}
	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		if (str)
			free(str);
		else
			break;
	}
	close(fd);
	return (r);
}

int	so_long_map(char *path, t_vars *vars)
{
	int	r;

	(void)vars;
	r = so_long_map_read(path);
	return (r);
}
