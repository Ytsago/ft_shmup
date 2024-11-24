/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:52:18 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 09:20:42 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include <stdbool.h>
# include "vector.h"

typedef enum e_type
{
	BULLET,
	ENEMY,
	PLAYER
}	t_type;

typedef struct s_entity
{
	t_vec		pos;
	t_type		type;
	bool		alive;
	char		*sprite;
	void		*class;
}	t_entity;

typedef struct s_enemy
{
	t_vec		mooveset;//garbage type for now
	int			life;
}	t_enemy;

typedef struct s_bullet
{
	t_vec		velocity;
	t_type		shooter;
}	t_bullet;

typedef struct s_player
{
	int			life;
}	t_player;

//void init_entity(t_entity *entity, int x, int y, t_entity_type type, bool alive);
//void cleanup_entity(t_entity *entity);

#endif
