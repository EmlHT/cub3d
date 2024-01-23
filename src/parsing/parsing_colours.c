/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 08:46:18 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 08:46:46 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	comma_count(char *colour_char)
{
	int	i;
	int	comma;

	i = -1;
	comma = 0;
	while (colour_char[++i])
		if (colour_char[i] == ',')
			comma++;
	return (comma);
}

static t_colours	*retrieve_colour_values(t_cub *cube, char *colour_char)
{
	char		**tmp;
	t_colours	*colour_combo;

	colour_combo = ft_calloc(1, sizeof(t_colours));
	colour_combo->r = 0;
	colour_combo->g = 0;
	colour_combo->b = 0;
	tmp = ft_split(colour_char, ',');
	if (ft_arraylen(tmp) != 3)
	{
		free(colour_combo);
		ft_arrayfree(tmp);
		ft_free_exit(8, cube);
	}
	colour_combo->r = ft_atoi(tmp[0]);
	colour_combo->g = ft_atoi(tmp[1]);
	colour_combo->b = ft_atoi(tmp[2]);
	if (colour_combo->r > 255 || colour_combo->g > 255 || colour_combo->b > 255)
	{
		free(colour_combo);
		ft_arrayfree(tmp);
		ft_free_exit(9, cube);
	}
	ft_arrayfree(tmp);
	return (colour_combo);
}

void	check_colour_values(t_cub *cube)
{
	if (comma_count(cube->c) != 2 || comma_count(cube->f) != 2)
		ft_free_exit(8, cube);
	if (cube->c[0] == ',' || cube->f[0] == ',')
		ft_free_exit(8, cube);
	cube->c_colours = retrieve_colour_values(cube, cube->c);
	cube->f_colours = retrieve_colour_values(cube, cube->f);
}
