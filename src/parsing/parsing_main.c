/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:41 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 09:00:11 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	check_cube_elements(t_cub *cube)
{
	if (!cube->no || !cube->so || !cube->we || !cube->ea \
		|| !cube->c || !cube->f || !cube->map || !cube->map[0])
	{
		ft_putstr_fd("cube3D: missing elements\n", 2);
		return (false);
	}
	return (true);
}

static void	file_parsing(char *file, t_cub *cube)
{
	bool	elem_fill;
	char	*gnl;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_free_exit(6, cube);
	gnl = get_next_line(fd);
	while (gnl)
	{
		elem_fill = false;
		if (!allocate_line(gnl, cube, elem_fill))
		{
			free(gnl);
			close(fd);
			ft_free_exit(0, cube);
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
}

static void	cub_file_extension_check(char *arg)
{
	int	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len <= 4)
		ft_error_exit(4);
	if (arg[arg_len - 1] != 'b' && arg[arg_len - 2] != 'u' \
	&& arg[arg_len - 3] != 'c' && arg[arg_len - 4] != '.')
		ft_error_exit(4);
}

static void	file_check(char *file)
{
	int	fd;

	fd = open(file, O_DIRECTORY);
	if (fd != -1)
		ft_error_exit(2);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_exit(3);
	close(fd);
}

void	parsing_main(int argc, char **argv, t_cub *cube)
{
	if (argc != 2)
		ft_error_exit(1);
	file_check(argv[1]);
	cub_file_extension_check(argv[1]);
	ft_initialise_cube(cube);
	file_parsing(argv[1], cube);
	if (!check_cube_elements(cube))
		ft_free_exit(0, cube);
	parse_cube(cube);
	parse_map(cube);
}
