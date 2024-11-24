/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:05:17 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 06:03:28 by jaubry--         ###   ########.fr       */
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
}

void	statloop(void)
{
	//handle_menu_input();
	//handle_menu_logic();
	draw_stat();
}
