/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:55 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/14 16:17:44 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

int	ft_random(int range)
{
	struct timeval	mytime;

	gettimeofday(&mytime, NULL);
	return (mytime.tv_usec % range);
}
