/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:58:55 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/10 11:47:09 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"

enum	e_elem
{
	NO,		// --> 0
	SO,		// --> 1
	WE,		// --> 2
	EA,		// --> 3
	C,		// --> 4
	F,		// --> 5
};

typedef struct s_cub
{
	int		i;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*c;
	char	*f;
	char	**map;
	void	*mlx;
}	t_cub;

void	parsing_main(int argc, char **argv, t_cub *cube);
bool	allocate_line(char *line, t_cub *cube);
void	ft_error_exit(int error_message);
void	ft_free_exit(int error_message, t_cub *cube);
char	*get_elem_value(enum e_elem elem);
int		ft_iswhitespace(int c);
void	parse_cube(t_cub *cube);


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

#endif