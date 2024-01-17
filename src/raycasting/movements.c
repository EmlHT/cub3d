/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:11 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/17 11:28:09 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_movement_left(t_cub *cube)
{
	double	old_dir_x;
	double	old_plane_x;
	
	old_dir_x = cube->mlx.dir.x;
	old_plane_x = cube->mlx.plane.x;
	if (cube->map[(int)cube->mlx.pos.y][(int)cube->mlx.pos.x - 1] == '1')
		return ;
	else
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
		ft_new_image(cube);
		cube->mlx.dir.x = cube->mlx.dir.x * cos(ROT_SPEED) - cube->mlx.dir.y * sin(ROT_SPEED);
     	cube->mlx.dir.y = old_dir_x * sin(ROT_SPEED) + cube->mlx.dir.y * cos(ROT_SPEED);
      	cube->mlx.plane.x = cube->mlx.plane.x * cos(ROT_SPEED) - cube->mlx.plane.y * sin(ROT_SPEED);
      	cube->mlx.plane.y = old_plane_x * sin(ROT_SPEED) + cube->mlx.plane.y * cos(ROT_SPEED);	
		draw_walls(cube);
	}
}

void	ft_movement_forward(t_cub *cube)
{
	if (cube->map[(int)cube->mlx.pos.y - 1][(int)cube->mlx.pos.x] == '1')
		return ;
	else
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
		ft_new_image(cube);
		cube->mlx.pos.x += cube->mlx.dir.x * MOVE_SPEED;
		cube->mlx.pos.y += cube->mlx.dir.y * MOVE_SPEED;
		draw_walls(cube);
	}
}

void	ft_movement_right(t_cub *cube)
{
	double	old_dir_x;
	double	old_plane_x;
	
	old_dir_x = cube->mlx.dir.x;
	old_plane_x = cube->mlx.plane.x;
	if (cube->map[(int)cube->mlx.pos.y][(int)cube->mlx.pos.x + 1] == '1')
		return ;
	else
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
		ft_new_image(cube);
      	cube->mlx.dir.x = cube->mlx.dir.x * cos(-ROT_SPEED) - cube->mlx.dir.y * sin(-ROT_SPEED);
     	cube->mlx.dir.y = old_dir_x * sin(-ROT_SPEED) + cube->mlx.dir.y * cos(-ROT_SPEED);
      	cube->mlx.plane.x = cube->mlx.plane.x * cos(-ROT_SPEED) - cube->mlx.plane.y * sin(-ROT_SPEED);
      	cube->mlx.plane.y = old_plane_x * sin(-ROT_SPEED) + cube->mlx.plane.y * cos(-ROT_SPEED);
		draw_walls(cube);
	}
}

void	ft_movement_backward(t_cub *cube)
{
	if (cube->map[(int)cube->mlx.pos.y + 1][(int)cube->mlx.pos.x] == '1')
		return ;
	else
	{
		mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
		ft_new_image(cube);
		cube->mlx.pos.x -= cube->mlx.dir.x * MOVE_SPEED;
		cube->mlx.pos.y -= cube->mlx.dir.y * MOVE_SPEED;
		draw_walls(cube);
	}
}
