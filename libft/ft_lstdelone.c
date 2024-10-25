/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:50:26 by tiizuka           #+#    #+#             */
/*   Updated: 2024/03/28 16:23:30 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != (t_list *) NULL)
	{
		(*del)(lst->content);
		free(lst);
	}
}
