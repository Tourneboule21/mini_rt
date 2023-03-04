/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:02:58 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/04 17:59:30 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

void	draw_pixel(t_data *data, t_vec3 *color, int i, int j)
{
	t_color	pixel_color;
	double	scale;
	double	r;
	double	g;
	double	b;

	scale = 1.0 / data->sample_per_pixel;
	r = color->x;
	g = color->y;
	b = color->z;
	r = sqrt(scale * r);
	g = sqrt(scale * g);
	b = sqrt(scale * b);
	pixel_color.tcolor.r = (int)(256 * clamp(r, 0.0, 0.999));
	pixel_color.tcolor.g = (int)(256 * clamp(g, 0.0, 0.999));
	pixel_color.tcolor.b = (int)(256 * clamp(b, 0.0, 0.999));
	data->renderer[i * data->win_w + j] = pixel_color.ucolor;
}

int	render_image(t_data *data)
{
	t_vec3	color;
	t_ray	ray;
	t_vec3	ray_dir;
	double	win_size;
	static int t = 0;

	win_size = (double)(data->win_h * data->win_w);
	if (!t)
	{
		for (int i = 0; i < data->win_h; i++)
		{
			for (int j = 0; j < data->win_w; j++)
			{
				set_vec3(&color, 0.0, 0.0, 0.0);
				for (int k = 0; k < data->sample_per_pixel; k++)
				{
					double u = (j + random_double()) / (data->win_w - 1);
					double v = (i + random_double()) / (data->win_h - 1);
					ray_dir = get_ray_dir(&data->camera, u, v);
					init_ray(&ray, &data->camera.origin, &ray_dir);
					color = r_add_vec3(color, ray_color(&ray, &data->objects, data->max_depth));
				}
				draw_pixel(data, &color, i, j);
				printf("%f\n", ((i + 1) * data->win_w + (j + 1)) / win_size * 100.0);
			}
		}
		mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	}
	t = 1;
	return (0);
}

int	main(void)
{
	t_data	data;

	if (!init_mlx(&data))
		return (1);
	init_camera(&data.camera);
	data.objects.spheres = malloc(sizeof(t_sphere) * 2);
	data.objects.spheres_nb = 2;
	data.sample_per_pixel = 100;
	data.max_depth = 10;
	set_sphere(&data.objects.spheres[0], r_set_vec3(0.0, 0.0, -1.0), 0.5);
	set_sphere(&data.objects.spheres[1], r_set_vec3(0.0, -100.5, -1.0), 100);
	mlx_loop_hook(data.mlx, render_image, &data);
	mlx_hook(data.win, ON_DESTROY, 0, ft_close, &data);
	mlx_hook(data.win, ON_KEYDOWN, 1L << 0, key_pressed, &data);
	mlx_loop(data.mlx);
	return (0);
}
