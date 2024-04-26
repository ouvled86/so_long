/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:56:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/27 00:37:22 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static bool	file_check(char *map_path)
{
	int	i;
	int	fd;

	i = ft_strlen(map_path) - 4;
	if (ft_strncmp(map_path + i, ".ber", 4) != 0)
		return (false);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	close (fd);
	return (true);
}

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
		free (s);
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

	if (file_check(map_path) == false)
		return (NULL);
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
			err_func("Memory issue", NULL, map);
		i++;
	}
	map[lines] = NULL;
	close (fd);
	return (map);
}

void	flood_fill(char **map, t_pos size, int x, int y)
{
	char	**ffd;

	ffd = map;
	if (!ffd[y][x] || ffd[y][x] == '\n')
		return ;
	if (ffd[y][x] == '1' || ffd[y][x] == 'F' 
		|| x >= size.x || y >= size.y || x < 0 || y < 0)
		return ;
	ffd[y][x] = 'F';
	flood_fill(ffd, size, x + 1, y);
	flood_fill(ffd, size, x - 1, y);
	flood_fill(ffd, size, x, y + 1);
	flood_fill(ffd, size, x, y - 1);
}

bool	is_accessible(char *map_path)
{
	t_assets	*cl_a;
	int			c;
	int			e;
	int			i;
	int			j;

	cl_a = assets_ini(read_map(map_path), map_path);
	flood_fill(cl_a->map, cl_a->size, cl_a->player.x, cl_a->player.y);
	c = set_c_count(cl_a->map);
	e = 0;
	i = 0;
	while (cl_a->map[i])
	{
		j = 0;
		while (cl_a->map[i][j])
		{
			if (cl_a->map[i][j++] == 'E')
				e++;
		}
		i++;
	}
	cl_a->map = freemem(cl_a->map);
	free (cl_a);
	if (c != 0 || e != 0)
		return (false);
	return (true);
}
