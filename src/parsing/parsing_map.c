/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:22:47 by ehouot            #+#    #+#             */
/*   Updated: 2024/01/22 08:52:52 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static bool	check_wrong_char(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!is_valid_char(map[y][x]) && !ft_isspace(map[y][x]))
				return (false);
		}
	}
	return (true);
}

static bool	check_player_loc(char **map, t_cub *cube)
{
	int	y;
	int	x;
	int	check_loc;

	y = -1;
	check_loc = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' \
				|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				check_loc++;
				cube->mlx.player_start_dir = map[y][x];
			}
			if (check_loc > 1)
				return (false);
		}
	}
	if (check_loc == 0)
		return (false);
	return (true);
}

static bool	check_map_closed(char **map, int x, int y)
{
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' \
			|| map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (!is_valid_char(map[y - 1][x]) \
				|| !is_valid_char(map[y - 1][x + 1]))
					return (false);
				if (!is_valid_char(map[y + 1][x]) \
				|| !is_valid_char(map[y + 1][x - 1]))
					return (false);
				if (!is_valid_char(map[y][x - 1]) \
				|| !is_valid_char(map[y - 1][x - 1]))
					return (false);
				if (!is_valid_char(map[y][x + 1]) \
				|| !is_valid_char(map[y + 1][x + 1]))
					return (false);
			}
		}
	}
	return (true);
}

void	parse_map(t_cub *cube)
{
	int	x;
	int	y;

	y = -1;
	x = -1;
	if (!check_wrong_char(cube->map))
		ft_free_exit(11, cube);
	if (!check_map_closed(cube->map, x, y))
		ft_free_exit(10, cube);
	if (!check_player_loc(cube->map, cube))
		ft_free_exit(12, cube);
}
