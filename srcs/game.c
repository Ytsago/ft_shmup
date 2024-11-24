/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:05:17 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 07:09:27 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	init_game(void)
{
	WINDOW	*win;

	win = enginectx.windows[GAME_WIN];
	getmaxyx(win, enginectx.game.lines, enginectx.game.cols);
	enginectx.game.lines -= 3;
	enginectx.game.scroller = 0;
}

void	resize_game(void)
{
	WINDOW	*win;

	win = enginectx.windows[GAME_WIN];
	wresize(win, LINES - (LINES / 5), COLS);
	mvwin(win, 0, 0);
	getmaxyx(win, enginectx.game.lines, enginectx.game.cols);
	enginectx.game.lines -=3;
	enginectx.game.cols -=2;
}

static void	draw_scroller(WINDOW *win)
{
	size_t	x;
	size_t	maxx;
	size_t	maxy;
	char	ch;

	x = 0;
	maxx = enginectx.game.cols;
	maxy = enginectx.game.lines;
	while (x < maxx)
	{
		enginectx.game.scroller++;
		enginectx.game.scroller %= SCROLL_LEN;
		ch = SCROLLER[enginectx.game.scroller];
		mvwaddch(win, maxy, x + 1, ch);
		mvwaddch(win, 2, x + 1, ch);
		x++;
	}
}

static void	draw_game(void)
{
	WINDOW	*win;

	win = enginectx.windows[GAME_WIN];
	werase(win);
	box(win, 0, 0);
	draw_scroller(win);
	printcenter(win, "i do be gamin'");
	wrefresh(win);
}

static void	handle_game_input(void)
{
	char	ch;

	ch = getch();
	if (ch == 'q')
		enginectx.context = QUIT;
}

static void	handle_game_logic(void)
{
	
}

void	gameloop(void)
{
	handle_game_input();
	handle_game_logic();
	draw_game();
}
