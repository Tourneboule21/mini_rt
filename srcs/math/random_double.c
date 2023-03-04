/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:56:11 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/04 13:57:47 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double	random_double_limit(double min, double max)
{
	return (min + (max - min) * random_double());
}