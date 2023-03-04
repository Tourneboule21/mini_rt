/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:11:04 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/04 14:49:42 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_vec3(t_vec3 *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_vec3	r_set_vec3(double x, double y, double z)
{
	t_vec3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

double	vec3_length(t_vec3 *vec)
{
	return (sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z)));
}

double	vec3_length_squared(t_vec3 *vec)
{
	return ((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
}

void	vec3_scale(t_vec3 *vec, double scale)
{
	vec->x *= scale;
	vec->y *= scale;
	vec->z *= scale;
}

void	add_vec3(t_vec3 *dest, t_vec3 *add)
{
	dest->x += add->x;
	dest->y += add->y;
	dest->z += add->z;
}

void	substract_vec3(t_vec3 *dest, t_vec3 *sub)
{
	dest->x -= sub->x;
	dest->y -= sub->y;
	dest->z -= sub->z;
}

void	reverse_vec3(t_vec3 *vec)
{
	vec->x = -vec->x;
	vec->y = -vec->y;
	vec->z = -vec->z;
}

t_vec3	r_vec3_scale(t_vec3 vec, double scale)
{
	t_vec3	res;

	res.x = vec.x * scale;
	res.y = vec.y * scale;
	res.z = vec.z * scale;
	return (res);
}

t_vec3	r_add_vec3(t_vec3 dest, t_vec3 add)
{
	t_vec3	res;

	res.x = dest.x + add.x;
	res.y = dest.y + add.y;
	res.z = dest.z + add.z;
	return (res);
}

t_vec3	r_substract_vec3(t_vec3 dest, t_vec3 sub)
{
	t_vec3	res;

	res.x = dest.x - sub.x;
	res.y = dest.y - sub.y;
	res.z = dest.z - sub.z;
	return (res);
}

t_vec3	r_reverse_vec3(t_vec3 vec)
{
	t_vec3	res;

	res.x = -vec.x;
	res.y = -vec.y;
	res.z = -vec.z;
	return (res);
}

double	vec3_dot_product(t_vec3 *vec1, t_vec3 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

t_vec3	vec3_cross_product(t_vec3 *vec1, t_vec3 *vec2)
{
	t_vec3	res;

	res.x = vec1->y * vec2->z - vec1->z * vec2->y;
	res.y = vec1->z * vec2->x - vec1->x * vec2->z;
	res.z = vec1->x * vec2->y - vec1->y * vec2->x;
	return (res);
}

void	vec3_normalize(t_vec3 *vec)
{
	vec->x /= vec3_length(vec);
	vec->y /= vec3_length(vec);
	vec->z /= vec3_length(vec);
}

t_vec3	r_vec3_normalize(t_vec3 vec)
{
	t_vec3	res;

	res.x = vec.x / vec3_length(&vec);
	res.y = vec.y / vec3_length(&vec);
	res.z = vec.z / vec3_length(&vec);
	return (res);
}

uint8_t		vec3_equal(t_vec3 *vec1, t_vec3 *vec2)
{
	if (vec1->x == vec2->x && vec1->y == vec2->y && vec1->z == vec2->z)
		return (1);
	return (0);
}

t_vec3	random_vec3(void)
{
	return (r_set_vec3(random_double(), random_double(), random_double()));
}

t_vec3	random_vec3_limit(double min, double max)
{
	return (r_set_vec3(random_double_limit(min, max), random_double_limit(min, max), random_double_limit(min, max)));
}

void	print_vec3(t_vec3 *vec)
{
	printf("(%f, %f, %f)", vec->x, vec->y, vec->z);
}
