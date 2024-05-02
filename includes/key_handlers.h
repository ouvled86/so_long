/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 00:57:45 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/02 11:31:10 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HANDLERS_H
# define KEY_HANDLERS_H

# include "rendering.h"

void		wasd_handler(int keycode, int *x, int *y, char **map);
int			movement_handler(int keycode, t_all_data *all);
void		esc_handler(int keycode, t_all_data *all);
int			mouse_cl_handler(t_all_data *all);

#endif