/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rverse_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrimet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:21:19 by lcrimet           #+#    #+#             */
/*   Updated: 2022/11/14 15:21:24 by lcrimet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

void	ft_rverse_str(char *str, int size)
{
	int	i;
	int	tmp;
	int	j;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}
