/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:05:17 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 12:06:53 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	*init_game(void)
{
	static bool	initialized = false;
	WINDOW		*win;
	t_entity	*p1;
	t_vec		start;

	start.set(&start, getmaxy(enginectx.windows[1]) / 2, 5);
	win = enginectx.windows[GAME_WIN];
	getmaxyx(win, enginectx.game.lines, enginectx.game.cols);
	enginectx.game.lines -= 3;
	enginectx.game.scroller = 0;
	initialized = true;
	p1 = malloc(sizeof(t_entity));
	add_player(start, &p1);
	return (p1);
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
	enginectx.game.scroller++;
	enginectx.game.scroller %= (SCROLL_LEN +1);
	while (x < maxx - 2)
	{
		ch = SCROLLER[(enginectx.game.scroller + x) % SCROLL_LEN];
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
	static bool	initialized = false;

	if (!initialized)	
	{
		enginectx.game.player =	init_game();
		initialized = TRUE;
	}
	handle_game_input();
	handle_game_logic();
	draw_game();
}
