# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/14 19:45:34 by tiizuka           #+#    #+#              #
#    Updated: 2024/11/03 13:59:44 by tiizuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of target
NAME		= libftprintf.a

# Name of srcs/includes
SRCDIR = srcs
INCDIR = includes

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(SRCDIR)/%.o)

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

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@if [ ! -d "$(SRCDIR)" ]; then mkdir $(SRCDIR); fi
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

# Rule for bonus
bonus:		all

# Rule for cleaning object files
clean:
			${RM} ${OBJS}

# Rule for full clean
fclean:		clean
			${RM} ${NAME}

# Rule for re-build
re:			fclean all

# Phony targets
.PHONY:		all clean fclean re bonus
