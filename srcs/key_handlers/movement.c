/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:38:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 02:15:27 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"
#include <mlx.h>

int	movement_handler(int keycode, t_all_data *all)
{
	char	**map;

	map = all->assets->map;
	// mlx_clear_window(all->data->mlx, all->data->win_ptr);
	// all->data->win_ptr = mlx_new_window(all->data->mlx, all->data->width, all->data->height, "so_long");
	if (keycode == 13 && all->assets->map[all->assets->player.y - 1][all->assets->player.x] == '0')
	{
		map[all->assets->player.y][all->assets->player.x] = '0';
		map[all->assets->player.y - 1][all->assets->player.x] = 'P';
		all->assets->player.y--;
	}
	else if (keycode == 1 && all->assets->map[all->assets->player.y + 1][all->assets->player.x] != '1')
	{
		map[all->assets->player.y][all->assets->player.x] = '0';
		map[all->assets->player.y + 1][all->assets->player.x] = 'P';
		all->assets->player.y++;
	}
	else if (keycode == 2 && all->assets->map[all->assets->player.y][all->assets->player.x + 1] != '1')
	{
		map[all->assets->player.y][all->assets->player.x] = '0';
		map[all->assets->player.y][all->assets->player.x + 1] = 'P';
		all->assets->player.x++;
	}
	else if (keycode == 0 && all->assets->map[all->assets->player.y][all->assets->player.x - 1] != '1')
	{
		map[all->assets->player.y][all->assets->player.x] = '0';
		map[all->assets->player.y][all->assets->player.x - 1] = 'P';
		all->assets->player.x--;
	}
	printf("Keycode number %d has been pressed\n", keycode);
	all->assets->map = map;
	// render_map(all->txts, all->data, all->assets);
	// for (int j = 0; j <= 5; j++)
	// 	printf("%s", all->assets->map[j]);
	// printf("\nplayer position: (%d, %d)\nexit position: (%d, %d)\ncollectibles count: %d\n", assets->player.x, assets->player.y, assets->exit.x, assets->exit.y, assets->collectibles);
	return (0);
}
