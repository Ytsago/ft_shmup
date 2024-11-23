/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:01:13 by secros            #+#    #+#             */
/*   Updated: 2024/11/23 20:12:32 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

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
