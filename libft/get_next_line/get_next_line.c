/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:05:08 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/03 13:20:50 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	i = 0;
	while ((from[i] != 0) && i < n)
	{
		to[i] = from[i];
		i++;
	}
	while (i < n)
	{
		to[i] = 0;
		i++;
	}
	return (dest);
}

char	*dequeue(char *p, char **bp)
{
	int		size;
	char	*deqp;
	char	*lp;

	lp = (char *) NULL;
	size = p - *bp;
	deqp = *bp;
	lp = ft_calloc(1, size + 2);
	if (lp)
	{
		ft_strncpy(lp, *bp, size + 1);
		size = ft_strlen(p + 1);
	}
	if (lp && size)
	{
		*bp = ft_calloc(1, size + 1);
		if (*bp)
			ft_strncpy(*bp, (p + 1), size);
	}
	else
		*bp = (char *) NULL;
	free(deqp);
	return (lp);
}

char	*enqueue(char *p, int size, char **bp)
{
	char	*enqp;
	char	*lp;

	lp = (char *) NULL;
	if (!*bp)
	{
		*bp = ft_calloc(1, size + 1);
		if (!*bp)
			return (lp);
		ft_strncpy(*bp, p, size);
	}
	else
	{
		enqp = *bp;
		*bp = ft_strjoin(*bp, p);
		if (enqp)
			free(enqp);
	}
	enqp = ft_strchr(*bp, '\n');
	if (enqp)
		lp = dequeue(enqp, bp);
	return (lp);
}

char	*next_read(int fd, char *p, char **bp)
{
	int		size;
	char	*lp;

	lp = (char *) NULL;
	while (1)
	{
		size = read(fd, p, BUFFER_SIZE);
		if (size <= 0)
			break ;
		lp = enqueue(p, size, bp);
		if (lp)
			break ;
		while (size--)
			p[size] = 0;
	}
	if (!lp && *bp)
	{
		size = ft_strlen(*bp);
		lp = ft_calloc(1, size + 1);
		if (lp)
			ft_strncpy(lp, *bp, size);
		free(*bp);
		*bp = (char *) NULL;
	}
	return (lp);
}

char	*get_next_line(int fd)
{
	static char	*bp;
	char		*lp;
	char		*p;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return ((char *) NULL);
	lp = (char *) NULL;
	if (bp)
		p = ft_strchr(bp, '\n');
	if (bp && p)
		lp = dequeue(p, &bp);
	else
	{
		p = ft_calloc(1, BUFFER_SIZE + 1);
		if (p)
		{
			lp = next_read(fd, p, &bp);
			free(p);
		}
	}
	return (lp);
}
