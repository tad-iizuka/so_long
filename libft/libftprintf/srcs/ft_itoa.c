/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:46:55 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:58:38 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

static int	ft_intlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len += 1;
	else if (n == 0)
		len += 1;
	while (n)
	{
		len += 1;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		len;
	int		sign;

	sign = n;
	len = ft_intlen(n);
	p = (char *)malloc(len);
	if (p)
	{
		p[--len] = '\0';
		if (n == 0)
			p[--len] = '0';
		while (n)
		{
			if (sign < 0)
				p[--len] = '0' - (n % 10);
			else
				p[--len] = '0' + (n % 10);
			n /= 10;
		}
		if (sign < 0)
			p[--len] = '-';
	}
	return (p);
}
