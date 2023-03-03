/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:02:58 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/03 16:49:57 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	*quit(t_data *data)
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

int	close(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	quit(data);
	return (0);
}

int	main(void)
{
	t_data	data;
	t_vec3	test;
	t_vec3	cp;

	if (!init_mlx(&data))
		return (1);
	set_vec3(&test, 1, 4.5, -2);
	print_vec3(&test);
	printf("\n");
	copy_vec3(&cp, &test);
	reverse_vec3(&cp);
	print_vec3(&cp);
	printf("\n");
	mlx_hook(data.win, ON_DESTROY, 0, close, &data);
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, key_pressed, &data);
	mlx_loop(data.mlx);
	return (0);
}
