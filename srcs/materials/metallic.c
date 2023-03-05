/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metallic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:39:46 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/05 16:23:02 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

uint8_t	metallic_scatter(t_ray *ray_in, t_hit_info *hit_info, t_vec3 *color_attenuation, t_ray *scattered, t_material *mat)
{
	t_vec3	reflected;

	reflected = reflect(r_vec3_normalize(ray_in->dir), hit_info->normal);
	init_ray(scattered, &hit_info->p, &reflected);
	*color_attenuation = mat->albedo;
	return ((vec3_dot_product(&scattered->dir, &hit_info->normal) > 0));
}