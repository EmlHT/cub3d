/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:20:13 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/19 08:49:23 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	stock_xpm_images(t_cub *cube)
{
	cube->mlx.xpm_img.no = ft_new_image(cube, cube->no);
	cube->mlx.xpm_img.so = ft_new_image(cube, cube->so);
	cube->mlx.xpm_img.we = ft_new_image(cube, cube->we);
	cube->mlx.xpm_img.ea = ft_new_image(cube, cube->ea);
}

void	render_map(t_cub *cube)
{
	int	x;

    x = -1;
	color_ceiling_floor(cube);
    while (++x < SCREEN_WIDTH)
    {
        init_ray(cube, x);
        init_ray_direction(cube);
		perform_dda_algorithm(cube);
		calculate_wall_distance(cube);
		calculate_texture_coordinates(cube);
		draw_texture(cube, x);
    }
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.window, cube->mlx.img.ref, 0, 0);
}
