# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpan <lpan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/10 18:26:42 by lpan              #+#    #+#              #
#    Updated: 2019/05/11 00:30:55 by lpan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lpan.filler

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g3 #-fsanitize=address

SRC = main.c\
	parse_info_piece.c\
	player.c\
	place.c\
	checkplace.c\
	utilities.c\
	free_var_arr.c

OBJ = $(patsubst %.c, %.o, $(SRC))

HEADER = ./libft/libft.h \
		./includes/filler.h

INCLUDE_PATH = -I libft -I includes

$(NAME) : ./libft/libft.a $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L ./libft -lft

./libft/libft.a : 
	make -C libft

all : $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< $(INCLUDE_PATH)

clean :
	rm -f $(OBJ)
	make -C ./libft/ clean

fclean : clean
	make -C ./libft/ fclean
	rm -f $(NAME)

re : all
	make re -C ./libft/
	

.PHONY : all clean fclean re
