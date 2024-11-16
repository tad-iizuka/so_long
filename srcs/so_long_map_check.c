/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:07:47 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/16 14:09:07 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../header/so_long.h"

void	map_calc_wizard(t_vars *vars)
{
	int	w;

	w = vars->num_space - vars->num_c;
	vars->num_space = w;
	if (w < 5)
		vars->num_wizard = 1;
	else
		vars->num_wizard = ((w - 5) / 10) + 1;
}

int	map_check_wall(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->num_map > i)
	{
		if (i == 0 || i == vars->num_map - 1)
		{
			if (vars->map[i]->num_1 != vars->map[i]->x)
				return (False);
		}
		else
		{
			if (vars->map[i]->map[0] != '1')
				return (False);
			if (vars->map[i]->map[(vars->map[i]->x - 1)] != '1')
				return (False);
		}
		i++;
	}
	return (True);
}

int	map_check_square(t_vars *vars)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (vars->num_map > i)
		w += vars->map[i++]->x;
	if ((w / vars->num_map) != vars->map[0]->x)
		return (False);
	if ((w % vars->num_map) != 0)
		return (False);
	vars->size_map = w;
	vars->w = vars->map[0]->x;
	return (True);
}

int	map_check_items(t_vars *vars)
{
	int	i;
	int	e;
	int	p;
	int	c;

	i = 0;
	e = 0;
	p = 0;
	c = 0;
	while (vars->num_map > i)
	{
		e += vars->map[i]->num_E;
		p += vars->map[i]->num_P;
		c += vars->map[i]->num_C;
		i++;
	}
	if (e != 1 || p != 1 || c == 0)
		return (False);
	vars->num_c = c;
	return (True);
}

int	map_check_format(t_vars *vars)
{
	int	i;
	int	s;

	i = 0;
	while (vars->num_map > i)
	{
		s = 0;
		s += vars->map[i]->num_0;
		s += vars->map[i]->num_1;
		s += vars->map[i]->num_E;
		s += vars->map[i]->num_P;
		s += vars->map[i]->num_C;
		if (s != vars->w)
			return (False);
		i++;
	}
	return (True);
}

int	map_check_main(t_vars *vars)
{
	int	r;

	r = True;
	r &= map_check_wall(vars);
	r &= map_check_square(vars);
	r &= map_check_items(vars);
	r &= map_check_format(vars);
	if (r)
	{
		map_find_pos(vars);
		map_to_mtx(vars);
		r &= map_check_route(vars);
		if (BONUS && r)
			map_calc_wizard(vars);
	}
	return (r);
}
