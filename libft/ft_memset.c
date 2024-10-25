/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:03:50 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/21 04:57:00 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*to;

	to = (unsigned char *)b;
	while (len--)
		*to++ = (unsigned char)c;
	return (b);
}
