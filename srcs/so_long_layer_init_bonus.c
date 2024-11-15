/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_layer_init_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:02:11 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/15 13:58:39 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "../header/so_long.h"

void	create_images_alpha(t_vars *vars)
{
	int		i;
	char	str[6];
	char	*p;

	i = 0;
	while (i < NUM_ALPHA)
	{
		ft_strlcpy(&str[0], "A.xpm", sizeof(str));
		str[0] += i;
		p = ft_strjoin("./xpm/ALPHA/", str);
		if (p)
		{
			create_image_one(vars, vars->imgALPHA, p, i);
			free(p);
		}
		else
			break ;
		i++;
	}
}

void	create_images_num(t_vars *vars)
{
	int		i;
	char	str[6];
	char	*p;

	i = 0;
	while (i < NUM_NUM)
	{
		ft_strlcpy(&str[0], "0.xpm", sizeof(str));
		str[0] += i;
		p = ft_strjoin("./xpm/NUM/", str);
		if (p)
		{
			create_image_one(vars, vars->imgNUM, p, i);
			free(p);
		}
		else
			break ;
		i++;
	}
}
