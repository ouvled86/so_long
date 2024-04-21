/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:51:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/21 19:55:55 by ouel-bou         ###   ########.fr       */
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
	char	*map_path;
	char	**map;

	map_path = extract_path(argv[1]);
	map = read_map(map_path);
	for (int j = 0; j < 5; j++)
		printf("%s", map[j]);
}
