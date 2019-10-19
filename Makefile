# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 14:46:22 by fserlut           #+#    #+#              #
#    Updated: 2019/10/19 17:19:12 by fserlut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

NAME_LIB = libft.a

NAME_FILE = ./*.c

SRC = ./libft/*.c

FILE_O = ./*.o

HEAD_FOLDER = ./libft

FLAGC = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -I $(HEAD_FOLDER) -c $(SRC) $(FLAGC)
	ar rc $(NAME_LIB) $(FILE_O)
	ranlib $(NAME_LIB)
	gcc $(FLAGC) -c $(NAME_FILE)
	gcc ./$(NAME_LIB) ./$(FILE_O) -o $(NAME)

clean:
	/bin/rm -f *.o
	/bin/rm -f *.o~
	/bin/rm -f *.h~
	/bin/rm -f *.c~

fclean: clean
	/bin/rm -rf $(NAME_LIB) $(NAME) *~ 

re: fclean all