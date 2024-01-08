/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:28:21 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/08 18:37:30 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_print_map_error(char *element, bool *error)
{
	ft_putstr_fd("cub3D: element: ", 2);
	ft_putstr_fd(element, 2);
	ft_putstr_fd(" mentioned twice\n", 2);
	error = false;
}

static void	retrieve_line(char *line, t_cub *cube, enum e_elem elem)
{
	if (elem == NO)
		cube->no = ft_strdup(line);
	else if (elem == SO)
		cube->so = ft_strdup(line);
	else if (elem == WE)
		cube->we = ft_strdup(line);
	else if (elem == EA)
		cube->ea = ft_strdup(line);
	else if (elem == C)
		cube->c = ft_strdup(line);
	else if (elem == F)
		cube->f = ft_strdup(line);
}

static bool	check_for_doubles(t_cub *cube, enum e_elem elem)
{
	bool	error;

	error = true;
	if (elem == NO)
		if (cube->no != NULL)
			ft_printf_map_error("NO", &error);
	else if (elem == SO)
		if (cube->so != NULL)
			ft_printf_map_error("SO", &error);
	else if (elem == WE)
		if (cube->we != NULL)
			ft_printf_map_error("WE", &error);
	else if (elem == EA)
		if (cube->ea != NULL)
			ft_printf_map_error("EA", &error);
	else if (elem == C)
		if (cube->c != NULL)
			ft_printf_map_error("C", &error);
	else if (elem == F)
		if (cube->f != NULL)
			ft_printf_map_error("F", &error);
	return (error);
}

char	**ft_arrayadd(char *newline, char **array)
{
	char	**tmp;
	int		i;

	if (!array)
		return (NULL);
	i = -1;
	tmp = ft_calloc(ft_arraylen(array) + 2, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (array[++i])
		tmp[i] = ft_strdup(array[i]);
	tmp[i] = ft_strdup(newline);
	ft_arrayfree(array);
	return (tmp);
}

bool	allocate_line(char *line, t_cub *cube)
{
	enum e_elem	elem;

	elem = 0;
	while (elem < 5)
	{
		if (!ft_strncmp(line, elem, ft_strlen(elem)))
		{
			if (!check_for_doubles(cube, elem))
				return (false);
			else
				retrieve_line(line, cube, elem);
			break ;
		}
		elem++;
	}
	if (line contient 1 ou 0) //a travailler dessus demain matin à Starbucks
	{
		cube->map = ft_arrayadd(line, cube->map);
	}
}
