/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:06:01 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/17 09:54:17 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
		c == '\f' || c == '\r' || c == ' ');
}

static long	ft_atoi_sub(int sign, char *str, unsigned long ulim, int lim)
{
	unsigned long	num;
	int				c;
	int				f;

	f = 0;
	num = 0;
	while (ft_isdigit(*str))
	{
		c = *str++ - '0';
		if (f < 0 || num > ulim || (num == ulim && c > lim))
			f = -1;
		else
		{
			f = 1;
			num = (num * 10) + c;
		}
	}
	if (f < 0)
	{
		num = LONG_MAX;
		if (sign == -1)
			num = LONG_MIN;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	unsigned long	ulim;
	int				lim;
	int				sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	ulim = LONG_MAX;
	if (sign == -1)
		ulim = LONG_MIN;
	lim = ulim % 10;
	ulim /= 10;
	return (ft_atoi_sub(sign, (char *)str, ulim, lim) * sign);
}
