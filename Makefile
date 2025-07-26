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

CC = cc

CFLAGS = -Wall -Wextra -Werror

CFILES = \
	main.c 

OFILES = $(CFILES:.c=.o)

NAME = fractol.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean 
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
