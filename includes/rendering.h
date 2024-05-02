/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 19:05:53 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/02 11:48:57 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "parsing.h"

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}			t_mlx_data;

typedef struct s_textures
{
	void	*g;
	void	*r;
	void	*e;
	void	*c;
	void	*p;
}			t_textures;

typedef struct s_all_data
{
	t_textures	*txts;
	t_mlx_data	*data;
	t_assets	*assets;
}				t_all_data;

t_mlx_data	*data_init(t_assets *assets, char *map_path);
t_textures	*load_textures(t_mlx_data *data);

int			render_map(t_all_data *all);

#endif