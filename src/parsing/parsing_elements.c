/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:36:32 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/10 18:41:14 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int check_textures(char *elem, int *ret_value)
{
	char	**dest;
	int		fd;

	dest = ft_split_isspace(elem);
	fd = open(dest[1], O_RDONLY);
	if (fd == -1 || ft_arraylen(dest) > 2)
	{
		*ret_value = 6;
		return (*ret_value);
	}
	close(fd);
	free(elem);
	elem = ft_strdup(dest[1]);
	ft_arrayfree(dest);
	return (*ret_value);
}

static char *check_ceiling_floor(char *elem, int *ret_value)
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
	int	ret_value;
	
	ret_value = -1;
	if (check_textures(cube->no, &ret_value) != -1)
    	ft_free_exit(ret_value, cube);
	if (check_textures(cube->so, &ret_value) != -1)
    	ft_free_exit(ret_value, cube);
	if (check_textures(cube->we, &ret_value) != -1)
    	ft_free_exit(ret_value, cube);
	if (check_textures(cube->ea, &ret_value) != -1)
    	ft_free_exit(ret_value, cube);
    cube->c = check_ceiling_floor(cube->c, &ret_value);
	if (ret_value != -1)
    	ft_free_exit(ret_value, cube);
	cube->f = check_ceiling_floor(cube->f, &ret_value);
	if (ret_value != -1)
    	ft_free_exit(ret_value, cube);
}
