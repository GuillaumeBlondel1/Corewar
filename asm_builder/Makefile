##
## EPITECH PROJECT, 2024
## Corewar
## File description:
## Makefile
##

SRC	:=	src/main.c						\

OBJ_DIR	:=	build

OBJ	:=	$(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.c=.o}))

BINARY	:=	asm_builder

CFLAGS	:=	-Wall -Wextra

all:	${OBJ_DIR} ${BINARY}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${OBJ_DIR}/%.o:	src/%.c
	gcc ${CFLAGS} -c $< -o $@

${BINARY}:	${OBJ}
	gcc ${OBJ} ${CFLAGS} -o ${BINARY}

clean:
	rm -f ${OBJ}
	rmdir ${OBJ_DIR}

fclean:	clean
	rm -f ${BINARY}

re:	fclean
	${MAKE} all
