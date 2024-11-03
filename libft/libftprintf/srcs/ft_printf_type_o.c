/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:39:28 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:52:39 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_type_o(va_list *vap, t_pr *pr)
{
	unsigned long long	x;

	x = va_arg(*vap, unsigned long long);
	ft_putnbr_base_8(x, pr);
}
