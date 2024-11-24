/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:51:10 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 15:47:01 by secros           ###   ########.fr       */
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

void	lstadd_front(t_pos **shoot, t_pos *new_bull)
{
	if (!shoot)
		*shoot = new_bull;
	else
	{
		new_bull->next = *shoot;
		*shoot = new_bull;
	}
}
