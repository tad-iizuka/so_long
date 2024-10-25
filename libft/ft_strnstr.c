/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:05:37 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/27 13:24:03 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*src;
	size_t	nlen;

	if (!haystack && !len)
		return (NULL);
	src = (char *)haystack;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	while (*src && len-- >= nlen)
	{
		if (ft_strncmp(src, needle, nlen) == 0)
			return (src);
		src++;
	}
	return (NULL);
}
