/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:18:43 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/04 13:29:57 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_sphere(t_sphere *sphere, t_vec3 center, double radius)
{
	sphere->center = center;
	sphere->radius = radius;
}

t_sphere	r_set_sphere(t_vec3 center, double radius)
{
	t_sphere	res;

	res.center = center;
	res.radius = radius;
	return (res);
}

uint8_t	hit_sphere(t_sphere *sphere, t_ray *ray, double t_min, double t_max, t_hit_info *hit_info)
{
	t_vec3	oc;
	t_vec3	outward_normal;
	double	a;
	double	half_b;
	double	c;
	double	dis;
	double	sqrt_dis;
	double	root;

	oc = r_substract_vec3(ray->origin, sphere->center);
	a = vec3_length_squared(&ray->dir);
	half_b = vec3_dot_product(&oc, &ray->dir);
	c = vec3_length_squared(&oc) - sphere->radius * sphere->radius;
	dis = half_b * half_b - a * c;
	if (dis < 0)
		return (0);
	sqrt_dis = sqrt(dis);
	root = (-half_b - sqrt_dis) / a;
	if (root < t_min || t_max < root)
	{
		root = (-half_b + sqrt_dis) / a;
		if (root < t_min || t_max < root)
			return (0);
	}
	hit_info->t = root;
	hit_info->p = pos_on_ray(ray, hit_info->t);
	outward_normal = r_vec3_scale((r_substract_vec3(hit_info->p, sphere->center)), (1.0 / sphere->radius));
	set_face_normal(ray, &outward_normal, hit_info);
	return (1);
}
