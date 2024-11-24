/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:05:17 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 05:25:46 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	resize_stat(void)
{
	WINDOW	*win;

	win = enginectx.windows[STAT_WIN];
	wresize(win, LINES / 5, COLS);
	mvwin(win, (LINES - (LINES / 5)), 0);
}

static void	draw_stat(void)
{
	WINDOW	*win;

	win = enginectx.windows[STAT_WIN];
	wclear(win);
	box(win, 0, 0);
	printcenter(win, "hello i am a statistik");
	wrefresh(win);

	/*
	WINDOW	*win;

	destroy_win(gamedata.windows[MENU_WIN]);
	win = create_newwin(LINES / 5, COLS, LINES - (LINES / 5), 0);
	wclear(win);
	box(win, 0, 0);
	printcenter(win, "Press 'q' to quit.");
	wrefresh(win);
	gamedata.windows[MENU_WIN] = win;
	*/
}

void	statloop(void)
{
	//handle_menu_input();
	//handle_menu_logic();
	draw_stat();
}
