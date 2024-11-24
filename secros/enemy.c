/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:10:28 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 18:49:48 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	*enemy_spawner(int x, int y, int class)
{
	
}

void	*first_wave(t_data *data)
{
	size_t	i = 0;
	static	unsigned int wait = 0;
	void *pt = 1;

	while (i < 3 && pt)
	{
		pt = lstadd_front_enti(data->enemy, enemy_spawner(7 + i, data->window.sizex - 2, 1));
		if (pt)
			pt = lstadd_front_enti(data->enemy, enemy_spawner(12 + i, data->window.sizex - 2, 1));
		i++;
	}
	wait++;
}