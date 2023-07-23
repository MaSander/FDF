NAME	= fdf

SRCS	= main.c \
		hook.c \
		read_map/read.c \
		read_map/read_helper.c \
		read_map/ft_lst_point.c \
		read_map/get_next_line.c \
		drawing/drawing.c \
		drawing/drawing_help.c \
		utils/ft_calloc.c \
		utils/ft_split.c \
		utils/ft_strjoin.c \
		utils/ft_strlcat.c \
		utils/ft_strlcpy.c \
		utils/atoi.c \
		utils/ft_strlen.c \
		utils/ft_substr.c \
		utils/ft_strdup.c \
		utils/ft_free.c \
		utils/ft_strnstr.c \
		utils/hexadecimal.c

OBJS	= ${SRCS:%.c=%.o}
CFLAGS	= -Wall -Wextra -Werror 
MLX 	= -lX11 -lXext -lmlx -lm
VFLAGS	= --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=valgring.log
CC		= clang -o3


all:	${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${MLX} -o ${NAME}

${OBJS}:	%.o: %.c
	${CC} ${CFLAGS} -o $@ -c $<

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} -rf ${NAME} ./fdf ./valgring.log ./.vscode

re:	fclean all

run:
	valgrind ${VFLAGS} ./fdf teste ./maps/teste.fdf

norm:
	norminette ./*.h ./*.c ./utils/* ./read_map/* ./drawing/* ./gnl/*