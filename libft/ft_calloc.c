/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:06:17 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/20 12:53:41 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	len;

	len = count * size;
	if (len != 0 && len / count != size)
		return (NULL);
	p = (void *)malloc(len);
	if (p)
		ft_bzero(p, len);
	return (p);
}
