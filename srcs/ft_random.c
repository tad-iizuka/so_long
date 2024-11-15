/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:55 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/15 00:46:52 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:22:09 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/12 11:09:46 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	ft_print_utime(char *id)
{
	struct timeval	mytime;
	struct tm		*time_st;
	const char		week[7][4] = {
		"Sun",
		"Mon",
		"Tue",
		"Wed",
		"Thu",
		"Fri",
		"Sat"
	};

	gettimeofday(&mytime, NULL);
	time_st = localtime(&mytime.tv_sec);
	printf("[%s] %d/%02d/%02d(%s) %02d:%02d:%02d.%06zu\n", \
		id, \
		time_st->tm_year + 1900, \
		time_st->tm_mon + 1, \
		time_st->tm_mday, \
		week[time_st->tm_wday], \
		time_st->tm_hour, \
		time_st->tm_min, \
		time_st->tm_sec, \
		mytime.tv_usec
		);
}

int	ft_random(int range)
{
	struct timeval	mytime;

	gettimeofday(&mytime, NULL);
	return (mytime.tv_usec % range);
}
