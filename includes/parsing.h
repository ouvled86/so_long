/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:43:12 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/21 23:08:46 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_assets
{
	char	**map;
	int		collectibles;
	t_pos	*player;
	t_pos	*exit;
}			t_assets;

char		**read_map(char *map_path);

bool		is_valid(char **map, char *map_path);

t_assets	*assets_ini(char **map);

#endif