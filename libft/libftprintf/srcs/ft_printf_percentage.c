/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_percentage.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:12:36 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:51:26 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	ft_printf_percentage(t_pr *pr)
{
	if (pr->fmt[pr->i] != '%')
		return (0);
	ft_putchar_fd('%', STDOUT_FILENO);
	pr->i++;
	pr->n++;
	return (1);
}
