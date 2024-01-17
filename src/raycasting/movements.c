/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:11 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/17 08:05:35 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_movement_a(t_cub *cube)
{
	if (cube->map[(int)cube->mlx.pos.y][(int)cube->mlx.pos.x - 1] == '1')
		return ;
	else
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
		ft_new_image(cube);
		cube->mlx.pos.x = cube->mlx.pos.x - 1;
		draw_walls(cube);
	}
}

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
	if(cube->map[(int)(cube->mlx.pos.x + cube->mlx.dir.x * MOVE_SPEED)][(int)(cube->mlx.pos.y)] == '0')
		cube->mlx.pos.x += cube->mlx.dir.x * MOVE_SPEED;
	if(cube->map[(int)(cube->mlx.pos.x)][(int)(cube->mlx.pos.y + cube->mlx.dir.y * MOVE_SPEED)] == '0')
		cube->mlx.pos.y += cube->mlx.dir.y * MOVE_SPEED;
}

void	ft_movement_d(t_cub *cube)
{
	if (cube->map[(int)cube->mlx.pos.y][(int)cube->mlx.pos.x + 1] == '1')
		return ;
	else
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
		ft_new_image(cube);
		cube->mlx.pos.x = cube->mlx.pos.x + 1;
		draw_walls(cube);
	}
}

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
