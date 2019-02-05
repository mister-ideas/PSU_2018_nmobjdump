##
## EPITECH PROJECT, 2019
## PSU_2018_malloc
## File description:
## Makefile
##

CC=				gcc

SRC_NM=			nm.c

SRC_OBJDUMP=	objdump.c

OBJ_NM=			$(SRC_NM:.c=.o)

OBJ_OBJDUMP=	$(SRC_OBJDUMP:.c=.o)

NAME_NM=		nm

NAME_OBJDUMP=	objdump

CFLAGS=			-Wall -Wextra -Werror

CPPFLAGS=		-I.

RM=				rm -f

all:			nm objdump

nm:				$(OBJ_NM)
				$(CC) -o $(NAME_NM) $(CFLAGS) $(OBJ_NM)

objdump:		$(OBJ_OBJDUMP)
				$(CC) -o $(NAME_OBJDUMP) $(CFLAGS) $(OBJ_OBJDUMP)

clean:
				$(RM) $(OBJ_NM) $(OBJ_OBJDUMP)

fclean:			clean
				$(RM) $(NAME_NM) $(NAME_OBJDUMP)

re:				fclean all

.PHONY:			all clean fclean re
