/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 12:06:18 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:51:41 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_putchar(t_pr *pr)
{
	ft_putchar_fd(pr->fmt[pr->i], STDOUT_FILENO);
	pr->i++;
	pr->n++;
}
