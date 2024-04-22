/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:43:12 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/22 22:42:27 by ouel-bou         ###   ########.fr       */
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
	t_pos	player;
	t_pos	size;
	t_pos	exit;
}			t_assets;

int			lines_count(char *map_path);
char		**read_map(char *map_path);
bool		is_accessible(char *map_path);


bool		is_valid(char **map, char *map_path);

t_assets	*assets_ini(char **map, char *map_path);
int			set_c_count(char **map);

void		err_func(char *display_msg, t_assets *a, char **map, char *mp);

#endif