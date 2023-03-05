/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 22:15:51 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/05 23:39:06 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	random_world(t_objects *objects)
{
	int	i = 0;
	t_vec3	ground_mat = r_set_vec3(0.5, 0.5, 0.5);
	objects->spheres_nb = 489;
	objects->spheres = malloc(sizeof(t_sphere) * objects->spheres_nb);
	objects->spheres[i] = r_set_sphere(r_set_vec3(0.0, -1000.0, 0.0), 1000.0);
	objects->spheres[i].mat.albedo = ground_mat;
	objects->spheres[i].mat.type = DIFFUSE;
	for (int a = -11; a < 11; a++)
	{
		for (int b = -11; b < 11; b++)
		{
			i++;
			double	choose_mat = random_double();
			t_vec3	center = r_set_vec3(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());
			t_vec3	point = r_substract_vec3(center, r_set_vec3(4.0, 0.2, 0.0));
			if (vec3_length(&point), 0.9)
			{
				if (choose_mat < 0.8)
				{
					objects->spheres[i].mat.albedo = r_mult_vec3(random_vec3(), random_vec3());
					objects->spheres[i].mat.type = DIFFUSE;
					objects->spheres[i].center = center;
					objects->spheres[i].radius = 0.2;
				}
				else if (choose_mat < 0.95)
				{
					objects->spheres[i].mat.albedo = random_vec3_limit(0.5, 1.0);
					objects->spheres[i].mat.fuzz = random_double_limit(0.0, 0.5);
					objects->spheres[i].mat.type = METALLIC;
					objects->spheres[i].center = center;
					objects->spheres[i].radius = 0.2;
				}
				else
				{
					objects->spheres[i].mat.ior = 1.5;
					objects->spheres[i].mat.type = DIELECTRIC;
					objects->spheres[i].center = center;
					objects->spheres[i].radius = 0.2;
				}
			}
		}
	}
	i++;
	objects->spheres[i] = r_set_sphere(r_set_vec3(0.0, 1.0, 0.0), 1.0);
	objects->spheres[i].mat.ior = 1.5;
	objects->spheres[i].mat.type = DIELECTRIC;
	i++;
	objects->spheres[i] = r_set_sphere(r_set_vec3(-4.0, 1.0, 0.0), 1.0);
	objects->spheres[i].mat.albedo = r_set_vec3(0.4, 0.2, 0.8);
	objects->spheres[i].mat.type = DIFFUSE;
	i++;
	objects->spheres[i] = r_set_sphere(r_set_vec3(4.0, 1.0, 0.0), 1.0);
	objects->spheres[i].mat.albedo = r_set_vec3(0.7, 0.6, 0.5);
	objects->spheres[i].mat.type = METALLIC;
	objects->spheres[i].mat.fuzz = 0.0;
	printf("World generated !\n");
}