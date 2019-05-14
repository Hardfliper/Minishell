##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	src/exec.c	\
		src/main_shell.c	\
		src/my_strspecialcpy.c	\
		src/main.c	\
		src/cd.c	\
		src/error_management.c	\
		src/builtin.c

NOMAIN	=	tests/test.c	\
		src/exec.c	\
		src/main_shell.c	\
		src/my_strspecialcpy.c	\
		src/cd.c		\
		src/error_management.c	\
		src/builtin.c

CC	=	cc

NAME	=	mysh

CRITNAME =	unit_test

CPPFLAGS =	-I ./include

CRITERION =	-lcriterion --coverage

LDFLAGS	=	-L ./lib/my/ -lmy

OBJ	=	$(SRC:.c=.o)

OBJ_TEST=	$(NOMAIN:.c=.o)

TEST	=	./tests/test.c

TEMP     =	*.gcno	\
		*.gcda

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C ./lib/my/
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIB) $(LDFLAGS)

tests_run:	$(OBJ)
		make -C ./lib/my/
		gcc -o $(CRITNAME) $(NOMAIN) $(LDFLAGS) $(CRITERION) $(CPPFLAGS)
		./unit_test

debug	:	CFLAGS += -g3
debug	:	re

err	:	CFLAGS += -Wall -Werror -Wextra
err	:	re

clean	:
		rm -f $(OBJ)
		rm -f $(TEMP)
		make clean -C ./lib/my/

fclean	:	clean
		rm -f $(NAME) $(CRITNAME)
		make fclean -C ./lib/my/

re	:	fclean all

.PHONY	:	all clean fclean re
