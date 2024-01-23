/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:07 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 12:15:52 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_mlx_pixel_put(t_img image, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = image.addr + (y * image.line_len + x * (image.bpp / 8));
	*(unsigned int *)pixel = color;
}

t_img	ft_new_image(t_cub *cube, char *img_source)
{
	t_img	image;

	image.ref = mlx_xpm_file_to_image(cube->mlx.ptr, img_source, \
	&image.size.x, &image.size.y);
	image.addr = mlx_get_data_addr(image.ref, \
	&(image.bpp), &(image.line_len), &(image.endian));
	return (image);
}

static int	handle_input(int keysym, t_cub *cube)
{
	if (keysym == 53)
		ft_free_mlx_ptr_cube(cube);
	else if (keysym == LEFT)
		ft_movement_left(cube);
	else if (keysym == FORWARD)
		ft_movement_forward(cube);
	else if (keysym == RIGHT)
		ft_movement_right(cube);
	else if (keysym == BACKWARD)
		ft_movement_backward(cube);
	else if (keysym == ROTATE_RIGHT)
		ft_rotate_right(cube);
	else if (keysym == ROTATE_LEFT)
		ft_rotate_left(cube);
	return (0);
}

static int	handle_window_close(t_cub *cube)
{
	ft_free_mlx_ptr_cube(cube);
	return (0);
}

void	mlx_main(t_cub *cube)
{
	cube->mlx.ptr = mlx_init();
	if (!cube->mlx.ptr)
		ft_free_exit(13, cube);
	cube->mlx.window = mlx_new_window(cube->mlx.ptr, SCREEN_WIDTH, \
	SCREEN_HEIGHT, "cub3D");
	if (!cube->mlx.window)
		ft_free_exit(14, cube);
	cube->mlx.img.ref = mlx_new_image(cube->mlx.ptr, SCREEN_WIDTH, \
	SCREEN_HEIGHT);
	cube->mlx.img.addr = mlx_get_data_addr(cube->mlx.img.ref, \
	&(cube->mlx.img.bpp), &(cube->mlx.img.line_len), &(cube->mlx.img.endian));
	stock_xpm_images(cube);
	render_map(cube);
	mlx_hook(cube->mlx.window, 2, 0, &handle_input, cube);
	mlx_hook(cube->mlx.window, 17, 0, &handle_window_close, cube);
	mlx_loop(cube->mlx.ptr);
	ft_free_mlx_ptr_cube(cube);
}
