/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:02:58 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/03 17:49:39 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	main(void)
{
	t_data	data;
	t_color	color;

	if (!init_mlx(&data))
		return (1);
	for (int i = WIN_HEIGHT - 1; i >= 0; i--)
	{
		for (int j = 0; j < WIN_HEIGHT; j++)
		{
			double r = (double)(i) / (double)(WIN_HEIGHT - 1);
			double g = (double)(j) / (double)(WIN_HEIGHT-1);
            double b = 0.25;
			
			color.tcolor.r = (int)(255.999 * r);
			color.tcolor.g = (int)(255.999 * g);
			color.tcolor.b = (int)(255.999 * b);
			data.renderer[i * WIN_WIDTH + j] = color.ucolor;
		}
	}
	mlx_put_image_to_window(data.mlx, data.win, data.img.img, 0, 0);
	mlx_hook(data.win, ON_DESTROY, 0, ft_close, &data);
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, key_pressed, &data);
	mlx_loop(data.mlx);
	return (0);
}
