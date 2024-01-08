/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:16:36 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/08 17:13:48 by brettlecler      ###   ########.fr       */
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
		ft_putstr_fd("cub3D: map file with .cub extension necessary\n", 2);
	else if (error_message == 4)
		ft_putstr_fd("cub3D: file does not exist\n", 2);
	else if (error_message == 5)
		ft_putstr_fd("cub3D: access denied\n", 2);
	else if (error_message == 6)
		ft_putstr_fd("cub3D: file does not open\n", 2);
	exit(error_message);
}
