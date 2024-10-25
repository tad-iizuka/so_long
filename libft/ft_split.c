/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:46:34 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/27 13:25:06 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	**ft_split_alloc(char *s, char c)
{
	char	**dst;
	int		len;

	len = 0;
	dst = (char **) NULL;
	while (*s)
	{
		if (*s != c)
		{
			len++;
			while (*s && *s != c)
				s++;
			while (*s && *s == c)
				s++;
		}
		else
			s++;
	}
	dst = (char **)malloc((len + 1) * sizeof(char *));
	return (dst);
}

static char	**ft_split_dealloc(char **dst)
{
	int	i;

	i = 0;
	while (dst && dst[i])
	{
		free(dst[i]);
		i++;
	}
	free(dst);
	return (NULL);
}

static char	**ft_split_store(char **dst, char const *s, char c)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			p = ft_substr(s, 0, len);
			if (!p)
				return (ft_split_dealloc(dst));
			dst[i++] = p;
			s += len;
		}
		else
			s++;
	}
	dst[i] = (char *) NULL;
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;

	if (s == NULL)
		return (NULL);
	dst = ft_split_alloc((char *)s, c);
	if (!dst)
		return (NULL);
	dst[0] = (char *) NULL;
	dst = ft_split_store(dst, s, c);
	return (dst);
}
