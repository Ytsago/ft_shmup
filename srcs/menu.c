/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:05:17 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 06:23:43 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	resize_menu(void)
{
	WINDOW	*win;

	win = enginectx.windows[MENU_WIN];
	wresize(win, LINES / 5, COLS);
	mvwin(win, (LINES - (LINES / 5)), 0);
}

static void	draw_menu(void)
{
	WINDOW	*win;

	win = enginectx.windows[MENU_WIN];
	werase(win);
	box(win, 0, 0);
	printcenter(win, "Press 'q' to quit.");
	wrefresh(win);
}

static void	handle_menu_input(void)
{
	char	ch;

	ch = getch();
	if (ch == 'd')
		enginectx.context = GAME;
	if (ch == 'q')
		enginectx.context = QUIT;
}

void	menuloop(void)
{
	handle_menu_input();
	//handle_menu_logic();
	draw_menu();
}
