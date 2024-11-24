/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_data.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:09:54 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 08:35:54 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_DATA_H
# define GAME_DATA_H
# include "libft.h"

typedef struct s_gamedata
{
	int	scroller;
	int	lines;
	int	cols;
	t_list	*entities;
}	t_gamedata;

#endif
