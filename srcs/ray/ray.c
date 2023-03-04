/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:08:12 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/04 13:42:39 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init_ray(t_ray *ray, t_vec3 *origin, t_vec3 *dir)
{
	ray->origin = *origin;
	ray->dir = *dir;
}

t_vec3	pos_on_ray(t_ray *ray, double t)
{
	t_vec3	res;

	res = r_vec3_scale(ray->dir, t);
	add_vec3(&res, &ray->origin);
	return (res);
}

t_vec3	ray_color(t_ray *ray, t_objects *objects)
{
	t_hit_info	hit_info;
	t_vec3		color;
	t_vec3		unit_dir;
	double		t;
	if (world_hit(objects, ray, 0.0, DBL_MAX, &hit_info))
	{
		color.x = 0.5 * (hit_info.normal.x + 1.0);
		color.y = 0.5 * (hit_info.normal.y + 1.0);
		color.z = 0.5 * (hit_info.normal.z + 1.0);
		return (color);
	}

	unit_dir = r_vec3_normalize(ray->dir);
	t = 0.5 * (unit_dir.y + 1.0);
	color.x = 1.0 * (1.0 - t) + t * 0.4;
	color.y = 1.0 * (1.0 - t) + t * 0.6;
	color.z = 1.0 * (1.0 - t) + t * 1.0;
	return (color);
}

t_vec3	get_ray_dir(t_camera *camera, float u, float v)
{
	t_vec3	res;
	t_vec3	scale_horizontal;
	t_vec3	scale_vertical;

	scale_horizontal = r_vec3_scale(camera->horizontal, (double)u);
	scale_vertical = r_vec3_scale(camera->vertical, (double)v);
	res = r_add_vec3(camera->low_left_corner, scale_horizontal);
	add_vec3(&res, &scale_vertical);
	substract_vec3(&res, &camera->origin);
	return (res);
}
