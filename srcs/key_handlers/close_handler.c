/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:45:36 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/27 18:42:14 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_handlers.h"
#include "../../mlx/mlx.h"

void	esc_handler(int keycode, t_all_data *all)
{
	if (keycode == 53)
	{
		mlx_destroy_image(all->data->mlx, all->txts->p);
		mlx_destroy_image(all->data->mlx, all->txts->r);
		mlx_destroy_image(all->data->mlx, all->txts->g);
		mlx_destroy_image(all->data->mlx, all->txts->e);
		mlx_destroy_image(all->data->mlx, all->txts->c);
		free (all->txts);
		all->assets->map = freemem(all->assets->map);
		free (all->assets);
		mlx_destroy_window(all->data->mlx, all->data->win);
		free (all->data);
		free(all);
		exit (0);
	}
}

int	mouse_cl_handler(t_all_data *all)
{
	mlx_destroy_image(all->data->mlx, all->txts->p);
	mlx_destroy_image(all->data->mlx, all->txts->r);
	mlx_destroy_image(all->data->mlx, all->txts->g);
	mlx_destroy_image(all->data->mlx, all->txts->e);
	mlx_destroy_image(all->data->mlx, all->txts->c);
	free (all->txts);
	all->assets->map = freemem(all->assets->map);
	free (all->assets);
	mlx_destroy_window(all->data->mlx, all->data->win);
	free (all->data);
	free(all);
	exit (0);
}
