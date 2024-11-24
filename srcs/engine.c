/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:35:51 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 04:33:22 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void init_engine(void)
{

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    timeout(0); 
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
	gamedata.windows[MENU_WIN] = create_newwin(LINES / 5, COLS, LINES - LINES / 5, 0);
	gamedata.windows[ALERT_WIN] = create_newwin(LINES, COLS, 0, 0);
	gamedata.windows[GAME_WIN] = create_newwin(LINES - (LINES / 5), COLS, 0, 0);
	gamedata.windows[STAT_WIN] = create_newwin(LINES / 5, COLS, LINES - LINES / 5, 0);
    gamedata.context = MENU;
}


void engineloop(void)
{
    while (true)
    {
        if (check_for_resize())
        {
            switch (gamedata.context)
            {
                case MENU:
                    menuloop();
                    break;
                case GAME:
                	gameloop();
                	statloop();
                    break;
                case QUIT:
                	return;
            }
        }
        switch (getch())
        {
            case 'q':
                return ;
            case ESC_KEY:
                return ;
            default:
                break ;
        }
        napms(100);
    }
}

void destroy_engine(void)
{
    size_t i;

    i = 0;
    while (i < WIN_NB)
    {
        if (gamedata.windows[i])
            destroy_win(gamedata.windows[i]);
        i++;
    }
    endwin();
}

