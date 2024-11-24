/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:54 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 12:05:59 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H
# include "libft.h"
# include "entity.h"

typedef struct s_gamedata
{
	int			scroller;
	int			lines;
	int			cols;
	t_list		*entities;
	t_entity	*player;
}	t_gamedata;

#endif
