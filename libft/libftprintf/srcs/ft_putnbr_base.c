/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:15:15 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/03 07:57:25 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../includes/ft_printf.h"

void	ft_putnbr_base(unsigned long long nbr, char *base, t_pr *pr)
{
	unsigned long long	base_type;

	base_type = ft_strlen(base);
	// if (nbr < 0)
	// {
	// 	ft_putchar_fd('-', STDOUT_FILENO);
	// 	nbr *= -1;
	// 	pr->n++;
	// }
	if (nbr >= base_type)
	{
		ft_putnbr_base(nbr / base_type, base, pr);
		nbr = nbr % base_type;
	}
	if (nbr < base_type)
	{
		ft_printf_putbuff(pr, base[nbr]);
	}
}

void	ft_putnbr_base_10(unsigned long long nbr, t_pr *pr)
{
	ft_putnbr_base(nbr, "0123456789", pr);
}

void	ft_putnbr_base_16(unsigned long long nbr, t_pr *pr)
{
	if (pr->sharp && nbr != 0)
		ft_printf_putnstr("0x", 2, pr);
	ft_putnbr_base(nbr, "0123456789abcdef", pr);
}

void	ft_putnbr_base_16_c(unsigned long long nbr, t_pr *pr)
{
	if (pr->sharp && nbr != 0)
		ft_printf_putnstr("0X", 2, pr);
	ft_putnbr_base(nbr, "0123456789ABCDEF", pr);
}

void	ft_putnbr_base_8(unsigned long long nbr, t_pr *pr)
{
	if (pr->sharp && nbr != 0)
		ft_printf_putnstr("0", 1, pr);
	ft_putnbr_base(nbr, "01234567", pr);
}
