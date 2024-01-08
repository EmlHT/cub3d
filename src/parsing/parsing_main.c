/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:41 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/08 17:08:058 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	file_parsing(char *file, t_cub *cube)
{
	char	*gnl;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_error_exit(6);
	gnl = get_next_line(fd);
	while (gnl)
	{
		if (!allocate_line(gnl, cube))
		{
			free(gnl);
			close(fd);
			exit(1);
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	close(fd);
}

static void	cub_file_check(char *arg)
{
	int	arg_len;

	arg_len = ft_strlen(arg);
	if (arg_len <= 4)
		ft_error_exit(3);
	if (arg[arg_len - 1] != 'b' && arg[arg_len - 2] != 'u' && arg[arg_len - 3] != 'c' \
		&& arg[arg_len - 4] != '.')
		ft_error_exit(3);
	if (access(arg, F_OK) == -1)
		ft_error_exit(4);
	if (access(arg, R_OK) == -1)
		ft_error_exit(5);
}

static bool	is_folder(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY | O_DIRECTORY);
	if (fd == -1)
		return (false);
	close(fd);
	return (true);
}

static void	ft_initialise_cube(char *file, t_cub *cube)
{
	cube->i = 0;
	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->ea = NULL;
	cube->c = NULL;
	cube->f = NULL;
	cube->map = ft_calloc(2, sizeof(char *));
	if (!cube->map)
	{
		ft_putstr_fd("cub3D: malloc error\n", 2);
		return ;
	}
	file_parsing(file, cube);
}

void	parsing_main(int argc, char **argv, t_cub *cube)
{
	if (argc != 2)
		ft_error_exit(1);
	if (is_folder(argv[1]))
		ft_error_exit(2);
	cub_file_check(argv[1]);
	ft_initialise_cube(argv[1], cube);
}
