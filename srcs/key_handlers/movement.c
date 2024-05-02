/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:38:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/02 11:39:31 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_handlers.h"
#include "../../mlx/mlx.h"

static int	update_collectibles(int keycode, int *x, int *y, char **map)
{
	int	c;

	c = 0;
	if (c == 0)
		c = set_c_count(map);
	if (keycode == 0 && map[*y][*x - 1] == 'C')
		c--;
	if (keycode == 2 && map[*y][*x + 1] == 'C')
		c--;
	if (keycode == 13 && map[*y - 1][*x] == 'C')
		c--;
	if (keycode == 1 && map[*y + 1][*x] == 'C')
		c--;
	return (c);
}

static void	moves_print(int keycode, int *x, int *y, char **map)
{
	static int	moves;
	int			f;

	f = 0;
	if (keycode == 0 && map[*y][*x - 1] != '1' && map[*y][*x - 1] != 'E')
		f = 1;
	if (keycode == 2 && map[*y][*x + 1] != '1' && map[*y][*x + 1] != 'E')
		f = 1;
	if (keycode == 13 && map[*y - 1][*x] != '1' && map[*y - 1][*x] != 'E')
		f = 1;
	if (keycode == 1 && map[*y + 1][*x] != '1' && map[*y + 1][*x] != 'E')
		f = 1;
	if (f == 1)
	{
		moves++;
		ft_printf("You have moved %d times\n", moves);
	}
}

static int	win_game(int keycode, t_pos p, int c, char **map)
{
	if (keycode == 13 && map[p.y - 1][p.x] == 'E' && c == 0)
		return (1);
	else if (keycode == 1 && map[p.y + 1][p.x] == 'E' && c == 0)
		return (1);
	else if (keycode == 2 && map[p.y][p.x + 1] == 'E' && c == 0)
		return (1);
	else if (keycode == 0 && map[p.y][p.x - 1] == 'E' && c == 0)
		return (1);
	return (0);
}

int	movement_handler(int keycode, t_all_data *all)
{
	char		**map;
	int			x;
	int			y;

	if (keycode == 53)
		esc_handler(keycode, all);
	map = all->assets->map;
	x = all->assets->player.x;
	y = all->assets->player.y;
	moves_print(keycode, &x, &y, map);
	all->assets->collectibles = update_collectibles(keycode, &x, &y, map);
	wasd_handler(keycode, &x, &y, map);
	if (win_game(keycode, all->assets->player, all->assets->collectibles, map))
	{
		ft_printf("Congratulations! You won.\n");
		exit (0);
	}
	all->assets->player.x = x;
	all->assets->player.y = y;
	return (0);
}
