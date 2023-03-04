/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:08:12 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/04 22:12:48 by lcrimet          ###   ########lyon.fr   */
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

t_ray	*set_ray(t_ray *ray, t_vec3 origin, t_vec3 dir)
{
	ray->origin = origin;
	ray->dir = dir;
	return (ray);
}

t_vec3	ray_color(t_ray *ray, t_objects *objects, int depth)
{
	t_hit_info	hit_info;
	t_vec3		color;
	t_vec3		unit_dir;
	t_vec3		target;
	double		t;

	if (depth <= 0)
		return (r_set_vec3(0.0, 0.0, 0.0));
	if (world_hit(objects, ray, 0.001, DBL_MAX, &hit_info))
	{
		target = r_add_vec3(r_add_vec3(hit_info.p, hit_info.normal), random_unit_vec_sphere());
		return (r_vec3_scale(ray_color(set_ray(ray, hit_info.p, r_substract_vec3(target, hit_info.p)), objects, depth - 1), 0.5));
	}
	unit_dir = r_vec3_normalize(ray->dir);
	t = 0.5 * (unit_dir.y + 1.0);
	color.x = 1.0 * (1.0 - t) + t * 0.5;
	color.y = 1.0 * (1.0 - t) + t * 0.7;
	color.z = 1.0 * (1.0 - t) + t * 1.0;
	return (color);
}

t_vec3	get_ray_dir(t_camera *camera, double u, double v)
{
	t_vec3	res;
	t_vec3	scale_horizontal;
	t_vec3	scale_vertical;

	scale_horizontal = r_vec3_scale(camera->horizontal, u);
	scale_vertical = r_vec3_scale(camera->vertical, v);
	res = r_add_vec3(camera->low_left_corner, scale_horizontal);
	add_vec3(&res, &scale_vertical);
	substract_vec3(&res, &camera->origin);
	return (res);
}
