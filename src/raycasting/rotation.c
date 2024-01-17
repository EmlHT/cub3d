/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:36:55 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/17 11:57:05 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_rotate_left(t_cub *cube)
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
		cube->mlx.dir.x = cube->mlx.dir.x * cos(-ROT_SPEED) - cube->mlx.dir.y * sin(-ROT_SPEED);
     	cube->mlx.dir.y = old_dir_x * sin(-ROT_SPEED) + cube->mlx.dir.y * cos(-ROT_SPEED);
      	cube->mlx.plane.x = cube->mlx.plane.x * cos(-ROT_SPEED) - cube->mlx.plane.y * sin(-ROT_SPEED);
      	cube->mlx.plane.y = old_plane_x * sin(-ROT_SPEED) + cube->mlx.plane.y * cos(-ROT_SPEED);	
		draw_walls(cube);
	}
}

void	ft_rotate_right(t_cub *cube)
{
	double	old_dir_x;
	double	old_plane_x;
	
	old_dir_x = cube->mlx.dir.x;
	old_plane_x = cube->mlx.plane.x;
	
	mlx_destroy_image(cube->mlx.ptr, cube->mlx.img.mlx_img);
	ft_new_image(cube);
	cube->mlx.dir.x = cube->mlx.dir.x * cos(ROT_SPEED) - cube->mlx.dir.y * sin(ROT_SPEED);
	cube->mlx.dir.y = old_dir_x * sin(ROT_SPEED) + cube->mlx.dir.y * cos(ROT_SPEED);
	cube->mlx.plane.x = cube->mlx.plane.x * cos(ROT_SPEED) - cube->mlx.plane.y * sin(ROT_SPEED);
	cube->mlx.plane.y = old_plane_x * sin(ROT_SPEED) + cube->mlx.plane.y * cos(ROT_SPEED);
	draw_walls(cube);
}
