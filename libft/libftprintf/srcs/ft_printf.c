/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:51:46 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/05 16:56:56 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

static void	ft_printf_alloc(const char *fmt, t_pr *pr)
{
	char	*p;

	pr->fmt = fmt;
	pr->n = 0;
	pr->i = 0;
	p = (char *)malloc(MAX_BUFFER_SIZE * sizeof(char));
	if (p)
		pr->buffer = p;
}

static void	ft_printf_init(t_pr *pr)
{
	pr->ll = 0;
	pr->hh = 0;
	pr->width = 0;
	pr->zero = false;
	pr->prec = false;
	pr->prec_num = 0;
	pr->minus = false;
	pr->plus = false;
	pr->i++;
	pr->count = 0;
	pr->space = false;
	pr->sharp = false;
}

static void	ft_printf_format(va_list *vap, t_pr *pr)
{
	while (pr->fmt[pr->i] && ft_printf_istype(pr->fmt[pr->i]) == 0)
	{
		ft_printf_plus_minus(pr);
		ft_printf_width(vap, pr);
		ft_printf_modifier(pr);
		ft_printf_precision(vap, pr);
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list	vap;
	t_pr	pr;

	ft_printf_alloc(fmt, &pr);
	va_start(vap, fmt);
	while (fmt[pr.i])
	{
		if (fmt[pr.i] && fmt[pr.i] == '%')
		{
			ft_printf_init(&pr);
			if (ft_printf_percentage(&pr))
				continue ;
			ft_printf_format(&vap, &pr);
			ft_printf_type(&vap, &pr);
			ft_printf_output(&pr);
		}
		else
			ft_printf_putchar(&pr);
	}
	va_end(vap);
	if (pr.buffer)
		free(pr.buffer);
	return (pr.n);
}
