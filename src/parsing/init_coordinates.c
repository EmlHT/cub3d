/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:00:56 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/12 11:41:48 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	retrieve_position(t_cub *cube)
{
	int	y;
	int	x;

	y = -1;
	while(cube->map[++y])
	{
		x = -1;
		while (cube->map[y][++x])
		{
			if (cube->map[y][x] == cube->player_start_dir)
			{
				cube->player_pos.x = x;
				cube->player_pos.y = y;
			}
		}
	}
}

void	init_coordinates(t_cub *cube)
{
	retrieve_position(cube);
}