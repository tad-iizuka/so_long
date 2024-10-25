/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:50:36 by tiizuka           #+#    #+#             */
/*   Updated: 2024/03/29 11:25:05 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lp;

	while (lst && *lst)
	{
		lp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = lp;
	}
}
