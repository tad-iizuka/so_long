# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 18:03:39 by tiizuka           #+#    #+#              #
#    Updated: 2024/10/25 18:09:02 by tiizuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of target
NAME		= so_long
HEAD		= ./header
LIBX		= ./minilibx-linux

# Sources directory
ifeq		"$(findstring bonus, $(MAKECMDGOALS))" "bonus"
SDIR		= bonus
else
SDIR		= srcs
endif

# Libraly and Object diectory
LDIR 		= ./libft
ODIR 		= objs

# Source, object files
SRCS 		= $(wildcard $(SDIR)/*.c)
LIBSRCS 	= $(wildcard $(LDIR)/*.c)

OBJS		= ${patsubst $(SDIR)/%.c, $(ODIR)/%.o, ${SRCS}}
LOBJS		= ${patsubst $(LDIR)/%.c, $(LDIR)/%.o, ${LIBSRCS}}

# Compiler setting
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I ${HEAD}

# Remove command
RM			= rm -f

# Rule for compiling source files
$(ODIR)/%.o: $(SDIR)/%.c
			@if [ ! -d "$(ODIR)" ]; then mkdir $(ODIR); fi
			$(CC) $(CFLAGS) -c $< -o ${patsubst $(SDIR)/%.o, $(ODIR)/%.o, $@}

$(LDIR)/%.o: $(LDIR)/%.c
			$(CC) $(CFLAGS) -c $< -o ${patsubst $(LDIR)/%.o, $(LDIR)/%.o, $@}

# Default target
all:		${NAME}

$(NAME) : $(OBJS) $(LOBJS)
			$(MAKE) -C $(LDIR)
			$(MAKE) -C $(LIBX)
			$(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LDIR)/*.a $(LIBX)/*.a -lXext -lX11

# Rule for bonus
bonus:		${NAME}

# Rule for cleaning object files
clean:
ifneq ("$(wildcard $(ODIR)/*.o)", "")
			${RM} $(wildcard $(ODIR)/*.o)
endif
ifneq ("$(wildcard $(LDIR)/*.o)", "")
			$(MAKE) -C $(LDIR) clean
			${RM} $(wildcard $(LDIR)/*.a)
endif
ifneq ("$(wildcard $(LIBX)/obj/*.o)", "")
			$(MAKE) -C $(LIBX) clean
endif
			

# Rule for full clean
fclean:		clean
ifneq ("$(wildcard $(NAME))", "")
			${RM} $(NAME)
endif

# Rule for re-build
re:			fclean all

# Phony targets
.PHONY:		all clean fclean re bonus
