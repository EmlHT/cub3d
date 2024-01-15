/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:58:55 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/15 08:40:15 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480

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

typedef struct s_mlx
{
	void		*ptr;
	void		*window;
	char		player_start_dir;
	t_vector	player_pos;
	t_vector	dir;
	t_vector	plane;
	t_vector	ray;
	double		cameraX;
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

#endif