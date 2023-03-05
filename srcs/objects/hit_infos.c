/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:14:36 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/05 18:40:41 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

uint8_t	world_hit(t_objects *objects, t_ray *ray, double t_min, double t_max, t_hit_info *hit_info)
{
	uint8_t		i;
	t_hit_info	tmp_hit_info;
	double		closest;
	uint8_t		hit;

	i = 0;
	hit = 0;
	closest = t_max;
	while (i < objects->spheres_nb)
	{
		if (hit_sphere(&objects->spheres[i], ray, t_min, t_max, &tmp_hit_info))
		{
			if (tmp_hit_info.t < closest)
			{
				hit = i + 1;
				closest = tmp_hit_info.t;
				*hit_info = tmp_hit_info;
			}
		}
		i++;
	}
	(void)closest;
	return (hit);
}

void	set_face_normal(t_ray *ray, t_vec3 *outward_normal, t_hit_info *hit_info)
{
	hit_info->front_face = vec3_dot_product(&ray->dir, outward_normal) < 0;
	if (hit_info->front_face)
		hit_info->normal = *outward_normal;
	else
		hit_info->normal = r_reverse_vec3(*outward_normal);
}