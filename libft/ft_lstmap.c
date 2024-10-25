/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:33:31 by tiizuka           #+#    #+#             */
/*   Updated: 2024/03/29 11:27:23 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lp;
	t_list	*temp;

	lp = (t_list *) NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (temp)
		{
			ft_lstadd_back(&lp, temp);
			lst = lst->next;
		}
		else
		{
			ft_lstclear(&lp, del);
			lp = (t_list *) NULL;
			break ;
		}
	}
	return (lp);
}
