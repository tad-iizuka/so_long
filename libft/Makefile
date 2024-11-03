# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 20:16:08 by tiizuka           #+#    #+#              #
#    Updated: 2024/11/03 14:47:43 by tiizuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of target
NAME		= libft.a

LPRINTF		= ./libftprintf

# Name of srcs
SRCS		= \
			ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
			ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c \
			ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c \
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_tolower.c ft_toupper.c \
			\
			ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_putstr_fd.c ft_split.c ft_striteri.c ft_strjoin.c ft_strmapi.c \
			ft_strtrim.c ft_substr.c

BSRCS		= \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c \

GSRCS		= get_next_line/get_next_line.c

OBJS		= ${SRCS:.c=.o}
BOBJS		= ${BSRCS:.c=.o}
GOBJS		= ${GSRCS:.c=.o}
			OBJS += $(GOBJS)

ifeq		"$(findstring bonus, $(MAKECMDGOALS))" "bonus"
			OBJS += $(BOBJS)
endif

# Compiler setting
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Archive and remove command
AR			= ar rcs
RM			= rm -f

# Default target
all:		${NAME}

${NAME}:	${OBJS}
			$(MAKE) -C ${LPRINTF}
			${AR} ${NAME} ${OBJS}

# Rule for bonus
bonus:		all

# Rule for cleaning object files
clean:
			$(MAKE) -C ${LPRINTF} clean
ifneq ("$(wildcard $(OBJS)/*.o)", "")
			${RM} ${OBJS}
endif
ifneq ("$(wildcard $(BOBJS)/*.o)", "")
			${RM} ${BOBJS}
endif
# Rule for full clean
fclean:		clean
ifneq ("$(wildcard $(NAME))", "")
			${RM} ${NAME}
endif
			$(MAKE) -C ${LPRINTF} fclean

# Rule for re-build
re:			fclean all

# Phony targets
.PHONY:		all clean fclean re bonus
