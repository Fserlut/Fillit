# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/01 13:26:43 by fserlut           #+#    #+#              #
#    Updated: 2019/10/24 14:07:26 by fserlut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	fillit

SRCS = 	main.c \
		validation.c \
		map.c \
		alg.c \
		move.c \
		find_figure.c \

OBJS = 	main.o \
		validation.o \
		map.o \
		alg.o \
		move.o \
		find_figure.o \

FLAGS = -Wall -Wextra -Werror

LIB = make -C libft/

H_DIR = ./

LIB_DIR = ./libft/

all: $(NAME)

$(NAME):
	$(LIB)
	gcc -c $(SRCS) -I $(H_DIR) -I $(LIB_DIR) $(FLAGS)
	gcc $(OBJS) -o $(NAME) -L $(LIB_DIR) -lft

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_DIR)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)
	make fclean -C $(LIB_DIR)

re: fclean all
