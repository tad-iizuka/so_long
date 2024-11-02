/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utime.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:22:09 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/02 13:04:22 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"so_long.h"

// void	ft_print_utime(char *id)
// {
// 	// (void)id;
// 	struct timeval	mytime;
// 	struct tm		*time_st;
// 	const char		week[7][4] = {
// 		"Sun",
// 		"Mon",
// 		"Tue",
// 		"Wed",
// 		"Thu",
// 		"Fri",
// 		"Sat"
// 	};

// 	gettimeofday(&mytime, NULL);
// 	time_st = localtime(&mytime.tv_sec);
// 	printf("[%s] %d/%02d/%02d(%s) %02d:%02d:%02d.%06zu\n", \
// 		id, \
// 		time_st->tm_year + 1900, \
// 		time_st->tm_mon + 1, \
// 		time_st->tm_mday, \
// 		week[time_st->tm_wday], \
// 		time_st->tm_hour, \
// 		time_st->tm_min, \
// 		time_st->tm_sec, \
// 		mytime.tv_usec
// 		);
// }

void	ft_print_utime(char *id)
{
	// (void)id;
	struct timeval	mytime;
	struct tm		*time_st;
	static int		sec;
	static size_t	usec;
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
		usec = mytime.tv_usec;
	}
	else
	{
		// printf("[%zu]\n", mytime.tv_usec - usec);
		usec = mytime.tv_usec;
		counter++;
	}
}

