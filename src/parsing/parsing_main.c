/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:11:41 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/08 15:34:02 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	is_cub_file(char *arg)
{
	int	i;

	i = ft_strlen(arg);
	if (i <= 4)
		return (false);
	if (arg[i - 1] != 'b' && arg[i - 2] != 'u' && arg[i - 3] != 'c' \
		&& arg[i - 4] != '.')
		return (false);
	return (true);
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

static void	ft_initialise_cube(t_cub *cube)
{
	cube->i = 0;
}

void	parsing_main(int argc, char **argv, t_cub *cube)
{
	if (argc != 2)
		ft_error_exit(1);
	if (is_folder(argv[1]))
		ft_error_exit(2);
	if(!is_cub_file(argv[1]))
		ft_error_exit(3);
	ft_initialise_cube(cube);
}