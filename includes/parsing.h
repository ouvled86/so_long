/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:43:12 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/02 11:48:31 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <fcntl.h>
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
}			t_assets;

char		**read_map(char *map_path);
int			lines_count(char *map_path);
bool		is_accessible(char *map_path);

bool		is_valid(char **map, char *map_path);

t_assets	*assets_init(char **map, char *map_path);
int			set_c_count(char **map);

char		*extract_path(char *path);
void		err_func(char *display_msg, t_assets *a, char **map);

#endif