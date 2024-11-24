/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:10:28 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 17:32:02 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	*enemy_spawner(int x, int y, int class)
{
	
}

void	*first_wave(t_data *data)
{
	size_t	i = 15;

	while (i > 11)
	{
		lstadd_front_enti(enemy_spawner(5, data->window.sizey - 2, 1));
	}
}