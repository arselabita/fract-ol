# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abita <abita@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/26 20:58:59 by abita             #+#    #+#              #
#    Updated: 2025/07/26 21:09:00 by abita            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# the compiler flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

# executable name
NAME = fractol

# source to bject files
CFILES = \
	main.c input_validity.c mandelbrot.c julia.c window.c
OFILES = $(CFILES:.c=.o)

# MLX and math libraries
LIBS = -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIBS)

clean:
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
