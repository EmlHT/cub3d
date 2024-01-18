/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:03:49 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/18 17:05:39 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
