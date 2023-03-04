/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:36:31 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/04 23:28:11 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	*quit(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);	
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == ESC)
		quit(data);
	/* use it only with very very VERY low resolution like 200 pixel width
	   cause the actual perf are awful */
	// if (keycode == D)
		// data->objects.spheres[0].center.x += 0.1;
	// else if (keycode == A)
		// data->objects.spheres[0].center.x -= 0.1;
	// else if (keycode == W)
		// data->objects.spheres[0].center.z -= 0.1;
	// else if (keycode == S)
		// data->objects.spheres[0].center.z += 0.1;
	// else if (keycode == Q)
		// data->objects.spheres[0].center.y -= 0.1;
	// else if (keycode == E)
		// data->objects.spheres[0].center.y += 0.1;
	return (0);
}

int	ft_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	quit(data);
	return (0);
}