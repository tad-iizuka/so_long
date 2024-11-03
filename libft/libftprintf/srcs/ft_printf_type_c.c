/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:55:40 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:51:58 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_type_c(va_list *vap, t_pr *pr)
{
	char	c;

	c = va_arg(*vap, int);
	ft_printf_putbuff(pr, c);
}
