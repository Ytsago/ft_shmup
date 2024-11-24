/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:47:18 by secros            #+#    #+#             */
/*   Updated: 2024/11/23 21:02:51 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	display_shoot(WINDOW *win, t_pos **shoot)
{
	t_pos *bull = *shoot;
	t_pos *prev = NULL;
	void *pt;

	while (bull)
	{
		mvwaddch(win, bull->y, bull->x++, 'o');
		if (bull->x == getmaxx(win) - 2)
		{
			pt = bull;
			if (prev)
				prev->next = NULL;
			else
				*shoot = NULL;
			bull = NULL;
			free(pt);
		}
		else
		{
			prev = bull;
			bull = bull->next;
		}
	}
}

void	display_win(WINDOW *win, const char back[23], t_data *data)
{
	int patern = 0;
	int x = 1;
	int line;
	char player = '>';
	
	werase(win);
	box(win, 0, 0);
	mvwprintw(win, 1, 1, "Score %d", data->score);
	mvwaddch(win, data->player->y, data->player->x - 1, player);
	while (x < getmaxx(win) - 1)
	{
		patern = (data->back_off + x) % 22;
		mvwaddch(win, getmaxy(win) - 2, x, back[patern]);
		mvwaddch(win, 2, x, back[patern]);
		x++;
	}
	display_shoot(win, &data->shoot);
	wrefresh(win);
}