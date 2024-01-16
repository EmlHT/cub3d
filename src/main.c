/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:24:32 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/16 14:29:44 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

// printf("player pos x:%f\n", cube.mlx.pos.x);
// printf("player pos y:%f\n", cube.mlx.pos.y);
// printf("player dir x:%f\n", cube.mlx.dir.x);
// printf("player dir y:%f\n", cube.mlx.dir.y);
