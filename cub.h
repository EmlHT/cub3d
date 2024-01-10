/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:58:55 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/08 15:24:37 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	CUB_H
# define CUB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"

typedef struct s_cub
{
	int		i;
	void	*mlx;
}	t_cub;

void	parsing_main(int argc, char **argv, t_cub *cube);
void	ft_error_exit(int error_message);


#endif