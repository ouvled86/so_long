/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:52:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/21 22:23:09 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static char	*set_wall(int length)
{
	int		i;
	char	*wall;

	i = 0;
	wall = (char *)malloc(length);
	while (i < length)
	{
		wall[i] = '1';
		i++;
	}
	wall[i] = '\0';
	return (wall);
}

static bool	is_rectangular(char **map)
{
	int	i;
	int	j;

	if (!map)
		return ;
	i = 0;
	j = 1;
	while (map[j])
	{
		while (map[j][i])
			i++;
		if (i != ft_strlen(map[0]))
			return (false);
		j++;
	}
	return (true);
}

static bool	is_enclosed(char **map, char *map_path)
{
	int		i;
	int		j;
	int		lines;
	int		length;
	char	*wall;

	i = 0;
	j = 0;
	if (!map || !map_path)
		return ;
	length = ft_strlen(map[0]);
	lines = lines_count(map_path);
	wall = set_wall(length);
	if (!wall)
		return ;
	if (map[j][0] != '1' || map[j][length - 1] != '1')
		return (false);
	if (ft_strncmp(map[0], wall, length))
		return (false);
	if (ft_strncmp(map[lines - 1], wall, length))
		return (false);
	free (wall);
	return (true);
}

bool	is_valid(char **map, char *map_path)
{
	if (is_rectangular(map) && is_enclosed(map, map_path))
		return (true);
	return (false);
}
