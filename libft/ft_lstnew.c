/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:49:39 by tiizuka           #+#    #+#             */
/*   Updated: 2024/03/27 18:41:06 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lp;

	lp = (t_list *)malloc(sizeof(t_list));
	if (lp)
	{
		lp->content = content;
		lp->next = (t_list *) NULL;
	}
	return (lp);
}
