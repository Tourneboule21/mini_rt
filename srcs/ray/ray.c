/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 18:08:12 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/03 18:42:38 by lcrimet          ###   ########lyon.fr   */
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

	res = r_vec3_scale(&ray->dir, t);
	add_vec3(&res, &ray->origin);
	return (res);
}

t_vec3	ray_color(t_ray *ray)
{
	t_vec3	color;
	t_vec3	unit_dir;
	double	grad_factor;

	unit_dir = r_vec3_normalize(&ray->dir);
	grad_factor = 0.5 * (unit_dir.y + 1.0);
	color.x = 1.0 + (1.0 - grad_factor) + grad_factor * 0.5;
	color.y = 1.0 + (1.0 - grad_factor) + grad_factor * 0.7;
	color.z = 1.0 + (1.0 - grad_factor) + grad_factor * 1.0;
	return (color);
}
