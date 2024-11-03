/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 11:55:51 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/06 10:22:44 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_output_width_str(t_pr *pr, t_out *out)
{
	if (pr->width && pr->width > pr->count)
	{
		out->i = pr->width - pr->count;
		while (out->i-- > 0)
		{
			if (pr->zero)
				out->padding = '0';
			else
				out->padding = ' ';
			out->plen++;
			pr->n++;
		}
	}
}

void	ft_printf_output_width_int(t_pr *pr, t_out *out)
{
	if (pr->width && pr->width > 1)
	{
		if (pr->count > pr->prec_num)
			out->i = pr->width - pr->count;
		else
			out->i = pr->width - pr->prec_num;
		while (out->i-- > 0)
		{
			out->padding = ' ';
			if (pr->zero && !pr->minus)
				out->padding = '0';
			out->plen++;
			pr->n++;
		}
	}
}

void	ft_printf_width(va_list *vap, t_pr *pr)
{
	if (ft_isdigit(pr->fmt[pr->i]))
	{
		while (ft_isdigit(pr->fmt[pr->i]))
		{
			if (pr->fmt[pr->i] == '0' && pr->width == 0)
				pr->zero = 1;
			else
				pr->width = (pr->width * 10) + (pr->fmt[pr->i] - '0');
			pr->i++;
		}
	}
	else if (pr->fmt[pr->i] == '*')
	{
		pr->width = va_arg(*vap, int);
		if (pr->width < 0)
		{
			pr->width *= -1;
			pr->minus = true;
		}
		pr->i++;
	}
}
