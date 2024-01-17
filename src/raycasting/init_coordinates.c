/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:00:56 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/17 15:34:01 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	retrieve_direction(t_cub *cube)
{
	if (cube->mlx.player_start_dir == 'N')
	{
		cube->mlx.dir.x = 0;
		cube->mlx.dir.y = -1;
		cube->mlx.plane.x = 0.66;
		cube->mlx.plane.y = 0;
	}
	else if (cube->mlx.player_start_dir == 'S')
	{
		cube->mlx.dir.x = 0;
		cube->mlx.dir.y = 1;
		cube->mlx.plane.x = 0.66;
		cube->mlx.plane.y = 0;
	}
	else if (cube->mlx.player_start_dir == 'W')
	{
		cube->mlx.dir.x = -1;
		cube->mlx.dir.y = 0;
		cube->mlx.plane.x = 0;
		cube->mlx.plane.y = 0.66;
	}
	else if (cube->mlx.player_start_dir == 'E')
	{
		cube->mlx.dir.x = 1;
		cube->mlx.dir.y = 0;
		cube->mlx.plane.x = 0;
		cube->mlx.plane.y = 0.66;
	}
}

static void	retrieve_position(t_cub *cube)
{
	int	y;
	int	x;

	y = -1;
	while(cube->map[++y])
	{
		x = -1;
		while (cube->map[y][++x])
		{
			if (cube->map[y][x] == cube->mlx.player_start_dir)
			{
				cube->mlx.pos.x = x;
				cube->mlx.pos.y = y;
			}
		}
	}
}

void	init_coordinates(t_cub *cube)
{
	retrieve_position(cube);
	retrieve_direction(cube);
	// cube->mlx.plane.x = 0;
	// cube->mlx.plane.y = 0.66;
	// if (cube->mlx.player_start_dir == 'N' || cube->mlx.player_start_dir == 'S')
	// {
	// 	if (cube->mlx.player_start_dir == 'N')
	// 		cube->mlx.plane.y = -0.66;
	// 	else
	// 		cube->mlx.plane.y = 0.66;
	// }
	// if (cube->mlx.player_start_dir == 'E' || cube->mlx.player_start_dir == 'W')
	// {
	// 	if (cube->mlx.player_start_dir == 'E')
	// 		cube->mlx.plane.x = -0.66;
	// 	else
	// 		cube->mlx.plane.x = 0.66;
	// }
}
