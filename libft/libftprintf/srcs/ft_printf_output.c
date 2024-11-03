/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:33:45 by tiizuka           #+#    #+#             */
/*   Updated: 2024/05/06 10:25:53 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	ft_printf_output_sign(t_pr *pr, t_out *out)
{
	if ((pr->plus || pr->space) && *pr->buffer != '-')
	{
		if (pr->width)
			pr->width -= 1;
		out->sign = '+';
		pr->n++;
		if (pr->space)
			out->sign = ' ';
	}
	else if (*pr->buffer == '-')
		out->sign = '-';
}

void	ft_printf_output_value(t_pr *pr, t_out *out)
{
	int		i;

	i = 0;
	if (out->c == 'd' || out->c == 'i' || out->c == 'u')
		if (pr->buffer[i] == '-')
			i = 1;
	while (out->len > i)
	{
		ft_putchar_fd(pr->buffer[i], STDOUT_FILENO);
		i++;
	}
}

void	ft_printf_output_init(t_pr *pr, t_out *out)
{
	out->len = pr->count;
	out->plen = 0;
	out->padding = 0;
	out->sign = 0;
	out->c = pr->fmt[pr->i - 1];
}

void	ft_printf_output_fd(t_pr *pr, t_out *out)
{
	if (pr->minus)
	{
		if (out->sign)
			ft_putchar_fd(out->sign, STDOUT_FILENO);
		ft_printf_output_value(pr, out);
		while (out->plen > 0)
		{
			ft_putchar_fd(out->padding, STDOUT_FILENO);
			out->plen--;
		}
	}
	else
	{
		if (out->sign && out->padding == '0')
			ft_putchar_fd(out->sign, STDOUT_FILENO);
		while (out->plen > 0)
		{
			ft_putchar_fd(out->padding, STDOUT_FILENO);
			out->plen--;
		}
		if (out->sign && out->padding != '0')
			ft_putchar_fd(out->sign, STDOUT_FILENO);
		ft_printf_output_value(pr, out);
	}
}

void	ft_printf_output(t_pr *pr)
{
	t_out	out;

	ft_printf_output_init(pr, &out);
	if (out.c == 's' || out.c == 'c' || out.c == 'p' \
		|| out.c == 'x' || out.c == 'X')
	{
		ft_printf_output_width_str(pr, &out);
		ft_printf_output_precision_str(pr, &out);
	}
	else if (out.c == 'd' || out.c == 'i' || out.c == 'u')
	{
		ft_printf_output_sign(pr, &out);
		ft_printf_output_width_int(pr, &out);
		ft_printf_output_precision_int(pr, &out);
		if (pr->width && out.len == 0)
		{
			out.padding = ' ';
			out.plen = pr->width;
			pr->n += pr->width;
		}
	}
	ft_printf_output_fd(pr, &out);
}
