/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:58:55 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/16 18:20:10 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"

# define SCREEN_WIDTH 1678
# define SCREEN_HEIGHT 904

enum	e_elem
{
	NO,		// --> 0
	SO,		// --> 1
	WE,		// --> 2
	EA,		// --> 3
	C,		// --> 4
	F,		// --> 5
};

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}	t_img;
typedef	struct s_colours
{
	int	r;
	int	g;
	int	b;
}	t_colours;

typedef struct s_vector
{
	double	x;
	double	y;
}		t_vector;

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_move
{
	double	time;
	double	oldTime;
	double	frametime;
	double	move_speed;
	double	rot_speed;
}		t_move;


typedef struct s_mlx
{
	void		*ptr;
	void		*window;
	t_img		img;
	char		player_start_dir;
	t_vector	pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	ray;
	t_vector	side_dist;
	t_vector	delta_dist;
	t_pos		map;
	t_pos		step;
	double		cameraX;
	double		perp_wall_dist;
	int			hit;
	int			side;
	int			height;
	int			draw_start;
	int			draw_end;
	double		move_speed;
	double		rot_speed;
	t_move		move;
}	t_mlx;

typedef struct s_cub
{
	int			i;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*c;
	char		*f;
	char		**map;
	t_colours	*c_colours;
	t_colours	*f_colours;
	t_mlx		mlx;
}	t_cub;

void	parsing_main(int argc, char **argv, t_cub *cube);
bool	allocate_line(char *line, t_cub *cube, bool elem_fill);
void	ft_error_exit(int error_message);
void	ft_free_exit(int error_message, t_cub *cube);
void	ft_printf_map_error(char *element, bool *error);
char	*get_elem_value(enum e_elem elem);
void	init_coordinates(t_cub *cube);

/***_________ GET_NEXT_LINE _________***/
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
# define BUFFER_SIZE 5

/***_________ ARRAY MANIPULATIONS _________***/
char	**ft_arrayadd(char *newline, char **array);
int		ft_arraylen(char **array);
void	ft_arrayfree(char **array);

/***_________ DEBUG TOOLS _________***/
void	print_elements(t_cub *cube);
void	print_map(t_cub *cube);
void	print_colours(t_cub *cube);

/***_________ PARSING _________***/
void    parse_map(t_cub *cube);
void	parse_cube(t_cub *cube);

/***_________ MLX FUNCTIONS _________***/
void	mlx_main(t_cub *cube);
void	ft_free_mlx_ptr_cube(t_cub *cube);

/***_________ MOVEMENT KEYS _________***/
void	ft_movement_a(t_cub *cube);
void	ft_movement_w(t_cub *cube);
void	ft_movement_d(t_cub *cube);
void	ft_movement_s(t_cub *cube);

#endif