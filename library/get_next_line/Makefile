# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/29 13:56:15 by tatashir          #+#    #+#              #
#    Updated: 2023/04/21 21:41:54 by tatashir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libgnl.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= ./
SRCS		= get_next_line.c \
			get_next_line_utils.c
OBJS	= ${SRCS:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re
