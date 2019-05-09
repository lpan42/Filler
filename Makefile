NAME = filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c	parse_info_piece.c	player_o.c	place_o.c	player_x.c	place_x.c checkplace.c\

OBJ = $(SRC:.c=.o)

$(NAME) :
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o filler

all : $(NAME)

clean :
	rm -f $(OBJ)
	make -C libft/ clean

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
