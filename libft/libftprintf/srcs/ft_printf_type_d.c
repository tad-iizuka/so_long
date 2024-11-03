/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:20:29 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:52:03 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_type_d(va_list *vap, t_pr *pr)
{
	char	*s;
	int		len;

	s = ft_itoa(va_arg(*vap, int));
	if (s)
	{
		len = ft_strlen(s);
		ft_printf_putnstr(s, len, pr);
		free(s);
	}
}
