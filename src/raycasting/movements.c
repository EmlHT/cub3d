/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehouot <ehouot@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:01:11 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/16 17:39:26 by ehouot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_movement_a(t_cub *cube)
{
	
}

void	ft_movement_w(t_cub *cube)
{
	// if (cube->map[cube->mlx.pos.y - 1][cube->mlx.pos.x] == '1')
	// 	break ;
	// else
	if(cube->map[(cube->mlx.pos.x + cube->mlx.dir.x * moveSpeed)][int(posY)] == false) posX += dirX * moveSpeed;
	if(cube->map[(cube->mlx.pos.x)][int(cube->mlx.pos.y + cube->mlx.dir.y * moveSpeed)] == false) posY += dirY * moveSpeed;
}

void	ft_movement_d(t_cub *cube)
{
	
}

void	ft_movement_s(t_cub *cube)
{
	
}
