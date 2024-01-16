/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:11 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/16 19:23:10 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// void	ft_movement_a(t_cub *cube)
// {
// 	return ;
// }

void	ft_movement_w(t_cub *cube)
{
	if (cube->map[(int)cube->mlx.pos.y - 1][(int)cube->mlx.pos.x] == '1')
		return ;
	else
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
		ft_new_image(cube);
		cube->mlx.pos.y = cube->mlx.pos.y - 1;
		draw_walls(cube);
	}
	// if(cube->map[int(cube->mlx.pos.x + cube->mlx.dir.x * moveSpeed)][int(posY)] == '0')
	// 	posX += dirX * moveSpeed;
	// if(cube->map[(cube->mlx.pos.x)][int(cube->mlx.pos.y + cube->mlx.dir.y * moveSpeed)] == false)
	// 	posY += dirY * moveSpeed;
}

// void	ft_movement_d(t_cub *cube)
// {
// 	return ;
// }

void	ft_movement_s(t_cub *cube)
{
	if (cube->map[(int)cube->mlx.pos.y + 1][(int)cube->mlx.pos.x] == '1')
		return ;
	else
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
		ft_new_image(cube);
		cube->mlx.pos.y = cube->mlx.pos.y + 1;
		draw_walls(cube);
	}
}
