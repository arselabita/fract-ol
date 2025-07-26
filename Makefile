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