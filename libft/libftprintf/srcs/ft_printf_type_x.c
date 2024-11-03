/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:29:20 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:53:19 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_type_x(va_list *vap, t_pr *pr)
{
	unsigned long long	x;

	if (pr->ll)
		x = va_arg(*vap, unsigned long);
	else
		x = va_arg(*vap, unsigned int);
	if (pr->fmt[pr->i] == 'X')
		ft_putnbr_base_16_c(x, pr);
	else
		ft_putnbr_base_16(x, pr);
}
