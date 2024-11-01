/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:22:09 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/01 21:14:02 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

void	ft_print_utime(char *id)
{
	// (void)id;
	struct timeval	mytime;
	struct tm		*time_st;
	static int		sec;
	// static size_t	usec;
	static int 		counter;
	// const char		week[7][4] = {
	// 	"Sun",
	// 	"Mon",
	// 	"Tue",
	// 	"Wed",
	// 	"Thu",
	// 	"Fri",
	// 	"Sat"
	// };
	(void)id;
	gettimeofday(&mytime, NULL);
	time_st = localtime(&mytime.tv_sec);
	if (sec != time_st->tm_sec)
	{
		sec = time_st->tm_sec;
		printf("[%02d]: %04d\n", sec, counter);
		counter = 0;
	}
	else
	{
		counter++;
	}
}
