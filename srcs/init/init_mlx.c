/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:26:02 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/03 21:09:41 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win_w = WIN_WIDTH;
	data->win_h = (int)(data->win_w / ASPECT_RATIO);
	data->win = mlx_new_window(data->mlx, data->win_w, data->win_h, "mini_rt");
	data->img.img = mlx_new_image(data->mlx, data->win_w, data->win_h);
	if (!data->img.img)
		return (quit(data), 0);
	data->img.addr = mlx_get_data_addr(data->img.img,
			&data->img.bits_per_pixel, &data->img.line_length,
			&data->img.endian);
	data->renderer = (uint32_t *)data->img.addr;
	if (!data->win || !data->renderer)
		return (quit(data), 0);
	return (1);
}
