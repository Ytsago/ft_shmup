/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:35:51 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 09:26:45 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	init_enginectx(void)
{
	initscr();
	cbreak();
	noecho();
	curs_set(false);
	timeout(1);
	nodelay(stdscr, true);
	keypad(stdscr, true);
	enginectx.windows[MENU_WIN] = create_newwin(LINES / 5, COLS, LINES - LINES / 5, 0);
	enginectx.windows[ALERT_WIN] = create_newwin(LINES, COLS, 0, 0);
	enginectx.windows[GAME_WIN] = create_newwin(LINES - (LINES / 5), COLS, 0, 0);
	enginectx.windows[STAT_WIN] = create_newwin(LINES / 5, COLS, LINES - LINES / 5, 0);
	enginectx.context = MENU;
}

void	engineloop(void)
{
	char	ch;

	while (true)
	{
		if (check_for_resize())
		{
			if (enginectx.context == MENU)
				menuloop();
			if (enginectx.context == GAME)
			{
				gameloop();
				statloop();
			}
			if (enginectx.context == QUIT)
				return ;
		}
		ch = getch();
		if (ch == 'a' || ch == ESC_KEY)
			return ;
		napms(100);
	}
}

void	destroy_engine(void)
{
	size_t	i;

	i = 0;
	while (i < WIN_NB)
	{
		if (enginectx.windows[i])
			destroy_win(enginectx.windows[i]);
		i++;
	}
	endwin();
}
