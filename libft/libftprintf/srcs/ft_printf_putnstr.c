/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnstr.C                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:50:49 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:51:44 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_putnstr(char *s, int n, t_pr *pr)
{
	int	i;

	i = 0;
	while (n > i)
	{
		ft_printf_putbuff(pr, s[i]);
		i++;
	}
}
