/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 05:20:39 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 12:09:58 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

static t_entity	new_entity(t_vec pos, t_type type, char *sprite, void *class)
{
	t_entity	entity;

	entity.pos = pos;
	entity.type = type;
	entity.sprite = sprite;
	entity.alive = true;
	entity.class = class;
	return (entity);
}

/*
	Add an entity to the chained list
*/
static void	add_entity(t_entity entity)
{
	t_list	*lst;

	lst = ft_lstnew(&entity);
	if (!lst)
	{}// CREATE A PANIC FUNCTION TO FREE EVERYTHING AND QUIT SAFELY
	ft_lstadd_back(&enginectx.game.entities, lst);
}

/*
 * COMMENTAIRE FR A REMOVE!!!!!!!!!!!!!!!!!!!!!!
	Function qui rajoute un enemi, faudrait que en arg il prends le lvl/le type d'enemy pour
	determiner ici avec une condition, sa facon de se deplacer, sa vie, son sprite etc
*/
void	add_enemy(t_vec pos)
{
	t_entity	entity;
	t_enemy		enemy = {new_vec(0, 0), 100};
	entity = new_entity(pos, ENEMY, "%", (void *)&enemy);
	add_entity(entity);
}

void	add_bullet(t_vec pos, t_vec vel, t_type shooter)
{
	t_entity	entity;
	t_bullet	bullet = {vel, shooter};
	entity = new_entity(pos, BULLET, ".", (void *)&bullet);
	add_entity(entity);
}

void	add_player(t_vec pos, t_entity **play1)
{
	t_player	player = {1000};
	**play1 = new_entity(pos, PLAYER, ">", (void *)&player);
//	add_entity(entity);
}

bool	is_alive(t_entity *entity)
{
	return (entity->alive);
}

void	del(void *entity)
{
	entity = NULL;
}

/*
	Function that cleans dead entites
*/
void	cleanup(void)
{
	t_list	*lst;
	t_list	*last;
	t_list	*next;
	t_list	*tmp;

	lst = enginectx.game.entities;
	last = NULL;
	if (lst)
		next = lst->next;
	else
		next = NULL;
	tmp = NULL;
	while (lst)
	{
		if (!is_alive((t_entity *)lst->content))
		{
			tmp = lst;
			if (!last)
			{
				enginectx.game.entities = next;
				lst = lst->next;
			}
			else
			{
				last->next = next;
				lst = next;
			}
			ft_lstdelone(tmp, &del);
		}
		else
		{
			last = lst;
			lst = lst->next;
		}
		if (next)
			next = next->next;
	}
}
