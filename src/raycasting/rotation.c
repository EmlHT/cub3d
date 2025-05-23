/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:36:55 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 12:16:57 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_rotate_left(t_cub *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->mlx.dir.x;
	old_plane_x = cube->mlx.plane.x;
	cube->mlx.dir.x = cube->mlx.dir.x * cos(-ROT_SPEED) \
	- cube->mlx.dir.y * sin(-ROT_SPEED);
	cube->mlx.dir.y = old_dir_x * sin(-ROT_SPEED) \
	+ cube->mlx.dir.y * cos(-ROT_SPEED);
	cube->mlx.plane.x = cube->mlx.plane.x * cos(-ROT_SPEED) \
	- cube->mlx.plane.y * sin(-ROT_SPEED);
	cube->mlx.plane.y = old_plane_x * sin(-ROT_SPEED) \
	+ cube->mlx.plane.y * cos(-ROT_SPEED);
	render_map(cube);
}

void	ft_rotate_right(t_cub *cube)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cube->mlx.dir.x;
	old_plane_x = cube->mlx.plane.x;
	cube->mlx.dir.x = cube->mlx.dir.x * cos(ROT_SPEED) \
	- cube->mlx.dir.y * sin(ROT_SPEED);
	cube->mlx.dir.y = old_dir_x * sin(ROT_SPEED) \
	+ cube->mlx.dir.y * cos(ROT_SPEED);
	cube->mlx.plane.x = cube->mlx.plane.x * cos(ROT_SPEED) \
	- cube->mlx.plane.y * sin(ROT_SPEED);
	cube->mlx.plane.y = old_plane_x * sin(ROT_SPEED) \
	+ cube->mlx.plane.y * cos(ROT_SPEED);
	render_map(cube);
}
