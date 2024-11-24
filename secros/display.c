/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:47:18 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 18:54:11 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	display_shoot(WINDOW *win, t_bullet **shoot)
{
	t_bullet *bull = *shoot;
	t_bullet *prev = NULL;
	void *pt;

	while (bull)
	{
		mvwaddch(win, bull->pos.y, bull->pos.x++, 'o');
		if (bull->pos.x == getmaxx(win) - 2)
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

void	display_player(WINDOW *win, t_data *data)
{
	int i = 0;
	char *player[] = PLAYER_S;
	while (player[i])
		mvwaddstr(win, data->player.pos.y - 1 + i, data->player.pos.x - 1, player[i++]);
}

void	display_background(WINDOW *win, t_data *data)
{
	int patern = 0;
	static int back_size = 0;
	const char back[] = BACK;
	int x = 1;
	int line;

	if (!back_size)
		back_size = ft_strlen(BACK);
	data->back_off = (data->back_off +1) % back_size;
	while (x < data->window.sizex - 1)
	{
		patern = (data->back_off + x) % (back_size - 1);
		mvwaddch(win, data->window.sizey - 2, x, back[patern]);
		mvwaddch(win, 2, x, back[patern]);
		x++;
	}
}

void	display_win(WINDOW *win, t_data *data)
{
	werase(win);
	box(win, 0, 0);
	mvwprintw(win, 1, 1, "Score %d", data->score);
	display_background(win, data);
	display_player(win, data);
	display_shoot(win, &data->shoot);
	wrefresh(win);
}
