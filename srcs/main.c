/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:51:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/02 13:51:17 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char		*map_path;
	t_all_data	*all;

	if (argc == 2)
	{
		map_path = extract_path(argv[1]);
		all = (t_all_data *)malloc(sizeof(t_all_data));
		if (map_path)
			all->assets = assets_init(read_map(map_path), map_path);
		if (!is_accessible(map_path))
			err_func("Map is invalid", all->assets, all->assets->map);
		all->data = data_init(all->assets, map_path);
		all->txts = load_textures(all->data);
		render_map(all);
		mlx_key_hook(all->data->win, movement_handler, all);
		mlx_hook(all->data->win, 17, 0, mouse_cl_handler, all);
		mlx_loop_hook(all->data->mlx, render_map, all);
		mlx_loop(all->data->mlx);
	}
	else
	{
		ft_printf("Please enter a map file.\n");
		return (1);
	}
	return (0);
}
