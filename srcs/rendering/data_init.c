/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:51:20 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/02 11:48:57 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"
#include "../../mlx/mlx.h"

t_mlx_data	*data_init(t_assets *assets, char *map_path)
{
	t_mlx_data	*data;

	data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (!data)
		err_func("Error\nMemory issue", assets, assets->map);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free (data);
		err_func("Error\nMLX Connection failed", assets, assets->map);
	}
	data->width = (ft_strlen(assets->map[0]) - 1) * 45;
	data->height = lines_count(map_path) * 45;
	data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
	if (!data->win)
	{
		assets->map = freemem(assets->map);
		free (data);
		err_func("Error\nWindow failed to load", assets, assets->map);
	}
	return (data);
}

t_textures	*load_textures(t_mlx_data *data)
{
	t_textures	*txts;
	int			w;
	int			h;

	txts = (t_textures *)malloc(sizeof(t_textures));
	if (!txts)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (1);
	}
	txts->g = mlx_xpm_file_to_image(data->mlx, "textures/gs.xpm", &w, &h);
	txts->r = mlx_xpm_file_to_image(data->mlx, "textures/rs.xpm", &w, &h);
	txts->e = mlx_xpm_file_to_image(data->mlx, "textures/ex.xpm", &w, &h);
	txts->c = mlx_xpm_file_to_image(data->mlx, "textures/cl.xpm", &w, &h);
	txts->p = mlx_xpm_file_to_image(data->mlx, "textures/pl.xpm", &w, &h);
	if (txts->g == NULL || txts->r == NULL || txts->e == NULL 
		|| txts->c == NULL || txts->p == NULL)
	{
		mlx_destroy_window(data->mlx, data->win);
		err_func("Error\nInvalid images", NULL, NULL);
	}
	return (txts);
}
