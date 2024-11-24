/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 03:05:17 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 06:23:35 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void	init_game(void)
{

}

void	resize_game(void)
{
	WINDOW	*win;

	win = enginectx.windows[GAME_WIN];
	wresize(win, LINES - (LINES / 5), COLS);
	mvwin(win, 0, 0);
}

static void	draw_game(void)
{
	WINDOW	*win;

	win = enginectx.windows[GAME_WIN];
	werase(win);
	box(win, 0, 0);
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
