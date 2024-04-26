/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:38:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 19:53:45 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"
#include "../../mlx/mlx.h"

void	wasd_handler(int keycode, int *x, int *y, char **map)
{
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

void	moves_print(int keycode, int *x, int *y, int *moves, char **map)
{
	int	f;
	
	f = 0;
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 13)
	{
		if (map[*y][*x - 1] != '1' || map[*y][*x + 1] != '1'
			|| map[*y - 1][*x] != '1' || map[*y - 1][*x] != '1')
			f = 1;
	}
	if (f == 1)
	{
		(*moves)++;
		printf("You have moved %d times\n", *moves);
	}
}

// int	win_game(int *c, t_pos exit, int *x, int *y)
// {
// 	int	f;

// 	f = 0;
// 	if (*c == 0 )
// }

int	movement_handler(int keycode, t_all_data *all)
{
	char	**map;
	static int		moves;
	int		x;
	int		y;

	map = all->assets->map;
	x = all->assets->player.x;
	y = all->assets->player.y;
	wasd_handler(keycode, &x, &y, map);
	moves_print(keycode, &x, &y, &moves, map);
	all->assets->player.x = x;
	all->assets->player.y = y;
	// printf("Keycode number %d has been pressed\n", keycode);
	// all->assets->map = map;
	// render_map(all->txts, all->data, all->assets);
	// for (int j = 0; j < 5; j++)
	// 	printf("%s", all->assets->map[j]);
	// printf("\nplayer position: (%d, %d)\nexit position: (%d, %d)\ncollectibles count: %d\n", assets->player.x, assets->player.y, assets->exit.x, assets->exit.y, assets->collectibles);
	return (0);
}
