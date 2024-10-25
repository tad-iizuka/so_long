/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:45:19 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/21 05:44:37 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dst;
	int				i;
	unsigned int	size;

	dst = (char *) NULL;
	if (!s)
		return (dst);
	size = ft_strlen(s);
	if (size < start)
		len = 0;
	if ((size - start) < len)
		len = size - start;
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst)
	{
		i = 0;
		while (len-- && s[start + i])
		{
			dst[i] = s[start + i];
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
