/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:16:36 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/08 15:29:00 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_error_exit(int error_message)
{
	if (error_message == 1)
		ft_putstr_fd("cub3D: too may arguments\n", 2);
	else if (error_message == 2)
		ft_putstr_fd("cub3D: file required\n", 2);
	else if (error_message == 3)
		ft_putstr_fd("cub3D: file with .cub extension necessary\n", 2);
	exit(error_message);
}
