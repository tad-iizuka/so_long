/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:57:51 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:52:55 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_type_p(va_list *vap, t_pr *pr)
{
	unsigned long long	x;

	x = va_arg(*vap, unsigned long long);
	ft_printf_putnstr("0x", 2, pr);
	ft_putnbr_base_16(x, pr);
}
