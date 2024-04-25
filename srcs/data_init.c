/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:51:20 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/25 22:14:16 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/rendering.h"
#include "../includes/parsing.h"
#include "../includes/libft.h"
#include <mlx.h>

t_mlx_data	*ini_data(t_assets *assets, char *map_path)
{
	t_mlx_data	*data;
	
	data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	data->mlx = mlx_init();
	data->width = (ft_strlen(assets->map[0]) - 1) * 45;
	data->height = lines_count(map_path) * 45;
	data->win_ptr = mlx_new_window(data->mlx, data->width, data->height, "so_long");
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
		mlx_destroy_window(data->mlx, data->win_ptr);
		exit (1);
	}
	txts->grass = mlx_xpm_file_to_image(data->mlx, "textures/gs.xpm", &w, &h);
	txts->rocks = mlx_xpm_file_to_image(data->mlx, "textures/rs.xpm", &w, &h);
	txts->exit = mlx_xpm_file_to_image(data->mlx, "textures/ex.xpm", &w, &h);
	txts->cols = mlx_xpm_file_to_image(data->mlx, "textures/cl.xpm", &w, &h);
	txts->player = mlx_xpm_file_to_image(data->mlx, "textures/pl.xpm", &w, &h);
	return (txts);
}