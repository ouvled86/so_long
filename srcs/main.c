/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:51:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/25 22:17:41 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/rendering.h"
#include "../includes/libft.h"
#include <mlx.h>

int	main(int argc, char **argv)
{
	char		*map_path;
	t_assets	*assets;
	t_textures	*txts;
	t_mlx_data	*data;

	map_path = extract_path(argv[1]);
	if (map_path)
		assets = assets_ini(read_map(map_path), map_path);
	if (!is_accessible(map_path))
		err_func("Map is invalid", assets, assets->map, map_path);
	data = ini_data(assets, map_path);
	txts = load_textures(data);
	render_map(txts, data, assets);
	mlx_loop(data->mlx);
}





	// mlx_put_image_to_window(mlx_con, mlx_win, wl_img, 63, 0);
	// for (int j = 0; j < 5; j++)
	// 	printf("%s", assets->map[j]);
	// printf("\nplayer position: (%d, %d)\nexit position: (%d, %d)\ncollectibles count: %d\n", assets->player.x, assets->player.y, assets->exit.x, assets->exit.y, assets->collectibles);
	// printf("Width is: %d, Height is: %d\n", width2, height2);