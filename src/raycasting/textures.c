/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:03:49 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/18 18:09:40 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	rgb_to_hex(int red, int green, int blue)
{
	int hex_value;

	hex_value = (red << 16) | (green << 8) | blue;
	return (hex_value);
}

void	fill_colors(t_cub *cube, int red, int green, int blue)
{
	
}

void	color_ceiling_floor(t_cub *cube)
{
	int	i;
    int	j;

    i = -1;
	fill_colors(cube->c_colours->r, cube->c_colours->g, cube->c_colours->b);
    fill_colors(cube->f_colours->r, cube->f_colours->g, cube->f_colours->b);
	while (++i < SCREEN_HEIGHT)
    {
        j = -1;
        while (++j < SCREEN_WIDTH)
		{
			if (i < SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(cube->mlx.img, j, i, rgb_to_hex(cube->c_colours->r, cube->c_colours->g, cube->c_colours->b));
			else
				my_mlx_pixel_put(cube->mlx.img, j, i, rgb_to_hex(cube->f_colours->r, cube->f_colours->g, cube->f_colours->b));
		}
    }
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
