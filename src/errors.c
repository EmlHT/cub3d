/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:16:36 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/10 10:40:57 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_error_exit(int error_message)
{	
	if (error_message == 1)
		ft_putstr_fd("cub3D: please add a map file as an argument\n", 2);
	else if (error_message == 2)
		ft_putstr_fd("cub3D: map file should not be a directory\n", 2);
	else if (error_message == 3)
		ft_putstr_fd("cub3D: file does not exist/access denied\n", 2);
	else if (error_message == 4)
		ft_putstr_fd("cub3D: map file with .cub extension necessary\n", 2);
	exit(error_message);
}

void	ft_free_exit(int error_message, t_cub *cube)
{
	if (error_message == 6)
		ft_putstr_fd("cub3D: file does not open\n", 2);
	if (cube->map || cube->map[0])
		ft_arrayfree(cube->map);
	if (cube->no)
		free(cube->no);
	if (cube->so)
		free(cube->so);
	if (cube->we)
		free(cube->we);
	if (cube->ea)
		free(cube->ea);
	if (cube->c)
		free(cube->c);
	if (cube->f)
		free(cube->f);
	exit(error_message);
}
