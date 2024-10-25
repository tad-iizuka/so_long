/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:04:45 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/27 13:22:54 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*to;

	if (!dst && !src)
		return (dst);
	to = (unsigned char *)dst;
	if (n == 0)
		return (dst);
	while (n--)
		*to++ = *(unsigned char *)src++;
	return (dst);
}
