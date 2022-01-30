##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## program
##

SRC	=	serveur.c	\
		add_to_list.c	\
		str_to_word_array.c		\
		help_tab.c		\
		action_file.c		\
		add_client.c		\
		command_directory.c		\
		command.c		\
		communicate.c		\
		connection_data.c		\
		directory.c		\
		get_element.c		\
		help.c		\
		inic.c		\
		logout.c		\
		remove_client.c		\
		remove_file.c

CLIENT 	=	client.c

NAME	=	myftp

FLAGS	=	-W -Wall -Werror -Wextra -Wunused-macros -Wendif-labels -pedantic -Wcomment -Wmissing-braces -Wmissing-include-dirs -Wparentheses -Wsequence-point -ansi -ggdb -Wunused -Wduplicated-branches -Wmisleading-indentation

LIB		=	-Llib/my/. -lmy

all:	$(NAME)

$(NAME):
		(cd ./lib/my/ && make)
		gcc -o $(NAME) $(SRC) $(LIB)

client:
		(cd ./lib/my/ && make)
		gcc -o client $(CLIENT) $(LIB)

valgrind: fclean
		(cd ./lib/my/ && make)
		gcc -o $(NAME) $(SRC) -g3 $(LIB)

warning:
		(cd ./lib/my/ && make)
		gcc -o $(NAME) $(SRC) $(FLAGS) -g3$(LIB)

optimize:
		(cd ./lib/my/ && make)
		gcc -o $(NAME) $(SRC) -O4 $(LIB)

clean:
		rm -f $(NAME)

fclean:
		rm -f $(NAME)
		rm -f *~
		rm -f *#

re:		fclean all