/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:24:32 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/12 11:42:37 by brettlecler      ###   ########.fr       */
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
	printf("Player pos_x: %i\n", cube.player_pos.x);
	printf("Player pos_y: %i\n", cube.player_pos.y);
	//mlx_main(&cube);
	return (0);
}
