/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 14:05:06 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/03 18:56:29 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# define WIN_WIDTH 1920
# define ASPECT_RATIO 16.0 / 9.0

# include <math.h>
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include "mlx.h"
# include "mlx_keycodes.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ENTER_WIN = 7,
	EXIT_WIN = 8,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef struct s_camera
{
	double	viewport_h;
	double	viewport_w;
	double	focal_length;
	t_vec3	origin;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	low_left_corner;
}	t_camera;

typedef struct s_bgra
{
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;
	uint8_t	a;
}	t_bgra;

typedef union u_color
{
	int32_t		color;
	uint32_t	ucolor;
	t_bgra		tcolor;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	uint32_t	*renderer;
	int			win_w;
	int			win_h;
}	t_data;

void	set_vec3(t_vec3 *vec, double x, double y, double z);
double	vec3_length(t_vec3 *vec);
double	vec3_length_squared(t_vec3 *vec);
void	vec3_scale(t_vec3 *vec, double scale);
void	add_vec3(t_vec3 *dest, t_vec3 *add);
void	substract_vec3(t_vec3 *dest, t_vec3 *sub);
void	reverse_vec3(t_vec3 *vec);
t_vec3	r_vec3_scale(t_vec3 *vec, double scale);
t_vec3	r_add_vec3(t_vec3 *dest, t_vec3 *add);
t_vec3	r_substract_vec3(t_vec3 *dest, t_vec3 *sub);
t_vec3	r_reverse_vec3(t_vec3 *vec);
double	vec3_dot_product(t_vec3 *vec1, t_vec3 *vec2);
t_vec3	vec3_cross_product(t_vec3 *vec1, t_vec3 *vec2);
void	vec3_normalize(t_vec3 *vec);
t_vec3	r_vec3_normalize(t_vec3 *vec);
void	print_vec3(t_vec3 *vec);

void	init_ray(t_ray *ray, t_vec3 *origin, t_vec3 *dir);
t_vec3	pos_on_ray(t_ray *ray, double t);
t_vec3	ray_color(t_ray *ray);

int		init_mlx(t_data *data);

int		key_pressed(int keycode, t_data *data);
int		ft_close(void *param);

#endif