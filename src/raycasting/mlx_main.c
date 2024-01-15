/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:07 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/15 18:48:09 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	handle_window_close(t_cub *cube)
{
	ft_free_mlx_ptr_cube(cube);
	return (0);
}

static void	draw_walls(t_cub *cube)
{
	int	x;

    x = -1;
    while (++x < SCREEN_WIDTH)
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
		
		//initialising varibales for determining if a wall has been hit, wall distance, which side (x or y);
		cube->mlx.perp_wall_dist = 0;
		cube->mlx.hit = 0;
		cube->mlx.side = 2;
		
		if (cube->mlx.ray.x < 0)
		{
			cube->mlx.step.x = -1;
			cube->mlx.side_dist.x = (cube->mlx.pos.x - cube->mlx.map.x) * cube->mlx.delta_dist.x;
		}
		else
		{
			cube->mlx.step.x = 1;
			cube->mlx.side_dist.x = (cube->mlx.map.x + 1.0 - cube->mlx.pos.x) * cube->mlx.delta_dist.x;
		}
		if (cube->mlx.ray.y < 0)
		{
			cube->mlx.step.y = -1;
			cube->mlx.side_dist.y = (cube->mlx.pos.y - cube->mlx.map.y) * cube->mlx.delta_dist.y;
		}
		else
		{
			cube->mlx.step.y = 1;
			cube->mlx.side_dist.y = (cube->mlx.map.y + 1.0 - cube->mlx.pos.y) * cube->mlx.delta_dist.y;
		}
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
			if (cube->map[cube->mlx.map.x][cube->mlx.map.y] == 1)
				cube->mlx.hit = 1;
		}
		if (cube->mlx.side == 0)
			cube->mlx.perp_wall_dist = cube->mlx.side_dist.x - cube->mlx.delta_dist.x;
		else
			cube->mlx.perp_wall_dist = cube->mlx.side_dist.y - cube->mlx.delta_dist.y;
		
		cube->mlx.height = (int)(SCREEN_HEIGHT / cube->mlx.perp_wall_dist);
		
		printf("mlx.height: %i\n", cube->mlx.height);
		
		cube->mlx.draw_start = -cube->mlx.height / 2 + SCREEN_HEIGHT / 2;
		if (cube->mlx.draw_start < 0)
			cube->mlx.draw_start = 0;
		cube->mlx.draw_end = cube->mlx.height / 2 + SCREEN_HEIGHT / 2;
		if (cube->mlx.draw_end >= SCREEN_HEIGHT)
			cube->mlx.draw_end = SCREEN_HEIGHT - 1;

		int whatever = cube->mlx.draw_end;
		while (--whatever > cube->mlx.draw_start)
			mlx_pixel_put(cube->mlx.ptr, cube->mlx.window, cube->mlx.draw_start, whatever, 0xFF0000);
    }
}

static int	handle_input(int keysym, t_cub *cube)
{
	if (keysym == 53)
		ft_free_mlx_ptr_cube(cube);
	// if (keysym == 0)
	// 	ft_movement_a(map);
	// if (keysym == 13)
	// 	ft_movement_w(map);
	// if (keysym == 2)
	// 	ft_movement_d(map);
	// if (keysym == 1)
	// 	ft_movement_s(map);
	return (0);
}

static int    ft_render(void)
{
    return (0);
}

void	mlx_main(t_cub *cube)
{
	cube->mlx.ptr = mlx_init();
	if (!cube->mlx.ptr)
		ft_free_exit(13, cube);
	cube->mlx.window = mlx_new_window(cube->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!cube->mlx.window)
		ft_free_exit(14, cube);
	cube->mlx.img.mlx_img = mlx_new_image(cube->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	mlx_loop_hook(cube->mlx.ptr, &ft_render, NULL);
	draw_walls(cube);
	mlx_key_hook(cube->mlx.window, &handle_input, cube);
	mlx_hook(cube->mlx.window, 17, 0, &handle_window_close, cube);
	mlx_loop(cube->mlx.ptr);
	ft_free_mlx_ptr_cube(cube);
}
