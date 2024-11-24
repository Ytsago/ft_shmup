/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:35:51 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 05:47:01 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shmup.h"

void init_enginectx(void)
{

    initscr();
    cbreak();
    noecho();
    curs_set(false);
    timeout(0); 
    nodelay(stdscr, true);
    keypad(stdscr, true);
	enginectx.windows[MENU_WIN] = create_newwin(LINES / 5, COLS, LINES - LINES / 5, 0);
	enginectx.windows[ALERT_WIN] = create_newwin(LINES, COLS, 0, 0);
	enginectx.windows[GAME_WIN] = create_newwin(LINES - (LINES / 5), COLS, 0, 0);
	enginectx.windows[STAT_WIN] = create_newwin(LINES / 5, COLS, LINES - LINES / 5, 0);
    enginectx.context = MENU;
}


void engineloop(void)
{
    while (true)
    {
        if (check_for_resize())
        {
            switch (enginectx.context)
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
        if (enginectx.windows[i])
            destroy_win(enginectx.windows[i]);
        i++;
    }
    endwin();
}

