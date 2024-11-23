/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:01:13 by secros            #+#    #+#             */
/*   Updated: 2024/11/23 19:29:40 by secros           ###   ########.fr       */
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
	t_pos	*player;
	t_pos	*shoot;
} 			t_data;

void	display_shoot(WINDOW *win, t_pos **shoot)
{
	t_pos *bull = *shoot;
	t_pos *prev = NULL;
	t_pos *freeing;

	while (bull)
	{
		mvwaddch(win, bull->y, bull->x++, '-');
		if (bull->x == getmaxx(win) - 1)
		{
			freeing = bull;
			if (prev)
				prev->next = bull->next;
			else
				*shoot = bull->next;
			bull = bull->next;
			free(freeing);
		}
		else
		{
			prev = bull;
			bull = bull->next;
		}
	}
}

void	display_win(WINDOW *win, const char back[23], t_data *data)
{
	int patern = 0;
	int x = 1;
	int line;
	char player = '>';
	
	werase(win);
	box(win, 0, 0);
	mvwprintw(win, 1, 1, "Score %d", data->score);
	while (x < getmaxx(win) - 1)
	{
		patern = (data->back_off + x) % 22;
		mvwaddch(win, getmaxy(win) - 2, x, back[patern]);
		mvwaddch(win, 2, x, back[patern]);
		x++;
		mvwaddch(win, data->player->y, data->player->x - 1, player);
	}
	display_shoot(win, &data->shoot);
	wrefresh(win);
}

void	lstadd_front(t_pos **shoot, t_pos *new)
{
	if (!*shoot)
		*shoot = new;
	else
	{
		new->next = *shoot;
		*shoot = new;
	}
}

void	shooting(t_data *data, int me)
{
	t_pos *bullet = malloc(sizeof(t_pos));
	if (me)
	{
		bullet->x = data->player->x;
		bullet->y = data->player->y;
		lstadd_front(&data->shoot, bullet);
	}
}

int main()
{
	const char background[] = "*      .      +       ";
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, true);
	timeout(25);

	t_pos	player;
	player.x = 5;
	player.y = 10;
	player.next = NULL;

	t_data	data;
	data.score = 0;
	data.back_off = 0;
	data.player = &player;
	data.shoot = NULL;

	int	input;

	WINDOW *game_win = newwin(40, 100, 5, 10);
	box(game_win, 0, 0);
	while (1)
	{
		display_win(game_win, background, &data);
		data.back_off = (data.back_off +1) % 23;
		input = getch();
		if (input == 'w' && data.player->y > 3)
			data.player->y--;
		if (input == 's'&& data.player->y < getmaxy(game_win) - 3)
			data.player->y++;
		if (input == 'd'&& data.player->x < 15)
			data.player->x++;
		if (input == 'a'&& data.player->x > 2)
			data.player->x--;
		if (input == ' ')
		{
			shooting(&data, 1);
		}
		napms(2);
	}
	
	endwin();
}
