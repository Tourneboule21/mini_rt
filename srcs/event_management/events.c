/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:36:31 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/03 17:39:37 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	*quit(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->win);	
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
}

int	key_pressed(int keycode, t_data *data)
{
	if (keycode == ESC)
		quit(data);
	return (0);
}

int	ft_close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	quit(data);
	return (0);
}