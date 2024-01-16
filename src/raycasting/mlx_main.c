/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:07 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/16 19:16:28 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	handle_window_close(t_cub *cube)
{
	ft_free_mlx_ptr_cube(cube);
	return (0);
}

// t_img	ft_new_image(void *mlx, char *path)
// {
// 	t_img	image;

// 	image.reference = mlx_xpm_file_to_image(mlx, path, &image.size.x,
// 			&image.size.y);
// 	image.pixels = mlx_get_data_addr(image.reference, &image.bits_per_pixel,
// 			&image.line_size, &image.endian);
// 	return (image);
// }

// static void   my_mlx_pixel_put(t_cub *cube, int x, int y, int color)
// {
//     char        *dst;
//     const int    offset = (y * cube->mlx.img.line_len + x * (cube->mlx.img.bpp / 8));

//     dst = cube->mlx.img.addr + offset;
//     *(unsigned int *)dst = color;
// }

static void verLine(int x, int drawStart, int drawEnd, int color, t_cub *cube)
{
	for (int y = drawStart; y <= drawEnd; y++)
	{
		mlx_pixel_put(cube->mlx.ptr, cube->mlx.window, x, y, color);
    }
}

void	draw_walls(t_cub *cube)
{
	int	x;

    x = -1;
	cube->mlx.move.time = 0;
	cube->mlx.move.oldTime = 0;
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
			if (cube->map[cube->mlx.map.y][cube->mlx.map.x] == '1')
				cube->mlx.hit = 1;
		}
		if (cube->mlx.side == 0)
			cube->mlx.perp_wall_dist = cube->mlx.side_dist.x - cube->mlx.delta_dist.x;
		else
			cube->mlx.perp_wall_dist = cube->mlx.side_dist.y - cube->mlx.delta_dist.y;
		
		cube->mlx.height = (int)(SCREEN_HEIGHT / cube->mlx.perp_wall_dist);
		
		cube->mlx.draw_start = -cube->mlx.height / 2 + SCREEN_HEIGHT / 2;
		if (cube->mlx.draw_start < 0)
			cube->mlx.draw_start = 0;
		cube->mlx.draw_end = cube->mlx.height / 2 + SCREEN_HEIGHT / 2;
		if (cube->mlx.draw_end >= SCREEN_HEIGHT)
			cube->mlx.draw_end = SCREEN_HEIGHT - 1;

		if (cube->mlx.side == 0)
			verLine(x, cube->mlx.draw_start, cube->mlx.draw_end, 0xFF8080, cube);
		else
			verLine(x, cube->mlx.draw_start, cube->mlx.draw_end, 0x8B0000, cube);
    }
}

void	ft_new_image(t_cub *cube)
{
	cube->mlx.img.mlx_img = mlx_new_image(cube->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->mlx.img.addr = mlx_get_data_addr(cube->mlx.img.mlx_img, \
    &(cube->mlx.img.bpp), &(cube->mlx.img.line_len), &(cube->mlx.img.endian));
}

static int	handle_input(int keysym, t_cub *cube)
{
	// cube->mlx.move.oldTime = cube->mlx.move.time;
	// cube->mlx.move.time = getTicks(); // a creer
	if (keysym == 53)
		ft_free_mlx_ptr_cube(cube);
	// if (keysym == 0)
	// 	ft_movement_a(cube);
	if (keysym == 13)
		ft_movement_w(cube);
	// if (keysym == 2)
	// 	ft_movement_d(cube);
	if (keysym == 1)
		ft_movement_s(cube);
	return (0);
}

// static int    ft_render(void)
// {
//     return (0);
// }

void	mlx_main(t_cub *cube)
{
	cube->mlx.ptr = mlx_init();
	if (!cube->mlx.ptr)
		ft_free_exit(13, cube);
	cube->mlx.window = mlx_new_window(cube->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!cube->mlx.window)
		ft_free_exit(14, cube);
	ft_new_image(cube);
	//mlx_loop_hook(cube->mlx.ptr, &ft_render, NULL);
	draw_walls(cube);
	mlx_key_hook(cube->mlx.window, &handle_input, cube);
	mlx_hook(cube->mlx.window, 17, 0, &handle_window_close, cube);
	mlx_loop(cube->mlx.ptr);
	ft_free_mlx_ptr_cube(cube);
}
