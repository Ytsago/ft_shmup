/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:45:33 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 05:39:10 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void vector_set(t_vector *v, int x, int y)
{
    v->x = x;
    v->y = y;
}

t_vector	new_vec(int x, int y)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.set = vector_set;
	return (vec);
}
