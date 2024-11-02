# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiizuka <tiizuka@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 18:03:39 by tiizuka           #+#    #+#              #
#    Updated: 2024/10/31 12:41:50 by tiizuka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of target
ifeq		"$(findstring bonus, $(MAKECMDGOALS))" "bonus"
NAME		= checker
else
NAME		= push_swap
endif

HEAD		= ./header
PUSHSWAP	= ./push_swap
CHECKER		= ./checker

# Sources directory
ifeq		"$(findstring bonus, $(MAKECMDGOALS))" "bonus"
SDIR		= bonus
else
SDIR		= srcs
endif

# Libraly and Object diectory
LDIR 		= libft
ODIR 		= objs
CDIR		= common

# Source, object files
LIBFT 		= libft.a
SRCS 		= $(wildcard $(SDIR)/*.c)
COMSRCS 	= $(wildcard $(CDIR)/*.c)

OBJS		= ${patsubst $(SDIR)/%.c, $(ODIR)/%.o, ${SRCS}}
COBJS		= ${patsubst $(CDIR)/%.c, $(ODIR)/%.o, ${COMSRCS}}

			OBJS += ${COBJS}

# Compiler setting
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I ${HEAD}

# Remove command
RM			= rm -f

# Default target
all:		${NAME}

$(NAME) : $(OBJS) $(COBJS) $(LDIR)/$(LIBFT)
			# $(MAKE) -C ./libft
			$(CC) $(OBJS) $(LDIR)/$(LIBFT) $(CFLAGS) -o $(NAME) 

# Rule for compiling source files
$(ODIR):
			mkdir $(ODIR)
$(ODIR)/%.o: $(SDIR)/%.c | $(ODIR)
			$(CC) $(CFLAGS) -c $< -o ${patsubst $(SDIR)/%.o, $(ODIR)/%.o, $@}

$(ODIR)/%.o: $(CDIR)/%.c | $(ODIR)
			$(CC) $(CFLAGS) -c $< -o ${patsubst $(CDIR)/%.o, $(ODIR)/%.o, $@}

$(LDIR)/$(LIBFT):
			make -C $(LDIR) bonus

# Rule for bonus
bonus:		${NAME}

# Rule for cleaning object files
clean:
	rm -fdr $(ODIR)
	make -C $(LDIR) clean

# Rule for full clean
fclean:		clean
			${RM} $(PUSHSWAP)
			${RM} $(CHECKER)
			$(RM) $(LDIR)/$(LIBFT)

# Rule for re-build
re:			fclean all

# Phony targets
.PHONY:		all clean fclean re bonus