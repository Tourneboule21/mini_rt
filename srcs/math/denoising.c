/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   denoising.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <lcrimet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:23:11 by lcrimet           #+#    #+#             */
/*   Updated: 2023/03/06 14:17:58 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	sort_tab(uint32_t *tab, int size)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 0;
	size--;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[j] > tab[j + 1])
			{
				r = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = r;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

static uint32_t	find_median(uint32_t *around)
{
	sort_tab(around, 9);
	return (around[4]);
}

void	median_denoise(uint32_t *image, int img_w, int img_h)
{
	uint32_t	*old_img;
	uint32_t	*around;
	int			i;
	int			j;

	old_img = malloc(sizeof(uint32_t) * (img_w * img_h));
	memcpy(old_img, image, sizeof(uint32_t) * (img_w * img_h));
	around = malloc(sizeof(uint32_t) * 9);
	i = 1;
	while (i < img_h - 1)
	{
		j = 1;
		while (j < img_w - 1)
		{
			around[0] = old_img[(j - 1) + (i - 1) * img_w];
			around[1] = old_img[(j - 1) + (i) * img_w];
			around[2] = old_img[(j - 1) + (i + 1) * img_w];
			around[3] = old_img[(j) + (i - 1) * img_w];
			around[4] = old_img[(j) + (i) * img_w];
			around[5] = old_img[(j) + (i + 1) * img_w];
			around[6] = old_img[(j + 1) + (i - 1) * img_w];
			around[7] = old_img[(j + 1) + (i) * img_w];
			around[8] = old_img[(j + 1) + (i + 1) * img_w];
			image[j + i * img_w] = find_median(around);
			j++;
		}
		i++;
	}
}