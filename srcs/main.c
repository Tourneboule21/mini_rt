/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:02:58 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/03 19:07:44 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	draw_pixel(t_data *data, t_vec3 *color, int i, int j)
{
	t_color	pixel_color;

	pixel_color.tcolor.r = (int)(255.999 * color->x);
	pixel_color.tcolor.g = (int)(255.999 * color->y);
	pixel_color.tcolor.b = (int)(255.999 * color->z);
	data->renderer[i * data->win_w + j] = pixel_color.ucolor;
}

int	main(void)
{
	t_data	data;
	t_vec3	color;

	if (!init_mlx(&data))
		return (1);
	for (int i = data.win_h - 1; i >= 0; i--)
	{
		for (int j = 0; j < data.win_w; j++)
		{
			color.x = (double)(i) / (double)(data.win_h - 1);
			color.y = (double)(j) / (double)(data.win_w-1);
			color.z = 0.25;
			draw_pixel(&data, &color, i, j);
		}
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_hook(data.win, ON_DESTROY, 0, ft_close, &data);
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, key_pressed, &data);
	mlx_loop(data.mlx);
	return (0);
}
