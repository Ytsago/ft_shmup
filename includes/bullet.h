/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullet.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:59:38 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 18:35:06 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_H
# define BULLET_H

# include "vector.h"

typedef enum e_shooter
{
	ENEMY,
	PLAYER
}	t_shooter;

typedef struct s_bullet
{
	t_vec	pos;
	t_vec	velosity;
	t_shooter	shooter;
}	t_bullet;

#endif
