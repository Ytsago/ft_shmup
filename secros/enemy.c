/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 17:10:28 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 20:11:44 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

t_entity	*enemy_spawner(int y, int x, int class)
{
	t_entity	*enemy;

	enemy = malloc(sizeof(t_entity));
	if (!enemy)
		return(NULL);
	enemy->class = class;
	enemy->pos.x = x;
	enemy->pos.y = y;
	enemy->next = NULL;
	if(class == 1)
	{
		enemy->life = 1;
		enemy->wait_time = 5;
	}
	if(class == 2)
	{
		enemy->wait_time = 8;
		enemy->life = 12;
	}
	if(class == 3)
	{
		enemy->wait_time = 5;
		enemy->life = 8;
	}
	return (enemy); 
}

void	*first_wave(t_data *data, int wait)
{
	size_t	i = 0;
	void *pt = NULL;

	while (i < 6 && wait == 50)
	{
		lstadd_front_enti(&data->enemy, enemy_spawner(7 + i, data->window.sizex - 2, 1));
		lstadd_front_enti(&data->enemy, enemy_spawner(20 + i, data->window.sizex - 2, 1));
		lstadd_front_enti(&data->enemy, enemy_spawner(33 + i, data->window.sizex - 2, 1));
		i += 2;
	}
	wait++;
	while (i < 2 && wait == 100)
	{
		lstadd_front_enti(&data->enemy, enemy_spawner(11 + i, data->window.sizex - 2, 3));
		lstadd_front_enti(&data->enemy, enemy_spawner(31 + i, data->window.sizex - 2, 3));
		i++;
	}
	while (i < 2 && wait == 130)
	{
		lstadd_front_enti(&data->enemy, enemy_spawner(7 + i, data->window.sizex - 2, 2));
		lstadd_front_enti(&data->enemy, enemy_spawner(20 + i, data->window.sizex - 2, 2));
		lstadd_front_enti(&data->enemy, enemy_spawner(33 + i, data->window.sizex - 2 , 2));
		i++;
	}
	return (pt);
}
