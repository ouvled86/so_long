/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:48:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/25 20:55:44 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"
#include <mlx.h>

void	render_grass(t_textures	*txts, t_mlx_data *data, t_assets *assets)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < data->width - 45)
	{
		x = 0;
		while (x < data->width - 45)
		{
			mlx_put_image_to_window(data->mlx, data->win_ptr, txts->grass, x, y);
			x += 45;
		}
		y += 45;
	}
}

void	render_rocks(t_textures *txts, t_mlx_data *data, t_assets *assets)
{
	int x;
	int y;

	y = 0;
	while (y <= data->height - 45)
	{
		x = 0;
		while (x <= data->width - 45)
		{
			if (assets->map[y/45][x/45] == '1')
				mlx_put_image_to_window(data->mlx, data->win_ptr, txts->rocks, x, y);
			x += 45;
		}
		y += 45;
	}
}