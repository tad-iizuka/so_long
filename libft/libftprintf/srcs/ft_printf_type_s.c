/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:52:40 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:53:10 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_type_s(va_list *vap, t_pr *pr)
{
	char	*s;
	int		len;

	s = va_arg(*vap, char *);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	ft_printf_putnstr(s, len, pr);
}
