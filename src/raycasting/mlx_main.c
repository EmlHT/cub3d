/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:07 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/12 17:10:36 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	handle_window_close(t_cub *cube)
{
	ft_free_mlx_ptr_cube(cube);
	return (0);
}

static int	ft_render(void)
{
	return (0);
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

void	mlx_main(t_cub *cube)
{
	cube->mlx.ptr = mlx_init();
	if (!cube->mlx.ptr)
		ft_free_exit(13, cube);
	cube->mlx.window = mlx_new_window(cube->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!cube->mlx.window)
		ft_free_exit(14, cube);
	mlx_loop_hook(cube->mlx.ptr, &ft_render, cube);
	mlx_key_hook(cube->mlx.window, &handle_input, cube);
	mlx_hook(cube->mlx.window, 17, 0, &handle_window_close, cube);
	mlx_loop(cube->mlx.ptr);
	ft_free_mlx_ptr_cube(cube);
}
