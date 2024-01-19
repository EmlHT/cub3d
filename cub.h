/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:58:55 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/19 08:51:16 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"

# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124

# define SCREEN_WIDTH 1080
# define SCREEN_HEIGHT 720
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

# define MOVE_SPEED 0.3
# define ROT_SPEED 0.08

enum	e_elem
{
	NO,		// --> 0
	SO,		// --> 1
	WE,		// --> 2
	EA,		// --> 3
	C,		// --> 4
	F,		// --> 5
};
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

typedef struct s_img
{
    void	*ref;
    char	*addr;
	t_pos	size;
    int		bpp;
    int		line_len;
    int		endian;
}	t_img;

typedef struct xpm
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;
}	t_xpm;

typedef struct s_tex
{
	int		x;
	int		y;
	double	step;
	double	pos;
}	t_tex;

typedef struct s_mlx
{
	void		*ptr;
	void		*window;
	t_img		img;
	t_xpm		xpm_img;
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
	double		wall_x;
	t_tex		tex;
	int			hit;
	int			side;
	int			height;
	int			draw_start;
	int			draw_end;
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
void	stock_xpm_images(t_cub *cube);
void	ft_free_mlx_ptr_cube(t_cub *cube);
void	render_map(t_cub *cube);
void	my_mlx_pixel_put(t_img image, int x, int y, unsigned int color);
t_img	ft_new_image(t_cub *cube, char *img_source);
void	draw_texture(t_cub *cube, int x);

/***_________ MOVEMENT KEYS _________***/
void	ft_movement_left(t_cub *cube);
void	ft_movement_forward(t_cub *cube);
void	ft_movement_right(t_cub *cube);
void	ft_movement_backward(t_cub *cube);
void	ft_rotate_left(t_cub *cube);
void	ft_rotate_right(t_cub *cube);

/***_________ RAYCASTING _________***/
void	calculate_texture_coordinates(t_cub *cube);
void	calculate_wall_distance(t_cub *cube);
void	perform_dda_algorithm(t_cub *cube);
void	init_ray_direction(t_cub *cube);
void	init_ray(t_cub *cube, int x);
void	color_ceiling_floor(t_cub *cube);

#endif