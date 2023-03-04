/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:51:13 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/04 11:57:29 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	init_camera(t_camera *camera)
{
	t_vec3	half_horizontal;
	t_vec3	half_vertical;
	t_vec3	focal;

	camera->viewport_h = 2.0;
	camera->viewport_w = ASPECT_RATIO * camera->viewport_h;
	camera->focal_length = 1.0;
	set_vec3(&focal, 0.0, 0.0, camera->focal_length);
	set_vec3(&camera->origin, 0.0, 0.0, 0.0);
	set_vec3(&camera->horizontal, camera->viewport_w, 0.0, 0.0);
	set_vec3(&camera->vertical, 0.0, -camera->viewport_h, 0.0);
	half_horizontal = r_vec3_scale(camera->horizontal, 0.5);
	half_vertical = r_vec3_scale(camera->vertical, 0.5);
	camera->low_left_corner = r_substract_vec3(camera->origin, half_horizontal);
	substract_vec3(&camera->low_left_corner, &half_vertical);
	substract_vec3(&camera->low_left_corner, &focal);
}
