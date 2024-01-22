/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:36:32 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/22 08:46:40 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static char	*check_textures(char *elem, int *ret_value, char *elem_value)
{
	char	**dest;
	int		fd;

	dest = ft_split_isspace(elem);
	fd = open(dest[1], O_RDONLY);
	if (fd == -1 || ft_arraylen(dest) > 2 \
		|| ft_strncmp(dest[0], elem_value, ft_strlen(elem_value) + 1))
	{
		*ret_value = 6;
		if (fd != -1)
			close(fd);
		free(elem);
		ft_arrayfree(dest);
		return (NULL);
	}
	close(fd);
	free(elem);
	elem = ft_strdup(dest[1]);
	ft_arrayfree(dest);
	return (elem);
}

static char	*check_ceiling_floor(char *elem, int *ret_value)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	dest = ft_split_isspace(elem);
	i = 0;
	free(elem);
	elem = NULL;
	while (dest[++i])
	{
		j = -1;
		while (dest[i][++j])
		{
			if (!ft_isdigit(dest[i][j]) && dest[i][j] != ',')
			{
				ft_arrayfree(dest);
				*ret_value = 7;
				return (NULL);
			}
		}
		elem = ft_strjoin_dol(elem, dest[i]);
	}
	ft_arrayfree(dest);
	return (elem);
}

void	parse_cube(t_cub *cube)
{
	int			ret_value;

	ret_value = -1;
	cube->no = check_textures(cube->no, &ret_value, "NO");
	cube->so = check_textures(cube->so, &ret_value, "SO");
	cube->we = check_textures(cube->we, &ret_value, "WE");
	cube->ea = check_textures(cube->ea, &ret_value, "EA");
	if (ret_value != -1)
		ft_free_exit(ret_value, cube);
	cube->c = check_ceiling_floor(cube->c, &ret_value);
	cube->f = check_ceiling_floor(cube->f, &ret_value);
	if (ret_value != -1)
		ft_free_exit(ret_value, cube);
	check_colour_values(cube);
}
