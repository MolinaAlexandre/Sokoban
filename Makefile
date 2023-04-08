##
## EPITECH PROJECT, 2022
## makefile
## File description:
## for myls
##

CFLAGS = -I./include\

SRC	=	src/check.c \
		src/get_number.c\
		src/map.c\
		src/utils.c\
		src/move1.c\
		src/move2.c\
		src/main.c\
		src/struct.c\
		src/touches.c\
		src/player.c\
		src/help.c\
		src/score.c\
		src/bonus.c

OBJ = $(SRC:.c=.o)

NAME	=	my_sokoban

all:	$(NAME)

sub:
	 cd my_lib/my && $(MAKE)

$(NAME):	sub
	gcc $(SRC) $(CFLAGS) -L./my_lib/my \
-lmy -lncurses -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make -C my_lib/my -f Makefile fclean


re: fclean $(NAME)

.PHONY: clean fclean re sub
