/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:45:00 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:51:18 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

static int	ft_ismodifier(int c)
{
	return (\
		c == 'h' || c == 'l' || c == 'j' || \
		c == 'z' || c == 't');
}

void	ft_printf_modifier(t_pr *pr)
{
	while (ft_ismodifier(pr->fmt[pr->i]))
	{
		if (pr->fmt[pr->i] == 'l')
			pr->ll++;
		if (pr->fmt[pr->i] == 'h')
			pr->ll++;
		pr->i++;
	}
}
