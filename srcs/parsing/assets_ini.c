/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_ini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 22:25:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/21 23:28:58 by ouel-bou         ###   ########.fr       */
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

static int	set_c_count(char **map)
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

static t_pos	*set_p_pos(char **map)
{
	int		i;
	int		j;
	t_pos	*p_pos;

	i = 0;
	p_pos = (t_pos *)malloc(sizeof(t_pos *));
	if (!p_pos)
		return (NULL);
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
		{
			p_pos->x = j;
			p_pos->y = i;
		}
		i++;
	}
	return (p_pos);
}

static t_pos	*set_e_pos(char **map)
{
	int		i;
	int		j;
	t_pos	*e_pos;

	i = 0;
	e_pos = (t_pos *)malloc(sizeof(t_pos *));
	if (!e_pos)
		return (NULL);
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != 'E')
			j++;
		if (map[i][j] == 'E')
		{
			e_pos->x = j;
			e_pos->y = i;
		}
		i++;
	}
	return (e_pos);
}

t_assets	*assets_ini(char **map, char *map_path)
{
	t_assets	*assets;

	assets = (t_assets *)malloc(sizeof(t_assets));
	if (!map || !uniq_p_e(map) || set_c_count(map) < 1)
		return (NULL);
	if (!is_valid(map, map_path))
		return (NULL);
	assets->map = map;
	assets->player = set_p_pos(map);
	assets->exit = set_e_pos(map);
	assets->collectibles = set_c_count(map);
	return (assets);
}
