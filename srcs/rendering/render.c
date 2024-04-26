/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:48:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 18:44:07 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"
#include "../../mlx/mlx.h"

static void	render_grass(t_textures	*txts, t_mlx_data *data, t_assets *assets)
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

static void	render_rocks(t_textures *txts, t_mlx_data *data, t_assets *assets)
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

static void	render_pl_ex(t_textures *txts, t_mlx_data *data, t_assets *assets)
{
	int x;
	int y;

	y = 0;
	while (y <= data->height - 45)
	{
		x = 0;
		while (x <= data->width - 45)
		{
			if (assets->map[y/45][x/45] == 'P')
				mlx_put_image_to_window(data->mlx, data->win_ptr, txts->player, x, y);
			if (assets->map[y/45][x/45] == 'E')
				mlx_put_image_to_window(data->mlx, data->win_ptr, txts->exit, x, y);
			x += 45;
		}
		y += 45;
	}
}

static void	render_cols(t_textures *txts, t_mlx_data *data, t_assets *assets)
{
	int x;
	int y;

	y = 0;
	while (y <= data->height - 45)
	{
		x = 0;
		while (x <= data->width - 45)
		{
			if (assets->map[y/45][x/45] == 'C')
				mlx_put_image_to_window(data->mlx, data->win_ptr, txts->cols, x, y);
			x += 45;
		}
		y += 45;
	}
}

int	render_map(t_all_data *all)
{
	render_grass(all->txts, all->data, all->assets);
	render_rocks(all->txts, all->data, all->assets);
	render_pl_ex(all->txts, all->data, all->assets);
	render_cols(all->txts, all->data, all->assets);
	return (0);
}