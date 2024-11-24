/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:34:21 by jaubry--          #+#    #+#             */
/*   Updated: 2024/11/24 04:28:58 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void printcenter(WINDOW *win, char *str)
{
    char **split;
    int lines, cols;
    size_t len, i;

    getmaxyx(win, lines, cols);
    split = ft_split(str, '\n');
    len = split_len(split);
    i = 0;
    while (split[i])
    {
        mvwprintw(win, (lines / 2) + (i - len / 2),
                  (cols - strlen(split[i])) / 2, "%s", split[i]);
        i++;
    }
    free_split(split);
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{   
    WINDOW *win;

    win = newwin(height, width, starty, startx);
    box(win, 0, 0);
    wrefresh(win);
    return (win);
}

void destroy_win(WINDOW *win)
{   
    wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
    wrefresh(win);
    delwin(win);
}

bool check_terminal_size(void)
{
	WINDOW	*alert;

	alert = gamedata.windows[ALERT_WIN];
	wclear(alert);
    if (LINES < MIN_LINES || COLS < MIN_COLS)
    {
        box(alert, 0, 0);
        printcenter(alert, "Terminal size is too small!\nPlease resize the terminal to at least 40x80");
        wrefresh(alert);
        return (false);
    }
    wrefresh(alert);
    return (true);
}

void	resize_windows(void)
{
	resize_menu();
	resize_stat();
	resize_game();
}

/*
	Function that checks if the lines or cols has changed.
	Calls on 
*/
#include <stdio.h>
bool	check_for_resize(void)
{
	if ((gamedata.lines != LINES) || (gamedata.cols != COLS))
	{
		gamedata.lines = LINES;
		gamedata.cols = COLS;
		resize_windows();
	}
	return (check_terminal_size());
}
