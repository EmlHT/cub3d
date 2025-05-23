/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:11 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 12:12:06 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_movement_forward(t_cub *cube)
{
	double	movement_x;
	double	movement_y;

	movement_x = cube->mlx.pos.x + cube->mlx.dir.x * MOVE_SPEED;
	movement_y = cube->mlx.pos.y + cube->mlx.dir.y * MOVE_SPEED;
	if (cube->map[(int)cube->mlx.pos.y][(int)movement_x] != '1')
		cube->mlx.pos.x = movement_x;
	if (cube->map[(int)movement_y][(int)cube->mlx.pos.x] != '1')
		cube->mlx.pos.y = movement_y;
	render_map(cube);
}

void	ft_movement_backward(t_cub *cube)
{
	double	movement_x;
	double	movement_y;

	movement_x = cube->mlx.pos.x - cube->mlx.dir.x * MOVE_SPEED;
	movement_y = cube->mlx.pos.y - cube->mlx.dir.y * MOVE_SPEED;
	if (cube->map[(int)cube->mlx.pos.y][(int)movement_x] != '1')
		cube->mlx.pos.x = movement_x;
	if (cube->map[(int)movement_y][(int)cube->mlx.pos.x] != '1')
		cube->mlx.pos.y = movement_y;
	render_map(cube);
}

void	ft_movement_left(t_cub *cube)
{
	double	side_x;
	double	side_y;
	double	movement_x;
	double	movement_y;

	side_x = cube->mlx.dir.y;
	side_y = -cube->mlx.dir.x;
	movement_x = cube->mlx.pos.x + side_x * MOVE_SPEED;
	movement_y = cube->mlx.pos.y + side_y * MOVE_SPEED;
	if (cube->map[(int)cube->mlx.pos.y][(int)movement_x] != '1')
		cube->mlx.pos.x = movement_x;
	if (cube->map[(int)movement_y][(int)cube->mlx.pos.x] != '1')
		cube->mlx.pos.y = movement_y;
	render_map(cube);
}

void	ft_movement_right(t_cub *cube)
{
	double	side_x;
	double	side_y;
	double	movement_x;
	double	movement_y;

	side_x = -cube->mlx.dir.y;
	side_y = cube->mlx.dir.x;
	movement_x = cube->mlx.pos.x + side_x * MOVE_SPEED;
	movement_y = cube->mlx.pos.y + side_y * MOVE_SPEED;
	if (cube->map[(int)cube->mlx.pos.y][(int)movement_x] != '1')
		cube->mlx.pos.x = movement_x;
	if (cube->map[(int)movement_y][(int)cube->mlx.pos.x] != '1')
		cube->mlx.pos.y = movement_y;
	render_map(cube);
}
