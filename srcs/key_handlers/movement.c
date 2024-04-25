/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:38:24 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 00:45:24 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"

int	movement_handler(int keycode, t_all_data *all)
{
	char	**map;

	map = all->assets->map;
	if (keycode == 13 && all->assets->map[all->assets->player.y - 1][all->assets->player.x] != '1')
	{
		all->assets->map[all->assets->player.y][all->assets->player.x] = '0';
		all->assets->map[all->assets->player.y - 1][all->assets->player.x] = 'P';
	}
	if (keycode == 1 && all->assets->map[all->assets->player.y + 1][all->assets->player.x] != '1')
	{
		all->assets->map[all->assets->player.y][all->assets->player.x] = '0';
		all->assets->map[all->assets->player.y + 1][all->assets->player.x] = 'P';
	}
	if (keycode == 2 && all->assets->map[all->assets->player.y][all->assets->player.x + 1] != '1')
	{
		all->assets->map[all->assets->player.y][all->assets->player.x] = '0';
		all->assets->map[all->assets->player.y][all->assets->player.x + 1] = 'P';
	}
	if (keycode == 0 && all->assets->map[all->assets->player.y][all->assets->player.x - 1] != '1')
	{
		all->assets->map[all->assets->player.y][all->assets->player.x] = '0';
		all->assets->map[all->assets->player.y][all->assets->player.x - 1] = 'P';
	}
	printf("Keycode number %d has been pressed\n", keycode);
	
	render_map(all->txts, all->data, all->assets);
	return (0);
}
