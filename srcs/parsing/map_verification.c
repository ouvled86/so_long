/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 21:52:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/27 00:38:05 by ouel-bou         ###   ########.fr       */
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
	wall[i] = '\n';
	wall[i + 1] = '\0';
	return (wall);
}

static bool	is_rectangular(char **map, char *map_path)
{
	int	i;
	int	j;
	int	lines;

	j = 0;
	lines = lines_count(map_path);
	while (map[j] && j < lines - 1)
	{
		i = ft_strlen(map[j]);
		if (i != ft_strlen(map[lines - 1]) + 1)
			return (false);
		j++;
	}
	return (true);
}

static bool	is_enclosed(char **map, char *map_path)
{
	int		j;
	int		lines;
	int		length;
	char	*wall;

	j = 0;
	length = ft_strlen(map[0]);
	lines = lines_count(map_path);
	wall = set_wall(length);
	while (map[j])
	{
		if (map[j][0] != '1' || map[j][length - 2] != '1')
			return (false);
		j++;
	}
	if (ft_strncmp(map[0], wall, length - 2))
		return (false);
	if (ft_strncmp(map[lines - 1], wall, length - 2))
		return (false);
	free (wall);
	return (true);
}

static bool	is_wrong(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'P' 
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != '\n')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	is_valid(char **map, char *map_path)
{
	if (!is_rectangular(map, map_path))
		err_func("Map is not rectangular", NULL, map);
	if (!is_enclosed(map, map_path))
		err_func("Map is not enclosed", NULL, map);
	if (is_wrong(map))
		err_func("Map keys are wrong", NULL, map);
	return (true);
}
