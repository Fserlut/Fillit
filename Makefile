# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fserlut <fserlut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 14:46:22 by fserlut           #+#    #+#              #
#    Updated: 2019/10/08 13:43:25 by fserlut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NAME_FILE = ./*.c

SRC = ./libft/*.c

FILE_O = ./*.o

HEAD_FOLDER = ./libft

FLAGC = -Wall -Wextra -Werror

all: create_lib fillit

create_lib:
	gcc -I $(HEAD_FOLDER) -c $(SRC) $(FLAGC)
	ar rc $(NAME) $(FILE_O)
	ranlib $(NAME)
	/bin/rm -f *.o
	/bin/rm -f *.o~
	/bin/rm -f *.h~
	/bin/rm -f *.c~

fillit:
	gcc $(FLAGC) -c $(NAME_FILE)
	gcc ./$(NAME) ./$(FILE_O) -o fillit
	/bin/rm -f *.o
	/bin/rm -f *.o~
	/bin/rm -f *.h~
	/bin/rm -f *.c~

re_fillit:
	/bin/rm -f fillit
	gcc $(FLAGC) ./$(NAME) ./*.c
	
clean:
	/bin/rm -f *.o
	/bin/rm -f *.o~
	/bin/rm -f *.h~
	/bin/rm -f *.c~
	/bin/rm -f fillit

fclean: clean
	/bin/rm -rf $(NAME) fillit *~ 

re: fclean all fillit