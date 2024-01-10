/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:36:32 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/10 12:41:54 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// char	*ft_stradd_char(char *s1, char c)
// {
// 	size_t	i;
// 	char	*dest;

// 	i = -1;
// 	if (!s1)
// 		dest = ft_calloc(2, sizeof(char *));
// 	else
// 		dest = ft_calloc(ft_strlen(s1) + 2, sizeof(char *));
// 	if (!dest)
// 		return (NULL);
// 	if (!s1)
// 	{
// 		dest[0] = c;
// 		dest[1] = '\0';
// 		return (dest);
// 	}
// 	while (s1[++i])
// 		dest[i] = s1[i];
// 	dest[i++] = c;
// 	dest[i] = '\0';
// 	free(s1);
// 	return (dest);
// }

static bool check_textures(char *elem, char *cardinal)
{
	char	**dest;
	
	dest = ft_split_isspace(elem);
	if (!ft_strncmp(dest[0], cardinal, ft_strlen(cardinal)))
		return (false);
	return (true);
}

static bool check_ceiling_floor(t_cub *cube, char *elem)
{
    
}

void	parse_cube(t_cub *cube)
{
	if (!check_textures(cube->no, "NO"))
    	ft_free_exit();
	if (!check_textures(cube->so, "SO"))
    	ft_free_exit();
	if (!check_textures(cube->we, "WE"))
    	ft_free_exit();
	if (!check_textures(cube->ea, "EA"))
    	ft_free_exit();
    if (!check_ceiling_floor(cube))
    	ft_free_exit(); 
)

}
