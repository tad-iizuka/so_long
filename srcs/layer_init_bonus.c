/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layer_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 12:01:40 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	create_images_alnum(t_vars *vars, char *name, char *path, int num)
{
	int		i;
	char	str[6];
	char	*p;

	i = 0;
	while (i < num)
	{
		ft_strlcpy(&str[0], name, sizeof(str));
		str[0] += i;
		p = ft_strjoin(path, str);
		if (p)
		{
			if (num == NUM_ALPHA)
				create_image_one(vars, vars->img_alpha, p, i);
			else if (num == NUM_NUM)
				create_image_one(vars, vars->img_num, p, i);
			else
				create_image_one(vars, vars->img_sym, p, i);
			free(p);
		}
		else
			break ;
		i++;
	}
}
