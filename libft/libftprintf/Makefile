# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 19:45:34 by tiizuka           #+#    #+#              #
#    Updated: 2024/11/03 14:45:10 by tiizuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of target
NAME		= libftprintf.a

# Name of srcs/includes
SDIR 		= srcs
HEAD 		= includes

SRCS 		= $(wildcard $(SDIR)/*.c)
OBJS		= ${patsubst $(SDIR)/%.c, $(SDIR)/%.o, ${SRCS}}

# Compiler setting
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Archive and remove command
AR			= ar rcs
RM			= rm -f

# Default target
all:		${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			mv *.a ../

$(SDIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -I$(HEAD) -c $< -o $@

# Rule for bonus
bonus:		all

# Rule for cleaning object files
clean:
ifneq ("$(wildcard $(OBJS)/*.o)", "")
			${RM} ${OBJS}
endif
# Rule for full clean
fclean:		clean
ifneq ("$(wildcard ../$(NAME))", "")
			${RM} ../${NAME}
endif

# Rule for re-build
re:			fclean all

# Phony targets
.PHONY:		all clean fclean re bonus
