/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:13:44 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:53:27 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_type(va_list *vap, t_pr *pr)
{
	char	c;

	c = pr->fmt[pr->i];
	if (!ft_printf_istype(c))
		return ;
	if (c == 'd' || c == 'i')
		ft_printf_type_d(vap, pr);
	else if (c == 'x' || c == 'X')
		ft_printf_type_x(vap, pr);
	else if (c == 'u')
		ft_printf_type_u(vap, pr);
	else if (c == 'o')
		ft_printf_type_o(vap, pr);
	else if (c == 's')
		ft_printf_type_s(vap, pr);
	else if (c == 'c')
		ft_printf_type_c(vap, pr);
	else if (c == 'p')
		ft_printf_type_p(vap, pr);
	pr->i++;
	return ;
}
