/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:50:55 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/10 13:52:56 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/* only refractive materials */

// Schlick's approximation for reflectance
static double	reflectance(double cos, double ref_idx)
{
	double	r;

	r = (1 - ref_idx) / (1 + ref_idx);
	r = r * r;
	return (r + (1 - r) * pow((1 - cos), 5));
}

uint8_t	dielectric_scatter(t_ray *ray_in, t_hit_info *hit_info, t_vec3 *color_attenuation, t_ray *scattered, t_material *mat)
{
	double	refract_ratio;
	t_vec3	unit_dir;
	t_vec3	rev_unit_dir;
	t_vec3	direction;
	double	cos_theta;
	double	sin_theta;
	uint8_t	cannot_refract;

	set_vec3(color_attenuation, 1.0, 1.0, 1.0);
	if (hit_info->front_face)
		refract_ratio = 1.0 / mat->ior;
	else
		refract_ratio = mat->ior;
	unit_dir = ray_in->dir;
	vec3_normalize(&unit_dir);
	rev_unit_dir = r_reverse_vec3(unit_dir);
	cos_theta = fmin(vec3_dot_product(&rev_unit_dir, &hit_info->normal), 1.0);
	sin_theta = sqrt(1.0 - cos_theta * cos_theta);
	cannot_refract = refract_ratio * sin_theta > 1.0;
	if (cannot_refract || reflectance(cos_theta, refract_ratio) > random_double())
		direction = reflect(unit_dir, hit_info->normal);
	else
		direction = refract(unit_dir, hit_info->normal, refract_ratio);;
	set_ray(scattered, hit_info->p, direction, ray_in->time);
	return (1);
}