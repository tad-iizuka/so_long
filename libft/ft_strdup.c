/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:06:49 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/21 04:58:29 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*p;

	len = ft_strlen(src) + 1;
	p = (char *)malloc(len);
	if (p)
		ft_memcpy(p, src, len);
	return (p);
}
