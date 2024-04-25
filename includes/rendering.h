/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:05:53 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/26 00:36:16 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "parsing.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win_ptr;
	int		width;
	int		height;
}			t_mlx_data;

typedef struct s_textures
{
	void	*grass;
	void	*rocks;
	void	*exit;
	void	*cols;
	void	*player;
}			t_textures;

typedef struct s_all_data
{
	t_textures	*txts;
	t_mlx_data	*data;
	t_assets	*assets;
}				t_all_data;

t_mlx_data	*ini_data(t_assets *assets, char *map_path);
t_textures	*load_textures(t_mlx_data *data);

void		render_map(t_textures *txts, t_mlx_data *data, t_assets *assets);

int	movement_handler(int keycode, t_all_data *all);


#endif