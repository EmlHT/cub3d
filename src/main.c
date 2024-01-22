/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:24:32 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 08:57:39 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_initialise_cube(t_cub *cube)
{
	cube->no = NULL;
	cube->so = NULL;
	cube->we = NULL;
	cube->ea = NULL;
	cube->c = NULL;
	cube->f = NULL;
	cube->c_colours = NULL;
	cube->f_colours = NULL;
	cube->map = ft_calloc(1, sizeof(char *));
	if (!cube->map)
	{
		ft_putstr_fd("cub3D: malloc error\n", 2);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_cub	cube;

	(void)argv;
	(void)argc;
	parsing_main(argc, argv, &cube);
	init_coordinates(&cube);
	mlx_main(&cube);
	return (0);
}
