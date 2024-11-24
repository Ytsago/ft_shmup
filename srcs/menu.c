/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:05:17 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 04:35:17 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	resize_menu(void)
{
	WINDOW	*win;

	win = gamedata.windows[MENU_WIN];
	wresize(win, LINES / 5, COLS);
	mvwin(win, (LINES - (LINES / 5)), 0);
}

static void	draw_menu(void)
{
	WINDOW	*win;

	win = gamedata.windows[MENU_WIN];
	wclear(win);
	box(win, 0, 0);
	printcenter(win, "Press 'q' to quit.");
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

static void	handle_menu_input(void)
{
	char	ch;

	ch = getch();
	if (ch == 'd')
		gamedata.context = GAME;
	if (ch == 'q')
		gamedata.context = QUIT;
}

void	menuloop(void)
{
	handle_menu_input();
	//handle_menu_logic();
	draw_menu();
}
