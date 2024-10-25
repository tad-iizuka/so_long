/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:05:48 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/21 18:07:56 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	char	*to;

	to = dst;
	len = 0;
	while (len < dstsize && *to)
	{
		to++;
		len++;
	}
	if (!dst)
	{
		return (ft_strlen(src));
	}
	return (ft_strlcpy(to, src, dstsize - len) + len);
}
