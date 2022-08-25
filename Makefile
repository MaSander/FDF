NAME	= fdf

SRCS	= main.c

OBJS	=${SRCS:%.c=%.o}

FLAGS	= -lX11 -lXext -lmlx

CC	= clang

all:	${NAME}

${NAME}:	${OBJS}
	ar -crs	${NAME} ${OBJS}

${OBJS}:	%.o: %.c
	%{CC} ${FLAGS} -o $@ -c $<

