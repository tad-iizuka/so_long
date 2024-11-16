/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_init_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/16 12:16:17 by tiizuka          ###   ########.fr       */
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
				create_image_one(vars, vars->imgALPHA, p, i);
			else if (num == NUM_NUM)
				create_image_one(vars, vars->imgNUM, p, i);
			else
				create_image_one(vars, vars->imgSYM, p, i);
			free(p);
		}
		else
			break ;
		i++;
	}
}
