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
CFLAGS = -Wall -Wextra -Werror -fsanitize=address,leak,undefined -g3

# executable name
NAME = fractol
LIBFT = libft/libft.a
# source to bject files
CFILES = \
	main.c \
	input_validity.c \
	mandelbrot.c \
	julia.c \
	multibrot.c \
	mlx_window.c \
	mlx_utils.c \
	utils.c

OFILES = $(CFILES:.c=.o)

# MLX and math libraries
LIBS = -lmlx -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) $(LIBS) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OFILES)
	make -C libft clean

fclean: clean 
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
