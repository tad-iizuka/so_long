/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:47:06 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/21 05:43:48 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dst;
	int		i;

	dst = (char *) NULL;
	if (!s)
		return (dst);
	dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dst)
	{
		i = 0;
		while (s[i])
		{
			dst[i] = (*f)(i, s[i]);
			i++;
		}
		dst[i] = '\0';
	}
	return (dst);
}
