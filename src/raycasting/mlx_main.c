/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:41:07 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/18 16:33:14 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// static void verLine(int x, int drawStart, int drawEnd, int color, t_cub *cube)
// {
// 	for (int y = drawStart; y <= drawEnd; y++)
// 	{
// 		mlx_pixel_put(cube->mlx.ptr, cube->mlx.window, x, y, color);
//     }
// }

// int     get_pixel_color(t_mlx *data, int x, int y)
// {
//         char    *dst;

//         dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
//         return (*(unsigned int *)dst);
// }

// void    apply_texture(t_config **conf, int dir, int x, int y)
// {
//         int             color;
//         t_ray   *r;

//         color = 0;
//         r = (*conf)->ray;
//         if (dir == NORTH)
//                 color = get_pixel_color(&(*conf)->text[NORTH], r->tex_x, r->tex_y);
//         else if (dir == SOUTH)
//                 color = get_pixel_color(&(*conf)->text[SOUTH], r->tex_x, r->tex_y);
//         else if (dir == EAST)
//                 color = get_pixel_color(&(*conf)->text[EAST], r->tex_x, r->tex_y);
//         else if (dir == WEST)
//                 color = get_pixel_color(&(*conf)->text[WEST], r->tex_x, r->tex_y);
//         my_mlx_pixel_put((*conf)->mlx, x, y, color);
// }

// int     draw_walls(t_config **conf, t_ray *ray, int x)
// {
//         int     dir;

//         dir = -1;
//         draw_floor_sky(conf, ray->draw_start, x);
//         while (ray->draw_start < ray->draw_end)
//         {
//                 ray->tex_y = (int)ray->text_pos & (TEXTURE_H - 1);
//                 ray->text_pos += ray->step_text;
//                 dir = find_orientation(ray, (*conf)->usr);
//                 if (dir == -1)
//                         return (-1);
//                 apply_texture(conf, dir, x, ray->draw_start);
//                 ray->draw_start++;
//         }
//         return (SUCCESS);
// }

// void    my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
// {
//         char    *dst;

//         dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
//         *(unsigned int *)dst = color;
// }

// void	my_img_pix_put(t_img img, int x, int y, int color)
// {
//     char    *pixel;
//     int		i;

//     i = img.bpp - 8;
//     pixel = img.addr + (y * img.line_len + x * (img.bpp / 8));
//     while (i >= 0)
//     {
//         /* big endian, MSB is the leftmost bit */
//         if (img.endian != 0)
//             *pixel++ = (color >> i) & 0xFF;
//         /* little endian, LSB is the leftmost bit */
//         else
//             *pixel++ = (color >> (img.bpp - 8 - i)) & 0xFF;
//         i -= 8;
//     }
// }

void	my_mlx_pixel_put(t_img image, int x, int y, unsigned int color)
{
    char		*pixel;

    pixel = image.addr + (y * image.line_len + x * (image.bpp / 8));
	*(unsigned int *)pixel = color;
}

static unsigned int	get_pixel_color(t_img image, int x, int y)
{
	char    *color;

	color = image.addr + (y * image.line_len + x * (image.bpp / 8));
	return (*(unsigned int *)color);
}

void	draw_texture(t_cub *cube, int x)
{
	int				y;
	unsigned int	color;

	y = cube->mlx.draw_start;
	while (y < cube->mlx.draw_end)
	{
		cube->mlx.tex.y = (int)cube->mlx.tex.pos & TEXTURE_HEIGHT - 1;
		cube->mlx.tex.pos += cube->mlx.tex.step;
		color = get_pixel_color(cube->mlx.xpm_img.no, cube->mlx.tex.x, cube->mlx.tex.y);
		my_mlx_pixel_put(cube->mlx.img, x, y, color);
		y++;
	}
}

void	draw_walls(t_cub *cube)
{
	int	x;

    x = -1;
	render_background(cube);
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
		
		//initialising varibales for determining if a wall has been hit, wall distance, which side (x or y)
		
		cube->mlx.perp_wall_dist = 0;
		cube->mlx.wall_x = 0;
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
		{
			cube->mlx.perp_wall_dist = cube->mlx.side_dist.x - cube->mlx.delta_dist.x;
			cube->mlx.wall_x = cube->mlx.pos.y + cube->mlx.perp_wall_dist * cube->mlx.ray.y;
		}
		else
		{
			cube->mlx.perp_wall_dist = cube->mlx.side_dist.y - cube->mlx.delta_dist.y;
			cube->mlx.wall_x = cube->mlx.pos.x + cube->mlx.perp_wall_dist * cube->mlx.ray.x;
		}
		cube->mlx.wall_x -= floor(cube->mlx.wall_x);
		
		//calculate texture colour for put_pixel on wall coordinate
		
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
		cube->mlx.tex.pos = ((cube->mlx.draw_start - SCREEN_HEIGHT / 2 + cube->mlx.height / 2) * cube->mlx.tex.step);
		
		draw_texture(cube, x);
    }
	mlx_put_image_to_window(cube->mlx.ptr, cube->mlx.window, cube->mlx.img.ref, 0, 0);
}

void	render_background(t_cub *cube)
{
    int	i;
    int	j;

    i = 0;
    while (i < SCREEN_HEIGHT)
    {
        j = 0;
        while (j < SCREEN_WIDTH)
		{
			my_mlx_pixel_put(cube->mlx.img, j, i, 0x000000);
			j++;
		}
        i++;
    }
}

t_img	ft_new_image(t_cub *cube, char *img_source)
{
	t_img	image;
	
	image.ref = mlx_xpm_file_to_image(cube->mlx.ptr, img_source, &image.size.x, &image.size.y);
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
	cube->mlx.img.ref = mlx_new_image(cube->mlx.ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	cube->mlx.img.addr = mlx_get_data_addr(cube->mlx.img.ref, \
    	&(cube->mlx.img.bpp), &(cube->mlx.img.line_len), &(cube->mlx.img.endian));
	stock_xpm_images(cube);
	//mlx_loop_hook(cube->mlx.ptr, &ft_render, NULL);
	draw_walls(cube);
	mlx_hook(cube->mlx.window, 2, 0, &handle_input, cube);
	mlx_hook(cube->mlx.window, 17, 0, &handle_window_close, cube);
	mlx_loop(cube->mlx.ptr);
	ft_free_mlx_ptr_cube(cube);
}
