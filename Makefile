
LIBFT_PATH      =	./Libft/
SRC_PATH		=	./src/

OS := ${shell uname}

ifeq (${OS}, Linux)
    COMPILE = @$(CC) $(CFLAGS) $(OBJ) ${LIBFT_PATH}libft.a -I $(HEADER) -o $(NAME)
else
	COMPILE = @$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) ${LIBFT_PATH}libft.a -I $(HEADER) -o $(NAME)
endif


SRC		        =	${addprefix ${SRC_PATH},	main.c \
												errors.c \
												parsing/parsing_main.c \
												parsing/parsing_map.c \
												parsing/init_map_elements.c \
												parsing/array_manipulations.c \
												parsing/parsing_elements.c \
												raycasting/init_coordinates.c \
												raycasting/mlx_main.c \
												debug.c \
												get_next_line/get_next_line.c \
												get_next_line/get_next_line_utils.c}

OBJ             = ${SRC:.c=.o}

HEADER          = ./

CC              = cc

RM              = rm -f

CFLAGS          = -Wall -Werror -Wextra -g
LINKS			= -lmlx -framework OpenGL -framework AppKit

ifdef DEBUG
        CFLAGS += -fsanitize=address -g3
endif

NAME            = cub3D

all:            $(NAME)

.c.o:
				@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):    	$(OBJ)
				@${MAKE} -C ${LIBFT_PATH}
				@$(CC) $(CFLAGS) $(LINKS) $(OBJ) ${LIBFT_PATH}libft.a -I $(HEADER) -o $(NAME)

debug:
	${MAKE} DEBUG=1

clean:
				@$(RM) $(OBJ)
				@${MAKE} clean -C ${LIBFT_PATH}

fclean:         clean
				@$(RM) $(NAME) ${LIBFT_PATH}libft.a

re:				fclean all

.PHONY:			all clean fclean re