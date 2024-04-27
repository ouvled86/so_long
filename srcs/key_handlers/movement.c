/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:38:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/27 19:44:35 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_handlers.h"
#include "../../mlx/mlx.h"

int	*update_collectibles(int *x, int *y, char **map)
{
	static int	c;

	if (c == 0)
		c = set_c_count(map);
	if (map[*y][*x - 1] == 'C')
		c--;
	if (map[*y][*x + 1] == 'C')
		c--;
	if (map[*y - 1][*x] == 'C')
		c--;
	if (map[*y + 1][*x] == 'C')
		c--;
	return (&c);
}

void	moves_print(int keycode, int *x, int *y, char **map)
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

int	win_game(int *x, int *y, int *c, char **map)
{
	if (map[*y - 1][*x] == 'E' && *c == 0)
		return (1);
	else if (map[*y + 1][*x] == 'E' && *c == 0)
		return (1);
	else if (map[*y][*x + 1] == 'E' && *c == 0)
		return (1);
	else if (map[*y][*x - 1] == 'E' && *c == 0)
		return (1);
	return (0);
}

int	movement_handler(int keycode, t_all_data *all)
{
	char		**map;
	int			x;
	int			y;

	map = all->assets->map;
	x = all->assets->player.x;
	y = all->assets->player.y;
	moves_print(keycode, &x, &y, map);
	if (keycode == 53)
		esc_handler(keycode, all);
	if (win_game(&x, &y, update_collectibles(&x, &y, map), map))
	{
		ft_printf("Congratulations! You won.\n");
		exit (0);
	}
	update_collectibles(&x, &y, map);
	if (all->assets->collectibles == 0)
		wasd_unlocked(keycode, &x, &y, map);
	else
		wasd_handler(keycode, &x, &y, map);
	all->assets->player.x = x;
	all->assets->player.y = y;
	return (0);
}
