/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:01:13 by secros            #+#    #+#             */
/*   Updated: 2024/11/23 16:48:01 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ncurses.h>
#include <time.h>


typedef struct s_pos
{
	int				x;
	int				y;
	struct s_pos	*next;
} 					t_pos;

typedef struct s_data
{
	int		back_off;
	int		score;
	int		input;
	t_pos	*player;
	t_pos	*enemy;

} 			t_data;

void	display_player(WINDOW *win, t_data *data)
{
	char	*player = "-o>";
	int		pl_size = 3;
	int		i = 0;

	while(i < pl_size)
		mvwaddstr(win, data->player->y, data->player->x - 1, player);
}

void	display_win(WINDOW *win, const char back[23], t_data *data)
{
	int patern = 0;
	int x = 1;
	int line;
	
	werase(win);
	box(win, 0, 0);
	mvwprintw(win, 1, 1, "Score %d", data->score);
	while (x < 49)
	{
		patern = (data->back_off + x) % 22;
		mvwaddch(win, getmaxy(win) - 2, x, back[patern]);
		mvwaddch(win, 2, x, back[patern]);
		x++;
		display_player(win, data);
	}
	wrefresh(win);
}

int main()
{
	const char background[] = "*      .      +       ";
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, true);
	timeout(50);

	t_pos	player;
	player.x = 5;
	player.y = 10;
	player.next = NULL;

	t_data	data;
	data.score = 0;
	data.back_off = 0;
	data.player = &player;

	WINDOW *game_win = newwin(20, 50, 5, 10);
	box(game_win, 0, 0);
	while (1)
	{
		display_win(game_win, background, &data);
		data.back_off = (data.back_off +1) % 23;
		napms(80);
	}
	endwin();
}
