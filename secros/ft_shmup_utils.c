/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:51:10 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 22:40:51 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

size_t	ft_strlen(const char *s)
{
	size_t	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	lstadd_front_enti(t_entity **enemy, t_entity *new_en)
{
	if (!*enemy)
		*enemy = new_en;
	else
	{
		new_en->next = *enemy;
		*enemy = new_en;
	}
}

void	lstadd_front(t_bullet **shoot, t_bullet *new_bull)
{
	if (!shoot)
		*shoot = new_bull;
	else
	{
		new_bull->next = *shoot;
		*shoot = new_bull;
	}
}

void	ft_entity_destroy(t_entity *enemy)
{
	t_entity	*tmp = enemy;

	while (tmp)
	{
		tmp = tmp->next;
		free(enemy);
		enemy = tmp;
	}
}

void	ft_bullet_destroy(t_bullet *shoot)
{
		t_bullet	*tmp = shoot;

	while (tmp)
	{
		tmp = tmp->next;
		free(shoot);
		shoot = tmp;
	}
}

void	ft_data_destroy(t_data *lst)
{
	if (lst->enemy)
		ft_entity_destroy(lst->enemy);
	if (lst->shoot)
		ft_bullet_destroy(lst->shoot);
}
