/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:02:55 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/16 07:16:21 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	ft_random_init(void)
{
	struct timeval	mytime;

	gettimeofday(&mytime, NULL);
	srand(mytime.tv_usec);
}


int	ft_random(int range)
{
	return (rand() % range);
}
