/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:04:58 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/21 04:54:04 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*to;

	to = dst;
	if (!dst && !src)
		return (dst);
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		to += len - 1;
		src += len - 1;
		while (len--)
			*to-- = *(unsigned char *)src--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
