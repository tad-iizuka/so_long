/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiizuka <tiizuka@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:19:56 by tiizuka           #+#    #+#             */
/*   Updated: 2024/11/18 15:22:36 by tiizuka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ERROR_H
# define  SO_LONG_ERROR_H

# define ERR_COLLECTIBLE "Map: Not contain at least one 'C'\n"
# define ERR_EXIT "Map: Not contain/more than 1 'E'\n"
# define ERR_PLAYER "Map: Not contain/more than 1 'P'\n"
# define ERR_INVALID_CHAR "Map: Contained invalid character.\n"

# define ERR_NOT_RECTANGLE "Map: Not rectangular.\n"
# define ERR_INVALID_WALL "Map: Not closed/surrounded by walls.\n"
# define ERR_INVALID_PATH "Map: Not contained valid path.\n"

#endif
