/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 00:19:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/02/21 23:10:16 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	create_trgb(unsigned char t, unsigned char r, unsigned char g, unsigned char b)
{
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int		add_shade(double d, int color)
{
	return (create_trgb(255 * d, ((unsigned char *)&color)[2], ((unsigned char *)&color)[1], ((unsigned char *)&color)[0]));
}

int		get_opposite(int color)
{
	return (create_trgb(255 - ((unsigned char *)&color)[3], 255 - ((unsigned char *)&color)[2], 255 - ((unsigned char *)&color)[1], 255 - ((unsigned char *)&color)[0]));
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		trgb = create_trgb(0,0,0,0);
	
	// trgb = add_shade(1, trgb);
	// trgb = get_opposite(trgb);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < 1080; i++) {
		for (int j = 0; j < 1920; j++) {
			my_mlx_pixel_put(&img, j, i, trgb++);
		}
	}
	// my_mlx_pixel_put(&img, 1800, 1000, 0x00FF0000);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
