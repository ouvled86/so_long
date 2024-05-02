/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:25:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/02 11:48:31 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static bool	uniq_p_e(char **map)
{
	int	i;
	int	j;
	int	p;
	int	e;

	i = 0;
	p = 0;
	e = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1)
		return (false);
	return (true);
}

int	set_c_count(char **map)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

static t_pos	set_p_pos(char **map)
{
	int		i;
	int		j;
	t_pos	p_pos;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
		{
			p_pos.x = j;
			p_pos.y = i;
		}
		i++;
	}
	return (p_pos);
}

t_assets	*assets_init(char **map, char *map_path)
{
	t_assets	*assets;

	is_valid(map, map_path);
	assets = (t_assets *)malloc(sizeof(t_assets));
	if (!assets)
		return (NULL);
	if (!uniq_p_e(map))
		err_func("Player or exit is not unique", assets, map);
	if (set_c_count(map) < 1)
		err_func("Map does not have any collectibles", assets, map);
	assets->map = map;
	assets->player = set_p_pos(map);
	assets->size.x = ft_strlen(map[0]) - 1;
	assets->size.y = lines_count(map_path);
	assets->collectibles = set_c_count(map);
	return (assets);
}
