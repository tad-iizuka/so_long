/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_u.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:34:46 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:53:14 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_type_u(va_list *vap, t_pr *pr)
{
	unsigned int	u;

	u = va_arg(*vap, unsigned int);
	ft_putnbr_base_10(u, pr);
}
