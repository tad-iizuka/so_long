/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 09:53:45 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/06 10:23:25 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_output_precision_str(t_pr *pr, t_out *out)
{
	if (!pr->prec)
		return ;
	if ((pr->prec_num == 0 && *pr->buffer == '0') \
		|| (out->c == 's' && pr->prec_num == 0))
	{
		out->len = 0;
		pr->n -= pr->count;
	}
	else if (pr->prec_num != 0 && pr->count > pr->prec_num && \
		!(out->c == 'x' || out->c == 'X'))
	{
		out->len = pr->prec_num;
		pr->n -= pr->count - pr->prec_num;
	}
	else if (pr->prec_num != 0 && pr->count == 0)
		out->len = 0;
	else if (pr->prec_num != 0 \
		&& pr->count < pr->prec_num && out->c != 's')
	{
		out->padding = '0';
		pr->n += pr->prec_num - pr->count;
		out->plen = pr->prec_num - pr->count;
	}
}

void	ft_printf_output_precision_int(t_pr *pr, t_out *out)
{
	if (pr->prec)
	{
		out->x = pr->count;
		if (pr->buffer[0] == '-')
			out->x--;
		if (out->x < pr->prec_num)
		{
			out->i = pr->prec_num - out->x;
			while (out->i--)
			{
				out->padding = '0';
				out->plen++;
				pr->n++;
			}
		}
		else if (pr->prec_num == 0 && pr->buffer[0] == '0' \
			&& pr->count == 1)
		{
			out->len = 0;
			pr->n--;
		}
	}
}

void	ft_printf_precision(va_list *vap, t_pr *pr)
{
	if (pr->fmt[pr->i] != '.')
		return ;
	pr->i++;
	if (pr->fmt[pr->i] == '*')
	{
		pr->prec_num = va_arg(*vap, int);
		pr->i++;
	}
	else if (ft_isdigit(pr->fmt[pr->i]))
	{
		while (ft_isdigit(pr->fmt[pr->i]))
		{
			pr->prec_num = (pr->prec_num * 10) + pr->fmt[pr->i] - '0';
			pr->i++;
		}
	}
	pr->prec = true;
}
