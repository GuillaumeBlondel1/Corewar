##
## EPITECH PROJECT, 2024
## Corewar
## File description:
## Makefile
##

SRC	:=	src/main.c										\
		src/free_memory.c								\
		src/op.c										\
		file_management/read_file.c 					\
		file_management/handling_path_data.c			\
		parser/parser.c									\
		parser/parser_mask.c							\
		parser/parser_name_comment.c					\
		parser/parser_body.c							\
		parser/checking_label.c							\
		parser/parser_instruction.c						\
		parser/parser_args.c							\
		parser/compute_label.c							\
		utils/recover_path.c							\
		utils/recover_file_name.c						\
		utils/stradd.c									\
		utils/change_extension.c						\
		utils/split_str.c								\
		utils/split_strlen.c							\
		utils/free_split_str.c							\
		utils/is_num.c									\
		utils/is_correct_char.c							\
		llist/implement_llist.c							\
		llist/free_llist.c								\
		llist/last_node.c								\

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

${OBJ_DIR}/%.o:	parser/%.c
	gcc ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o:	utils/%.c
	gcc ${CFLAGS} -c $< -o $@

${OBJ_DIR}/%.o:	llist/%.c
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
