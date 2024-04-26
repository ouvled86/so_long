/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:38:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 23:41:26 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"
#include "../../mlx/mlx.h"

void	update_collectibles(int keycode, int *x, int *y, int *c, char **map)
{
	if (keycode == 0 && map[*y][*x - 1] == 'C')
		(*c)--;
	if (keycode == 2 && map[*y][*x + 1] == 'C')
		(*c)--;
	if (keycode == 13 && map[*y - 1][*x] == 'C')
		(*c)--;
	if (keycode ==  1 && map[*y + 1][*x] == 'C')
		(*c)--;
}

void	moves_print(int keycode, int *x, int *y, int *moves, char **map)
{
	int	f;
	
	f = 0;
	if (keycode == 0 && map[*y][*x - 1] != '1' && map[*y][*x - 1] != 'E')
		f = 1;
	if (keycode == 2 && map[*y][*x + 1] != '1' && map[*y][*x + 1] != 'E')
		f = 1;
	if (keycode == 13 && map[*y - 1][*x] != '1' && map[*y - 1][*x] != 'E')
		f = 1;
	if (keycode ==  1 && map[*y + 1][*x] != '1' && map[*y + 1][*x] != 'E')
		f = 1;
	if (f == 1)
	{
		(*moves)++;
		printf("You have moved %d times\n", *moves);
	}
}

int	win_game(int keycode, int *x, int *y, int *c, char **map)
{
	if (keycode == 13 && map[*y - 1][*x] == 'E' && *c == 0)
		return (1);
	else if (keycode == 1 && map[*y + 1][*x] == 'E' && *c == 0)
		return (1);
	else if (keycode == 2 && map[*y][*x + 1] == 'E' && *c == 0)
		return (1);
	else if (keycode == 0 && map[*y][*x - 1] == 'E' && *c == 0)
		return (1);
	return (0);
}

int	movement_handler(int keycode, t_all_data *all)
{
	char	**map;
	static int		moves;
	int		x;
	int		y;

	map = all->assets->map;
	x = all->assets->player.x;
	y = all->assets->player.y;
	moves_print(keycode, &x, &y, &moves, map);
	if (keycode == 53)
		esc_handler(keycode, all);
	if (win_game(keycode, &x, &y, &all->assets->collectibles, map))
	{
		moves++;
		printf("You have moved %d times\nCongratulations! You won.\n", moves);
		exit (0);
	}
	if (all->assets->collectibles == 0)
		wasd_unlocked(keycode, &x, &y, &all->assets->collectibles, map);
	else
		wasd_handler(keycode, &x, &y, &all->assets->collectibles, map);
	all->assets->player.x = x;
	all->assets->player.y = y;
	return (0);
}
