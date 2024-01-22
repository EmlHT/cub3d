/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calculations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:44:25 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 12:06:30 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray(t_cub *cube, int x)
{
	cube->mlx.cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
	cube->mlx.ray.x = cube->mlx.dir.x + cube->mlx.plane.x * cube->mlx.cameraX;
	cube->mlx.ray.y = cube->mlx.dir.y + cube->mlx.plane.y * cube->mlx.cameraX;
	cube->mlx.map.x = (int)cube->mlx.pos.x;
	cube->mlx.map.y = (int)cube->mlx.pos.y;
	if (cube->mlx.ray.x == 0)
		cube->mlx.delta_dist.x = 1e30;
	else
		cube->mlx.delta_dist.x = fabs(1 / cube->mlx.ray.x);
	if (cube->mlx.ray.y == 0)
		cube->mlx.delta_dist.y = 1e30;
	else
		cube->mlx.delta_dist.y = fabs(1 / cube->mlx.ray.y);
}

void	init_ray_direction(t_cub *cube)
{
	if (cube->mlx.ray.x < 0)
	{
		cube->mlx.step.x = -1;
		cube->mlx.side_dist.x = (cube->mlx.pos.x - cube->mlx.map.x) \
		* cube->mlx.delta_dist.x;
	}
	else
	{
		cube->mlx.step.x = 1;
		cube->mlx.side_dist.x = (cube->mlx.map.x + 1.0 - cube->mlx.pos.x) \
		* cube->mlx.delta_dist.x;
	}
	if (cube->mlx.ray.y < 0)
	{
		cube->mlx.step.y = -1;
		cube->mlx.side_dist.y = (cube->mlx.pos.y - cube->mlx.map.y) \
		* cube->mlx.delta_dist.y;
	}
	else
	{
		cube->mlx.step.y = 1;
		cube->mlx.side_dist.y = (cube->mlx.map.y + 1.0 - cube->mlx.pos.y) \
		* cube->mlx.delta_dist.y;
	}
}

void	perform_dda_algorithm(t_cub *cube)
{
	cube->mlx.hit = 0;
	cube->mlx.side = 2;
	while (cube->mlx.hit == 0)
	{
		if (cube->mlx.side_dist.x < cube->mlx.side_dist.y)
		{
			cube->mlx.side_dist.x += cube->mlx.delta_dist.x;
			cube->mlx.map.x += cube->mlx.step.x;
			cube->mlx.side = 0;
		}
		else
		{
			cube->mlx.side_dist.y += cube->mlx.delta_dist.y;
			cube->mlx.map.y += cube->mlx.step.y;
			cube->mlx.side = 1;
		}
		if (cube->map[cube->mlx.map.y][cube->mlx.map.x] == '1')
			cube->mlx.hit = 1;
	}
}

void	calculate_wall_distance(t_cub *cube)
{
	cube->mlx.perp_wall_dist = 0;
	cube->mlx.wall_x = 0;
	if (cube->mlx.side == 0)
	{
		cube->mlx.perp_wall_dist = cube->mlx.side_dist.x \
		- cube->mlx.delta_dist.x;
		cube->mlx.wall_x = cube->mlx.pos.y + cube->mlx.perp_wall_dist \
		* cube->mlx.ray.y;
	}
	else
	{
		cube->mlx.perp_wall_dist = cube->mlx.side_dist.y \
		- cube->mlx.delta_dist.y;
		cube->mlx.wall_x = cube->mlx.pos.x + cube->mlx.perp_wall_dist \
		* cube->mlx.ray.x;
	}
	cube->mlx.wall_x -= floor(cube->mlx.wall_x);
}

void	calculate_texture_coordinates(t_cub *cube)
{
	double	tex_height;

	tex_height = 0;
	cube->mlx.tex.x = (int)(cube->mlx.wall_x * (double)(TEXTURE_WIDTH));
	if (cube->mlx.side == 0 && cube->mlx.ray.x > 0)
		cube->mlx.tex.x = TEXTURE_WIDTH - cube->mlx.tex.x - 1;
	if (cube->mlx.side == 1 && cube->mlx.ray.y < 0)
		cube->mlx.tex.x = TEXTURE_WIDTH - cube->mlx.tex.x - 1;
	cube->mlx.height = (int)(SCREEN_HEIGHT / cube->mlx.perp_wall_dist);
	cube->mlx.draw_start = -cube->mlx.height / 2 + SCREEN_HEIGHT / 2;
	if (cube->mlx.draw_start < 0)
		cube->mlx.draw_start = 0;
	cube->mlx.draw_end = cube->mlx.height / 2 + SCREEN_HEIGHT / 2;
	if (cube->mlx.draw_end >= SCREEN_HEIGHT)
		cube->mlx.draw_end = SCREEN_HEIGHT - 1;
	cube->mlx.tex.step = 1.0 * TEXTURE_HEIGHT / cube->mlx.height;
	tex_height = cube->mlx.draw_start - SCREEN_HEIGHT / 2 \
	+ cube->mlx.height / 2;
	cube->mlx.tex.pos = tex_height * cube->mlx.tex.step;
}
