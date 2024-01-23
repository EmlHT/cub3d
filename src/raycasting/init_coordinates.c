/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:00:56 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 12:22:01 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	allot_dir_values(t_cub *cube, double x, double y)
{
	cube->mlx.dir.x = x;
	cube->mlx.dir.y = y;
}

static void	allot_plane_values(t_cub *cube, double x, double y)
{
	cube->mlx.plane.x = x;
	cube->mlx.plane.y = y;
}

static void	retrieve_direction(t_cub *cube)
{
	if (cube->mlx.player_start_dir == 'N')
	{
		allot_dir_values(cube, 0, -1);
		allot_plane_values(cube, 0.66, 0);
	}
	else if (cube->mlx.player_start_dir == 'S')
	{
		allot_dir_values(cube, 0, 1);
		allot_plane_values(cube, -0.66, 0);
	}
	else if (cube->mlx.player_start_dir == 'W')
	{
		allot_dir_values(cube, -1, 0);
		allot_plane_values(cube, 0, -0.66);
	}
	else if (cube->mlx.player_start_dir == 'E')
	{
		allot_dir_values(cube, 1, 0);
		allot_plane_values(cube, 0, 0.66);
	}
}

static void	retrieve_position(t_cub *cube)
{
	int	y;
	int	x;

	y = -1;
	while (cube->map[++y])
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
}
