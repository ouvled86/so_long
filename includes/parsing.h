/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:43:12 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/21 19:48:05 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

char	**read_map(char *map_path);
#endif