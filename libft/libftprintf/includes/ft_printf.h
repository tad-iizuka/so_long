/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:53:14 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/03 13:57:13 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdio.h>
# include	<stdlib.h>
# include	<stdarg.h>
# include	<stdbool.h>
# include	<unistd.h>

# define MAX_BUFFER_SIZE 1024

typedef struct s_pr {
	const char	*fmt;
	int			i;
	int			n;
	char		*buffer;
	int			count;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			width;
	int			sharp;
	int			ll;
	int			hh;
	int			prec;
	int			prec_num;
}	t_pr;

typedef struct s_out {
	int		i;
	int		len;
	char	padding;
	char	sign;
	int		plen;
	int		x;
	char	c;
}	t_out;

void	ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_isdigit(int c);
char	*ft_itoa(int n);

void	ft_printf_output(t_pr *pr);
int		ft_printf_istype(int c);
void	ft_printf_type(va_list *vap, t_pr *pr);
void	ft_printf_type_d(va_list *vap, t_pr *pr);
void	ft_printf_type_x(va_list *vap, t_pr *pr);
void	ft_printf_type_u(va_list *vap, t_pr *pr);
void	ft_printf_type_o(va_list *vap, t_pr *pr);
void	ft_printf_type_s(va_list *vap, t_pr *pr);
void	ft_printf_type_c(va_list *vap, t_pr *pr);
void	ft_printf_type_p(va_list *vap, t_pr *pr);
int		ft_printf_percentage(t_pr *pr);
void	ft_printf_plus_minus(t_pr *pr);
void	ft_printf_modifier(t_pr *pr);
void	ft_printf_precision(va_list *vap, t_pr *pr);
void	ft_printf_output_precision_str(t_pr *pr, t_out *out);
void	ft_printf_output_precision_int(t_pr *pr, t_out *out);
void	ft_printf_width(va_list *vap, t_pr *pr);
void	ft_printf_output_width_str(t_pr *pr, t_out *out);
void	ft_printf_output_width_int(t_pr *pr, t_out *out);
void	ft_printf_putchar(t_pr *pr);
void	ft_printf_putbuff(t_pr *pr, char c);
void	ft_printf_putnstr(char *s, int n, t_pr *pr);
void	ft_putnbr_base_10(unsigned long long nbr, t_pr *pr);
void	ft_putnbr_base_16(unsigned long long nbr, t_pr *pr);
void	ft_putnbr_base_16_c(unsigned long long nbr, t_pr *pr);
void	ft_putnbr_base_8(unsigned long long nbr, t_pr *pr);

#endif
