/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:26:02 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/03 16:39:22 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "mini_rt");
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return (0);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	data->renderer = (t_color *)data->img.addr;
	if (!data->win || !data->renderer)
		return (0);
	return (1);
}
