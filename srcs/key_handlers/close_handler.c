/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:45:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 23:49:33 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rendering.h"
#include "../../includes/libft.h"
#include "../../mlx/mlx.h"

void	esc_handler(int keycode, t_all_data *all)
{
	if (keycode == 53)
	{
		mlx_destroy_image(all->data->mlx, all->txts->player);
		mlx_destroy_image(all->data->mlx, all->txts->rocks);
		mlx_destroy_image(all->data->mlx, all->txts->grass);
		mlx_destroy_image(all->data->mlx, all->txts->exit);
		mlx_destroy_image(all->data->mlx, all->txts->cols);
		free (all->txts);
		all->assets->map = freemem(all->assets->map);
		free (all->assets);
		mlx_destroy_window(all->data->mlx, all->data->win_ptr);
		// free (all->data->mlx);
		free (all->data);
		// free(all);
		exit (0);
	}
	// return (0);
}
