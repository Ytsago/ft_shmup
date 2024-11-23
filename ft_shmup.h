/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:47:29 by secros            #+#    #+#             */
/*   Updated: 2024/11/23 21:01:08 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHMUP_H
# define FT_SHMUP_H

#include <stdlib.h>
#include <ncurses.h>

typedef struct s_pos
{
	int				x;
	int				y;
	struct s_pos	*next;
} 					t_pos;

typedef struct s_data
{
	int		back_off;
	int		score;
	t_pos	*player;
	t_pos	*shoot;
	t_pos	*enemy;
} 			t_data;

void	display_shoot(WINDOW *win, t_pos **shoot);
void	display_win(WINDOW *win, const char back[23], t_data *data);
void	lstadd_front(t_pos **shoot, t_pos *new_bull);
void	data_init(t_data *data, t_pos *player);

#endif