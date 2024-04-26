/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wasd_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:08:26 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 22:08:55 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"

void	wasd_handler(int keycode, int *x, int *y, int *c, char **map)
{
	update_collectibles(keycode, x, y, c, map);
	if (keycode == 13 && map[*y - 1][*x] != '1' && map[*y - 1][*x] != 'E')
	{
		map[*y][*x] = '0';
		map[*y - 1][*x] = 'P';
		(*y)--;
	}
	else if (keycode == 1 && map[*y + 1][*x] != '1' && map[*y + 1][*x] != 'E')
	{
		map[*y][*x] = '0';
		map[*y + 1][*x] = 'P';
		(*y)++;
	}
	else if (keycode == 2 && map[*y][*x + 1] != '1' && map[*y][*x + 1] != 'E')
	{
		map[*y][*x] = '0';
		map[*y][*x + 1] = 'P';
		(*x)++;
	}
	else if (keycode == 0 && map[*y][*x - 1] != '1' && map[*y][*x - 1] != 'E')
	{
		map[*y][*x] = '0';
		map[*y][*x - 1] = 'P';
		(*x)--;
	}
}

void	wasd_unlocked(int keycode, int *x, int *y, int *c, char **map)
{
	update_collectibles(keycode, x, y, c, map);
	if (keycode == 13 && map[*y - 1][*x] != '1')
	{
		map[*y][*x] = '0';
		map[*y - 1][*x] = 'P';
		(*y)--;
	}
	else if (keycode == 1 && map[*y + 1][*x] != '1')
	{
		map[*y][*x] = '0';
		map[*y + 1][*x] = 'P';
		(*y)++;
	}
	else if (keycode == 2 && map[*y][*x + 1] != '1')
	{
		map[*y][*x] = '0';
		map[*y][*x + 1] = 'P';
		(*x)++;
	}
	else if (keycode == 0 && map[*y][*x - 1] != '1')
	{
		map[*y][*x] = '0';
		map[*y][*x - 1] = 'P';
		(*x)--;
	}
}
