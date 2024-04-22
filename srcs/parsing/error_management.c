/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 01:05:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/22 01:38:00 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	err_func(char *display_msg, t_assets *a, char **map, char *mp)
{
	if (display_msg)
		printf("Error\n%s\n", display_msg);
	if (map)
		map = freemem(map);
	if (a)
		free (a);
	exit (1);
}
