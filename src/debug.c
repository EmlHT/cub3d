/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brettleclerc <brettleclerc@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:58:43 by brettlecler       #+#    #+#             */
/*   Updated: 2024/01/10 10:58:41 by brettlecler      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_map(t_cub *cube)
{
	int	i;

	i = -1;
	printf("--- CUBE MAP ---\n");
	while (cube->map[++i])
		printf("%s", cube->map[i]);
}

void	print_elements(t_cub *cube)
{
	printf("--- CUBE ELEMENTS ---\n");
	printf("cube NO: %s", cube->no);
	printf("cube SO: %s", cube->so);
	printf("cube WE: %s", cube->we);
	printf("cube EA: %s", cube->ea);
	printf("cube C: %s", cube->c);
	printf("cube F: %s\n", cube->f);
}