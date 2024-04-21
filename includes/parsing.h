/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:43:12 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/21 21:04:37 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct s_assets
{
	char	**map;
	int		exit;
	int		player;
	int		collectibles;
}			t_assets;

int		file_check(char *map_path);
char	**read_map(char *map_path);
#endif