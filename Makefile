BASIC = \033[0m
BOLD = \033[1m
LBLUE = \033[38;5;153m

LIBFT_PATH      =	./Libft/
SRC_PATH		=	./src/


SRC		        =	${addprefix ${SRC_PATH},	main.c \
												errors.c \
												parsing/parsing_main.c \
												parsing/parsing_map.c \
												parsing/init_map_elements.c \
												parsing/array_manipulations.c \
												parsing/parsing_textures.c \
												parsing/parsing_colours.c \
												raycasting/init_coordinates.c \
												raycasting/ray_calculations.c \
												raycasting/mlx_main.c \
												raycasting/mlx_functions.c \
												raycasting/movements.c \
												raycasting/rotation.c \
												raycasting/textures.c \
												debug.c \
												get_next_line/get_next_line.c \
												get_next_line/get_next_line_utils.c}

OBJ             = ${SRC:.c=.o}

HEADER          = ./

CC              = cc

RM              = rm -f

CFLAGS          = -Wall -Werror -Wextra -g

OS := ${shell uname}

LINKS			= -lmlx -framework OpenGL -framework AppKit

ifeq (${OS}, Darwin)
	COMP = @$(CC) $(CFLAGS) $(LINKS) $(OBJ) ${LIBFT_PATH}libft.a -I $(HEADER) -o $(NAME)
else
	COMP = $(CC) $(CFLAGS) $(OBJ) ${LIBFT_PATH}libft.a -I $(HEADER) -o $(NAME) -L /home/ehouot/Git/cub3d/minilibx-linux -lmlx -lXext -lX11 -lm
endif

ifdef DEBUG
        CFLAGS += -fsanitize=address -g3
endif

NAME            = cub3D

all:            $(NAME)

.c.o:
				@$(CC) $(CFLAGS) -I $(HEADER) -c $< -o $(<:.c=.o)

$(NAME):    	$(OBJ)
				@${MAKE} -C ${LIBFT_PATH}
				$(COMP)
				@echo "${LBLUE}${BOLD}cub3D compiled${BASIC}"

debug:
	${MAKE} DEBUG=1

clean:
				@$(RM) $(OBJ)
				@${MAKE} clean -C ${LIBFT_PATH}

fclean:         clean
				@$(RM) $(NAME) ${LIBFT_PATH}libft.a
				@echo "${LBLUE}deleted cub3D support files${BASIC}"

re:				fclean all

.PHONY:			all clean fclean re