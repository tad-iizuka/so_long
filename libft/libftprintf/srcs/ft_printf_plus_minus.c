/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_plus_minus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:18:38 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:51:30 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_plus_minus(t_pr *pr)
{
	while (pr->fmt[pr->i] == '-')
	{
		pr->minus = true;
		pr->i++;
	}
	while (pr->fmt[pr->i] == '+')
	{
		pr->plus = true;
		pr->i++;
	}
	while (pr->fmt[pr->i] == ' ')
	{
		pr->space = true;
		pr->i++;
	}
	while (pr->fmt[pr->i] == '#')
	{
		pr->sharp = true;
		pr->i++;
	}
}
