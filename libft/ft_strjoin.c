/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:45:34 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/17 14:47:24 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		len;

	dst = (char *) NULL;
	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		dst = (char *)malloc(sizeof(char) * len);
		if (dst)
		{
			ft_strlcpy(dst, s1, len);
			ft_strlcat(dst, s2, len);
		}
	}
	return (dst);
}
