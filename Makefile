# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 16:03:12 by tatashir          #+#    #+#              #
#    Updated: 2023/04/29 17:39:55 by tatashir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = back_track.c\
	   check_map.c\
	   check_playable.c\
	   close.c \
	   draw_item.c \
	   error.c \
	   file_handling.c \
	   ftprintf.c \
	   hook.c \
	   initialize.c \
	   move.c \
	   so_long.c \

OBJCS = $(SRCS:.c=.o)

PRINTFDIR = ./library/ft_printf

GNLDIR = ./library/get_next_line

FT_PRINTF = -L$(PRINTFDIR) -lftprintf

GNL = -L$(GNLDIR) -lgnl

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJCS)
	$(MAKE) -C ${PRINTFDIR}
	$(MAKE) -C ${GNLDIR}
	$(CC) $(CFLAGS) -o $@ $(OBJCS) $(FT_PRINTF) $(GNL) $(MLX) 

clean:
	rm -f $(OBJCS)
	$(MAKE) -C ${PRINTFDIR} clean
	$(MAKE) -C ${GNLDIR} clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ${PRINTFDIR} fclean
	$(MAKE) -C ${GNLDIR} fclean

re: fclean all

.PHONY: all clean fclean re
