/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:51:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/27 00:54:51 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char		*map_path;
	t_all_data	*all;

	map_path = extract_path(argv[1]);
	all = (t_all_data *)malloc(sizeof(t_all_data));
	if (map_path)
		all->assets = assets_ini(read_map(map_path), map_path);
	if (!is_accessible(map_path))
		err_func("Map is invalid", all->assets, all->assets->map);
	all->data = ini_data(all->assets, map_path);
	all->txts = load_textures(all->data);
	render_map(all);
	mlx_key_hook(all->data->win_ptr, movement_handler, all);
	mlx_hook(all->data->win_ptr, 17, 0, mouse_cl_handler, all);
	mlx_loop_hook(all->data->mlx, render_map, all);
	mlx_loop(all->data->mlx);
}
