/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:51:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 18:42:52 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/rendering.h"
#include "../includes/libft.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	char		*map_path;
	t_all_data	*all;

	map_path = extract_path(argv[1]);
	all = (t_all_data *)malloc(sizeof(t_all_data));
	if (map_path)
		all->assets = assets_ini(read_map(map_path), map_path);
	if (!is_accessible(map_path))
		err_func("Map is invalid", all->assets, all->assets->map, map_path);
	all->data = ini_data(all->assets, map_path);
	all->txts = load_textures(all->data);
	render_map(all);
	mlx_key_hook(all->data->win_ptr, movement_handler, all);
	mlx_loop_hook(all->data->mlx, render_map, all);
	mlx_loop(all->data->mlx);
}





	// mlx_put_image_to_window(mlx_con, mlx_win, wl_img, 63, 0);
	// for (int j = 0; j < 5; j++)
	// 	printf("%s", assets->map[j]);
	// printf("\nplayer position: (%d, %d)\nexit position: (%d, %d)\ncollectibles count: %d\n", assets->player.x, assets->player.y, assets->exit.x, assets->exit.y, assets->collectibles);
	// printf("Width is: %d, Height is: %d\n", width2, height2);