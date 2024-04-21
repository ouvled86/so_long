/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:51:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/21 23:28:44 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"
#include "../includes/libft.h"

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
	char		**map;
	char		*map_path;
	t_assets	*assets;

	map_path = extract_path(argv[1]);
	if (map_path)
		assets = assets_ini(read_map(map_path), map_path);
	for (int j = 0; j < 5; j++)
		printf("%s", assets->map[j]);
	printf("\nplayer position: (%d, %d)\nexit position: (%d, %d)\ncollectibles count: %d\n", assets->player->x, assets->player->y, assets->exit->x, assets->exit->y, assets->collectibles);
}
