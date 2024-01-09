/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:28:21 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/09 12:22:34 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	ft_printf_map_error(char *element, bool *error)
{
	ft_putstr_fd("cub3D: element: ", 2);
	ft_putstr_fd(element, 2);
	ft_putstr_fd(" mentioned twice\n", 2);
	(*error) = false;
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
	if (elem == SO)
		if (cube->so != NULL)
			ft_printf_map_error("SO", &error);
	if (elem == WE)
		if (cube->we != NULL)
			ft_printf_map_error("WE", &error);
	if (elem == EA)
		if (cube->ea != NULL)
			ft_printf_map_error("EA", &error);
	if (elem == C)
		if (cube->c != NULL)
			ft_printf_map_error("C", &error);
	if (elem == F)
		if (cube->f != NULL)
			ft_printf_map_error("F", &error);
	return (error);
}

static char	*get_elem_value(enum e_elem elem)
{
	if (elem == NO)
		return (ft_strdup("NO"));
	if (elem == SO)
		return (ft_strdup("SO"));
	if (elem == WE)
		return (ft_strdup("WE"));
	if (elem == EA)
		return (ft_strdup("EA"));
	if (elem == C)
		return (ft_strdup("C"));
	if (elem == F)
		return (ft_strdup("F"));
	return (NULL);
}

bool	allocate_line(char *line, t_cub *cube)
{
	enum e_elem	elem;
	char		*elem_value;

	elem = 0;
	while (elem < 6)
	{
		elem_value = get_elem_value(elem);
		if (!ft_strncmp(line, elem_value, ft_strlen(elem_value)))
		{
			if (!check_for_doubles(cube, elem))
				return (false);
			else
				retrieve_line(line, cube, elem);
			break ;
		}
		free(elem_value);
		elem++;
	}
	if (ft_strrchr(line, '1' || ft_strrchr(line, '0')))
		cube->map = ft_arrayadd(line, cube->map);
	return (true);
}
