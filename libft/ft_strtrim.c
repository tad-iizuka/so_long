/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:46:39 by tiizuka           #+#    #+#             */
/*   Updated: 2024/04/17 15:01:06 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dst;
	int		len;
	int		start;
	int		end;

	dst = (char *) NULL;
	if (s1 && set)
	{
		len = ft_strlen(s1);
		start = 0;
		while (start < len && ft_strchr(set, *(s1 + start)))
			start++;
		end = len;
		while (end > start && ft_strchr(set, *(s1 + end - 1)))
			end--;
		dst = ft_substr(s1, start, end - start);
	}
	return (dst);
}
