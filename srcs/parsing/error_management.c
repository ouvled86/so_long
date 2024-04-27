/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:05:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/27 01:08:47 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

char	*extract_path(char *path)
{
	char	*map_path;

	map_path = NULL;
	if (path)
		map_path = path;
	return (map_path);
}

void	err_func(char *display_msg, t_assets *a, char **map)
{
	if (display_msg)
		printf("Error\n%s\n", display_msg);
	if (map)
		map = freemem(map);
	if (a)
		free (a);
	exit (1);
}
