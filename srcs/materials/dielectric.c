/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dielectric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:50:55 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/05 18:30:50 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/* only refractive materials */

uint8_t	dielectric_scatter(t_ray *ray_in, t_hit_info *hit_info, t_vec3 *color_attenuation, t_ray *scattered, t_material *mat)
{
	double	refract_ratio;
	t_vec3	unit_dir;
	t_vec3	refracted;

	set_vec3(color_attenuation, 1.0, 1.0, 1.0);
	if (hit_info->front_face)
		refract_ratio = 1.0 / mat->ior;
	else
		refract_ratio = mat->ior;
	unit_dir = ray_in->dir;
	vec3_normalize(&unit_dir);
	refracted = refract(unit_dir, hit_info->normal, refract_ratio);
	set_ray(scattered, hit_info->p, refracted);
	return (1);
}