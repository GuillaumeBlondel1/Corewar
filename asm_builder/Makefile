##
## EPITECH PROJECT, 2024
## Corewar
## File description:
## Makefile
##

SRC	:=	src/main.c										\
		file_management/read_file.c 					\
		file_management/handling_path_data.c			\
		utils/recover_path.c							\
		utils/recover_file_name.c						\

OBJ_DIR	:=	build

OBJ	:=	$(addprefix $(OBJ_DIR)/, $(notdir ${SRC:.c=.o}))

BINARY	:=	asm_builder

CFLAGS	:=	-Wall -Wextra -g3

all:	${OBJ_DIR} ${BINARY}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${OBJ_DIR}/%.o:	src/%.c
	gcc ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o:	file_management/%.c
	gcc ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o:	utils/%.c
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
