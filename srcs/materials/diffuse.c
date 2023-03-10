/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:52:54 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/10 13:53:30 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/* Lambertian diffuse material */

uint8_t	diffuse_scatter(t_ray *ray_in, t_hit_info *hit_info, t_vec3 *color_attenuation, t_ray *scattered, t_material *mat)
{
	t_vec3	scatter_dir;
	
	scatter_dir = r_add_vec3(hit_info->normal, random_unit_vec_sphere());
	if (near_zero(&scatter_dir))
		scatter_dir = hit_info->normal;
	init_ray(scattered, &hit_info->p, &scatter_dir, ray_in->time);
	*color_attenuation = mat->albedo;
	return (1);
}