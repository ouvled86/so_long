/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:56:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/21 19:51:08 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	lines_count(char *map_path)
{
	char	*s;
	int		fd;
	int		c;

	fd = open(map_path, O_RDONLY);
	s = get_next_line(fd);
	c = 0;
	while (s)
	{
		c++;
		s = get_next_line(fd);
	}
	close (fd);
	return (c);
}

char	**read_map(char *map_path)
{
	char	**map;
	int		lines;
	int		fd;
	int		i;

	lines = lines_count(map_path);
	fd = open(map_path, O_RDONLY);
	map = (char **)malloc(lines * sizeof(char *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			return (NULL); // Error function required!
		i++;
	}
	map[lines] = NULL;
	return (map);
}
