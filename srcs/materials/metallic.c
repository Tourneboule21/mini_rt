/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:39:46 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/10 13:52:44 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

uint8_t	metallic_scatter(t_ray *ray_in, t_hit_info *hit_info, t_vec3 *color_attenuation, t_ray *scattered, t_material *mat)
{
	t_vec3	reflected;
	t_vec3	fuzz;

	reflected = reflect(r_vec3_normalize(ray_in->dir), hit_info->normal);
	fuzz = r_add_vec3(reflected, r_vec3_scale(random_in_unit_sphere(), mat->fuzz));
	init_ray(scattered, &hit_info->p, &fuzz, ray_in->time);
	*color_attenuation = mat->albedo;
	return ((vec3_dot_product(&scattered->dir, &hit_info->normal) > 0));
}