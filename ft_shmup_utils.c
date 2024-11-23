/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:51:10 by secros            #+#    #+#             */
/*   Updated: 2024/11/23 20:12:11 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	lstadd_front(t_pos **shoot, t_pos *new_bull)
{
	if (!*shoot)
		*shoot = new_bull;
	else
	{
		new_bull->next = *shoot;
		*shoot = new_bull;
	}
}
