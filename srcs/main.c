/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:51:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/25 00:55:22 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/libft.h"
#include <mlx.h>

static char	*extract_path(char *path)
{
	char	*map_path;

	map_path = NULL;
	if (path)
	{
		map_path = (char *)malloc(sizeof(path));
		map_path = path;
	}
	return (map_path);
}

int	main(int argc, char **argv)
{
	void		*mlx_con;
	void		*mlx_win;
	void		*bg_img;
	void		*wl_img;
	int			width;
	int			width2;
	int			height;
	int			height2;
	int			x;
	int			y;
	char		*map_path;
	t_assets	*assets;

	mlx_con = mlx_init();
	map_path = extract_path(argv[1]);
	if (map_path)
		assets = assets_ini(read_map(map_path), map_path);
	width = ft_strlen(assets->map[0]) * 64;
	height = lines_count(map_path) * 64;
	mlx_win = mlx_new_window(mlx_con, width, height, "so_long");
	if (!is_accessible(map_path))
		err_func("Map is invalid", assets, assets->map, map_path);
	// for (int j = 0; j < 5; j++)
	// 	printf("%s", assets->map[j]);
	// printf("\nplayer position: (%d, %d)\nexit position: (%d, %d)\ncollectibles count: %d\n", assets->player.x, assets->player.y, assets->exit.x, assets->exit.y, assets->collectibles);
	bg_img = mlx_xpm_file_to_image(mlx_con, "textures/floor.xpm", &width2, &height2);
	wl_img = mlx_xpm_file_to_image(mlx_con, "textures/wall.xpm", &width2, &height2);
	printf("Width is: %d, Height is: %d\n", width2, height2);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			mlx_put_image_to_window(mlx_con, mlx_win, bg_img, x, y);
			x += 64;
		}
		y += 64;
	}
	mlx_put_image_to_window(mlx_con, mlx_win, wl_img, 63, 0);
	mlx_loop(mlx_con);
}
