/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:18:34 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 15:16:10 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

int	print_error(char *str)
{
	if (str)
		ft_putstr_fd(str, STDERR_FILENO);
	return (False);
}
