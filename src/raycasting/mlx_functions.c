/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:20:13 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/18 10:57:21 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	stock_xpm_images(t_cub *cube)
{
	cube->mlx.xpm_img.bg = ft_new_image(cube, "textures/black_bg.xpm");
	cube->mlx.xpm_img.no = ft_new_image(cube, cube->no);
	cube->mlx.xpm_img.so = ft_new_image(cube, cube->so);
	cube->mlx.xpm_img.we = ft_new_image(cube, cube->we);
	cube->mlx.xpm_img.ea = ft_new_image(cube, cube->ea);
}
