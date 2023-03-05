/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:51:13 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/05 22:06:04 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	deg_to_rad(double fov)
{
	return (fov * M_PI / 180);
}


// need to replace lookfrom and lookat by direction
void	init_camera(t_camera *camera, t_vec3 lookfrom, t_vec3 lookat, t_vec3 vup, double aperture, double focus_dist)
{
	t_vec3	half_horizontal;
	t_vec3	half_vertical;
	double	h;

	vup.y = -vup.y;
	h = tan(deg_to_rad(camera->fov / 2.0));
	camera->viewport_h = 2.0 * h;
	camera->viewport_w = ASPECT_RATIO * camera->viewport_h;
	camera->focal_length = 1.0;
	camera->w = r_vec3_normalize(r_substract_vec3(lookfrom, lookat));
	camera->u = r_vec3_normalize(vec3_cross_product(&vup, &camera->w));
	camera->v = vec3_cross_product(&camera->w, &camera->u);
	camera->origin = lookfrom;
	camera->horizontal = r_vec3_scale(camera->u, camera->viewport_w * focus_dist);
	camera->vertical = r_vec3_scale(camera->v, camera->viewport_h * focus_dist);
	half_horizontal = r_vec3_scale(camera->horizontal, 0.5);
	half_vertical = r_vec3_scale(camera->vertical, 0.5);
	camera->low_left_corner = r_substract_vec3(camera->origin, half_horizontal);
	substract_vec3(&camera->low_left_corner, &half_vertical);
	camera->low_left_corner = r_substract_vec3(camera->low_left_corner, r_vec3_scale(camera->w, focus_dist));
	camera->lens_radius = aperture / 2;
}
