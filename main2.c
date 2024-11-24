/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: secros <secros@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:01:13 by secros            #+#    #+#             */
/*   Updated: 2024/11/24 16:20:17 by secros           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.h"

void	shooting(t_data *data, int me)
{
	t_pos *bullet = malloc(sizeof(t_pos));
	static int flipflop = -1;
	if (!bullet)
		return;
	if (me)
	{
		bullet->x = data->player.x + 5;
		bullet->y = data->player.y + flipflop;
		lstadd_front(&data->shoot, bullet);
		flipflop *= -1;
	}
}

int	user_input(t_data *data)
{
	int	input;
	input = getch();
	if (input == 'w' && data->player.y > 3)
		data->player.y--;
	if (input == 's'&& data->player.y < data->window.sizey - 3)
		data->player.y++;
	if (input == 'd'&& data->player.x < 20)
		data->player.x++;
	if (input == 'a'&& data->player.x > 2)
		data->player.x--;
	if (input == ' ')
		shooting(data, 1);
	if (input == 27)
		return (1);
	return (0);
}		

void	engine(t_data *data, WINDOW *win)
{
	while (1)
	{
		if(user_input(data))
			break;
		display_win(win, data);
		napms(25);
	}
}

void	data_init(WINDOW **win, t_data *data)
{
	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	keypad(stdscr, true);
	timeout(1);

	*win = newwin(40, 100, 5, 10);

	data->player.x = 5;
	data->player.y = 10;
	data->player.next = NULL;

	data->window.sizex = getmaxx(*win);
	data->window.sizey = getmaxy(*win);

	data->score = 0;
	data->back_off = 0;
	data->shoot = NULL;
}

int main()
{
	t_data	data;
	WINDOW *game_win;
	data_init(&game_win, &data);
	engine(&data, game_win);
	endwin();
}
