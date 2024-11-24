/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:51:10 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 21:08:15 by secros           ###   ########.fr       */
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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
		*lst = NULL;
	}
}
